/*
给定一个非负整数数组 nums，  nums 中一半整数是 奇数 ，一半整数是 偶数 。

对数组进行排序，以便当 nums[i] 为奇数时，i 也是 奇数 ；当 nums[i] 为偶数时， i 也是 偶数 。

你可以返回 任何满足上述条件的数组作为答案 。*/
#include <vector>
#include <iostream>
using namespace std;
vector<int> sortArrayByParityII(vector<int> &nums)
{
    vector<int> afterSortArray;
    vector<int> sortA;
    vector<int> sortB;
    // 将奇数偶数分别放到a和b中
    size_t total_nums = nums.size();
    for (auto it = nums.begin(); it != nums.end();)
    {
        if (*it % 2 == 0)
        {
            sortB.push_back(*it);
            it = nums.erase(it);
        }
        else
        {
            sortA.push_back(*it);
            it = nums.erase(it);
        }
        ++it;
    }
    // sorta 全是奇数 sortb 全是偶数
    afterSortArray.resize(total_nums);
    for (int i = 0; i < total_nums; i++)
    {
        if (i % 2 == 0)
        {
            afterSortArray[i] = sortB.back();
            sortB.pop_back();
        }
        else
        {
            afterSortArray[i] = sortA.back();
            sortA.pop_back();
        }
    }
    return afterSortArray;
}

// 优化解法
class Solution
{
public:
    vector<int> sortArrayByParityII(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        int i = 0;
        for (auto e : nums)
        {
            if (e % 2 == 0)
            {
                ans[i] = e;
                i += 2;
            }
        }
        int j = 1;
        for (auto e : nums)
        {
            if (e % 2 != 0)
            {
                ans[j] = e;
                j += 2;
            }
        }
        return ans;
    }
};