'''
数组nums包含从0到n的所有整数，但其中缺了一个。请编写代码找出那个缺失的整数。你有办法在O(n)时间内完成吗？
'''
from typing import List
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        except_num = len(nums) * (len(nums) + 1) // 2
        actual_num = sum(nums)
        return except_num - actual_num
    
math = Solution()
num = math.missingNumber([1,3,0])
print(num)