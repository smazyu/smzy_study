import asyncio
import aiohttp
from lxml import etree
import aiomysql

async def get_book_url(session):
    url = 'https://www.17k.com/top/'
    async with session.get(url) as response:
        content = await response.text()
    tree = etree.HTML(content)
    url_list = tree.xpath('/html/body/div[4]/div[2]/div[1]/div[5]/ul[3]/li/a[1]/@href')
    urls = []
    for index, value in enumerate(url_list):
        if index == len(url_list) - 1:
            continue
        url = f'https:{value}'
        urls.append(url)
    return urls

async def download(url, session, pool):
    async with session.get(url) as response:
        content = await response.text()
    tree = etree.HTML(content)
    brief = tree.xpath('//*[@id="bookInfo"]/dd/div[1]/p/a/text()')
    jianjie = ''.join(brief).strip().replace('"', '')

    async with pool.acquire() as conn:
        async with conn.cursor() as cursor:
            try:
                sql = 'INSERT INTO table_name VALUES (null, %s)'
                await cursor.execute(sql, (jianjie,))
                print(cursor.rowcount)
                await conn.commit()
            except:
                await conn.rollback()

async def main():
    pool = await aiomysql.create_pool(host='localhost', port=3306, user='root', password='123456', db='smzy')
    headers = {
        'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/100.0.4896.75 Safari/537.36'
    }
# aiohttp.ClientSession创造一个可复用的客户端
    async with aiohttp.ClientSession(headers=headers) as session:
        url_list = await get_book_url(session)

        tasks = []
        for url in url_list:
            task = asyncio.create_task(download(url, session, pool))
            tasks.append(task)

        await asyncio.gather(*tasks)

    pool.close()
    await pool.wait_closed()

if __name__ == '__main__':
    asyncio.run(main())