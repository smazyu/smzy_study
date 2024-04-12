import re
a = '§6default§r: §4.GooierWord16718§r§f, qs_Bu_Jue§f'
match_names = re.findall(r'§r: §4(.*)', a)
for name in match_names:
    cleaned_names = re.sub(r'§.', '', name)
     
     
    print(cleaned_names)
