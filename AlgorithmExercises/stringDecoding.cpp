#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    string decodeString(string s) {
        stack<string> strStack; // 存储字符串
        stack<int> numStack; // 存储数字
        string currentStr; // 当前构建的字符串
        int currentNum = 0; // 当前构建的数字

        for (char ch : s) {
            if (isdigit(ch)) {
                // 处理多位数字
                currentNum = currentNum * 10 + (ch - '0');
            } else if (ch == '[') {
                // 将当前数字和当前字符串入栈
                numStack.push(currentNum);
                strStack.push(currentStr);
                // 重置当前字符串和数字
                currentNum = 0;
                currentStr.clear();
            } else if (ch == ']') {
                // 处理闭括号
                string prevStr = strStack.top(); strStack.pop();
                int num = numStack.top(); numStack.pop();
                // 生成解码后的字符串
                for (int i = 0; i < num; i++) {
                    prevStr += currentStr;
                }
                currentStr = prevStr; // 更新当前字符串
            } else {
                // 构建当前字符串
                currentStr += ch;
            }
        }
        return currentStr; // 返回解码后的字符串
    }
};
