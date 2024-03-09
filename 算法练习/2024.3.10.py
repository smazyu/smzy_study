'''给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。'''
from typing import List
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        num_dict = {}  # 创建一个空的哈希表（字典）
        for i in range(len(nums)):  # 遍历数组的每个索引
            num = nums[i]  # 获取当前索引下的元素值
            if (target - num) in num_dict:  # 检查target-num是否在哈希表中
                return [num_dict[target - num], i]  # 如果是，返回[target-num]的索引和当前索引
            else:
                num_dict[num] = i  # 否则，将当前元素及其索引加入哈希表
        return [-1, -1]  # 如果没有找到符合条件的元素对，返回[-1, -1]
