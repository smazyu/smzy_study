/*给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。*/

#include <iostream>
using namespace std;
#include <string.h>
#include <string>
#include <algorithm>

class Solution {
public:
    std::string addStrings(const std::string& num1, const std::string& num2) {
        int end1 = num1.size() - 1;
        int end2 = num2.size() - 1;
        int carry = 0;
        std::string retstr;

        // 使用 reserve 预先分配内存，以减少内存重新分配
        retstr.reserve(std::max(num1.size(), num2.size()) + 1);

        while (end1 >= 0 || end2 >= 0 || carry) {
            int val1 = (end1 >= 0) ? (num1[end1--] - '0') : 0;
            int val2 = (end2 >= 0) ? (num2[end2--] - '0') : 0;

            int sum = val1 + val2 + carry;
            carry = sum / 10;
            retstr.push_back(sum % 10 + '0');
        }

        // 反转字符串
        std::reverse(retstr.begin(), retstr.end());
        return retstr;
    }

    std::string multiply(const std::string& num1, const std::string& num2) {
        if (num1 == "0" || num2 == "0") return "0"; // 处理特殊情况

        std::string ret("0");

        // 逐位乘法
        for (int i = num2.size() - 1; i >= 0; --i) {
            int digit = num2[i] - '0';
            if (digit == 0) continue; // 如果当前位是0，跳过

            std::string temp = num1; // 备份 num1
            // 每次乘法后需要将 temp 左移（加上相应数量的0）
            for (int j = 0; j < (num2.size() - 1 - i); ++j) {
                temp.push_back('0'); // 模拟乘以 10
            }

            // 对 ret 和 temp 进行加法
            for (int j = 0; j < digit; ++j) {
                ret = addStrings(ret, temp);
            }
        }

        return ret;
    }
};