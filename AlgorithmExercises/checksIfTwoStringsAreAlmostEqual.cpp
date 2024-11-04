//
// Created by 20212 on 24-11-4.
//
/*
如果两个字符串 word1 和 word2 中从 'a' 到 'z' 每一个字母出现频率之差都 不超过 3 ，那么我们称这两个字符串 word1 和 word2 几乎相等 。
给你两个长度都为 n 的字符串 word1 和 word2 ，如果 word1 和 word2 几乎相等 ，请你返回 true ，否则返回 false 。
一个字母 x 的出现 频率 指的是它在字符串中出现的次数。
 */
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        int n = word1.size();
        for(int i = 0;i < n;i++)//这里前置++ 和后置++ 一样
            //0 n-1
        {
            if(word1[i] - word2[2] > 3)
                return false;
        }
        return true;
    }
};