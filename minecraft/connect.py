from mcrcon import MCRcon
import asyncio
import re
host = '118.25.179.84'
port = 25575
password = 'mazyu602'
rcon = MCRcon(host, password, port)

clear_interval = 1800
message_interval = 2
current_index = 0
messages = [
    '欢迎来到服务器！',
    '请遵守服务器规则，享受游戏！',
    '如果您有任何问题，请联系管理员?',
]

async def send_message():
    global current_index
    current_index = 0;
    
    rcon.connect()
    rcon.command(f'say {messages[current_index]}')
    current_index = (current_index + 1) % len(messages)
    rcon.disconnect()

async def clear_items():
    while True:
        rcon.connect()
        rcon.command('kill @e[type=item]')
        rcon.disconnect()
        await asyncio.sleep(clear_interval)

async def monitor_players():
    prev_player_count = 0
    while True:
        rcon.connect()
        status = rcon.command('list')
        matches = re.findall(r'\d+', status)
        current_player_count = int(matches[1]) if matches else 0
        rcon.disconnect()
        if current_player_count > prev_player_count:
            await send_message()
        prev_player_count = current_player_count
        await asyncio.sleep(10)

async def main():
    await asyncio.gather(
        clear_items(),
        monitor_players()
    )

asyncio.run(main())
