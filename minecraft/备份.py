from mcrcon import MCRcon
import toml
import tkinter as tk
from tkinter import messagebox

# 从配置文件加载设置
def load_settings(filename):
    with open(filename, 'r') as file:
        settings = toml.load(file)
    return settings

# 连接到Minecraft服务器
def connect_to_server(settings):
    host = settings['server']['host']
    port = settings['server']['port']
    password = settings['server']['password']
    return MCRcon(host, password, port)

# 从文件加载玩家列表
def load_joined_players(filename):
    with open(filename, 'r', encoding='gbk') as file:
        joined_players = file.read().splitlines()
    return joined_players

# 更改玩家的游戏模式
def change_game_mode(rcon, mode, target_player):
    rcon.connect()
    rcon.command(f'gamemode {mode} {target_player}')
    rcon.disconnect()
    messagebox.showinfo("提示", "切换成功")

# 传送玩家到指定位置
def teleport_player(rcon, target_player, destination):
    rcon.connect()
    rcon.command(f'tp {target_player} {destination}')
    rcon.disconnect()
    messagebox.showinfo("提示", "传送成功")

# 创建Tkinter窗口
root = tk.Tk()
root.title("Minecraft 服务器管理")

# 加载设置并连接到服务器
settings = load_settings("new_smzy_study\\minecraft\\config.toml")
rcon = connect_to_server(settings)

# 从文件加载玩家列表
joined_players = load_joined_players("new_smzy_study\\minecraft\\joined_players.txt")

# 可用的游戏模式列表
game_modes = ['creative', 'survival', 'adventure', 'spectator']

# 界面元素
mode_label = tk.Label(root, text="游戏模式:")
mode_var = tk.StringVar(root)
mode_var.set(game_modes[0])
mode_menu = tk.OptionMenu(root, mode_var, *game_modes)

player_label = tk.Label(root, text="选择玩家:")
player_listbox = tk.Listbox(root, selectmode=tk.SINGLE, exportselection=0)
for player in joined_players:
    player_listbox.insert(tk.END, player)

destination_label = tk.Label(root, text="目标位置(x AlgorithmExercises z):")
destination_entry = tk.Entry(root)

# 使用选择的玩家更改游戏模式
def change_mode_with_player():
    selected_player = player_listbox.get(tk.ACTIVE)
    selected_mode = mode_var.get()
    change_game_mode(rcon, selected_mode, selected_player)

# 使用选择的玩家和目标传送玩家
def teleport_with_player():
    selected_player = player_listbox.get(tk.ACTIVE)
    destination = destination_entry.get()
    teleport_player(rcon, selected_player, destination)

# 动作按钮
change_mode_button = tk.Button(root, text="切换游戏模式", command=change_mode_with_player)
teleport_button = tk.Button(root, text="传送玩家", command=teleport_with_player)

# 界面布局
mode_label.grid(row=0, column=0)
mode_menu.grid(row=0, column=1)
player_label.grid(row=1, column=0)
player_listbox.grid(row=1, column=1, columnspan=4)
destination_label.grid(row=2, column=0)
destination_entry.grid(row=2, column=1, columnspan=3)
change_mode_button.grid(row=0, column=2)
teleport_button.grid(row=2, column=4)

# 运行主界面循环
root.mainloop()
