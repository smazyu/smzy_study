'''给你一个字符串数组 names ，和一个由 互不相同 的正整数组成的数组 heights 。两个数组的长度均为 n 。

对于每个下标 i，names[i] 和 heights[i] 表示第 i 个人的名字和身高。

请按身高 降序 顺序返回对应的名字数组 names 。'''
from typing import List


def sortPeople( names: List[str], heights: List[int]) -> List[str]:
    new_dic = dict(zip(heights, names))
    n = len(heights)
    sorted = False
    while not sorted:
        sorted = True
        for index in range(n - 1):
            if heights[index] < heights[index + 1]:
                heights[index], heights[index + 1] = heights[index + 1], heights[index]
                sorted = False
        return [new_dic[i] for i in heights]

sortPeople(names = ["Mary","John","Emma"], heights = [180,165,170])