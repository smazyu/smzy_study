import toml
from mcrcon import MCRcon

def load_settings(filename):
    with open(filename, 'r') as file:
        settings = toml.load(file)
        print(settings)
    return settings

def connect_to_server(settings):
    host = settings['server']['host']
    port = settings['server']['port']
    password = settings['server']['password']
    return MCRcon(host, password, port)

# 使用示例
settings = load_settings('new_smzy_study\minecraft\setting.toml')
rcon = connect_to_server(settings)
