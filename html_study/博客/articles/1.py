from bs4 import BeautifulSoup

# 读取HTML文件
with open('集线器.html', 'r', encoding='utf-8') as file:
    html_content = file.read()

# 使用Beautiful Soup解析HTML
soup = BeautifulSoup(html_content, 'html.parser')

# 找到所有包含特定类名的<h4>元素并删除
elements_to_remove = soup.find_all('h4', class_='wp-block-heading')
for element in elements_to_remove:
    element.extract()

# 将修改后的HTML写回文件
with open('网络协议.html', 'w', encoding='utf-8') as file:
    file.write(str(soup))
