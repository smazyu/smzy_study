from typing import List
# l1 = [2,4,3]
# l1_new = []
# while l1:
#     l1_new.append(l1[-1])
#     l1.pop(-1)
def exchange(l1:List) -> List:
    l1_new = []
    while l1:
        l1_new.append(l1[-1])
        l1.pop(-1)
    return l1_new
def list_to_int(lst):
    # 将列表转换为整数
    result = 0
    for index, value in enumerate(reversed(lst)):
        result += value * (10 ** index)
    return result
l1 = [2,4,3]
l2 = [5, 6, 4]
l1 = exchange(l1)
l2 = exchange(l2)
num1 = list_to_int(l1)
num2 = list_to_int(l2)
total = num1 + num2
def int_to_list(n):
    # 将整数n的每一位数转换为列表
    return [int(digit) for digit in str(n)]
new_list = int_to_list(total)
new_list = exchange(new_list)
print(new_list)

