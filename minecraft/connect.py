import asyncio
import re
from mcrcon import MCRcon

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

# 创建一个空列表用于存储已经加入服务器的玩家名字
joined_players = []

async def send_message(name):
    global current_index
    rcon.connect()
    for _ in range(len(messages)):
        await asyncio.sleep(message_interval)
        rcon.command(f'tell {name} {messages[current_index]}')
        current_index = (current_index + 1) % len(messages)
    rcon.disconnect()

async def clear_items():
    rcon.connect()
    while True:
        rcon.command('kill @e[type=item]')
        rcon.disconnect()
        await asyncio.sleep(clear_interval)

async def monitor_players():
    global joined_players
    prev_player_count = 0
    while True:
        rcon.connect()
        status = rcon.command('list')
        #§6default§r: §4.GooierWord16718§r§f, qs_Bu_Jue§f
        match_names = re.findall(r'§6default§r: (.*)', status)
        if match_names:
            for name in match_names:
                clean_name = re.sub(r'§.', '', name)
                name_list = clean_name.split(',')
                for player in name_list:
                    if player not in joined_players:
                        joined_players.append(player)
                        await send_message(player)
        match_numbers = re.findall(r'\d+', status)
        current_player_count = int(match_numbers[1]) if match_numbers else 0
        rcon.disconnect()
        if current_player_count != prev_player_count:
            if current_player_count > prev_player_count:
                # await send_message()
                pass
            elif current_player_count < prev_player_count:
                for player in joined_players:
                    if player not in match_names:
                        joined_players.remove(player)
                        print(f'玩家 {player} 退出服务器')
        
        # 如果玩家数量变化了，才打印
        if current_player_count != prev_player_count:
            print(f'当前在线玩家数：{current_player_count}')
            print(f'已加入玩家列表：{joined_players}')

        prev_player_count = current_player_count
        await asyncio.sleep(3)

async def main():
    await asyncio.gather(
        clear_items(),
        monitor_players()
    )

asyncio.run(main())
