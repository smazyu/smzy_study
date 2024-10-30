//
// Created by 20212 on 24-10-28.
//
/*
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。
示例 1：

输入：strs = ["flower","flow","flight"]
输出："fl"
示例 2：

输入：strs = ["dog","racecar","car"]
输出：""
解释：输入不存在公共前缀。*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // for std::min_element

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.empty()) return ""; // 处理空向量

        // 找到最短的字符串长度
        int minLength = std::min_element(strs.begin(), strs.end(),
                                          [](const std::string& a, const std::string& b) {
                                              return a.size() < b.size();
                                          })->size();

        for (int i = 0; i < minLength; i++) {
            char currentChar = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] != currentChar) {
                    return strs[0].substr(0, i); // 返回公共前缀
                }
            }
        }
        return strs[0].substr(0, minLength); // 返回完整的最短字符串
    }
}
int main() {
    Solution sol;
    std::vector<std::string> strs = {"flower", "flow", "flight"};
    std::cout << "Longest Common Prefix: " << sol.longestCommonPrefix(strs) << std::endl;
    return 0;
}
