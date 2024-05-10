'''
泰波那契序列 Tn 定义如下：

T0 = 0, T1 = 1, T2 = 1, 且在 n >= 0 的条件下 Tn+3 = Tn + Tn+1 + Tn+2

给你整数 n，请返回第 n 个泰波那契数 Tn 的值。



示例 1：

输入：n = 4
输出：4
解释：
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4
示例 2：

输入：n = 25
输出：1389537
'''


class Solution:
    def tribonacci(self, n: int) -> int:
        num = [None for _ in range(n+1)]
        if n < 2:
            return n
        if n >= 2:
            num[2] = 1
            if n >= 3:
                num[0] = 0
                num[1] = 1
                num[2] = 1
                for i in range(3,n+1):
                    num[i] = num[i-3] + num[i-2] + num[i-1]
            return num[n]
num = Solution().tribonacci(2)
print(num)