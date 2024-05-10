'''
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

'''
class Solution:
    def climbStairs(self, n: int) -> int:
        if n <= 1:
            return n
        methods = [None for _ in range(n + 1)]
        methods[0] = 1
        methods[1] = 1
        if n > 1:
            for i in range(2, n + 1):
                methods[i] = methods[i - 1] + methods[i - 2]
        return methods[n]

