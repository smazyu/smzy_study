#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// 检查字符是否在字符集 `noRepetiton` 中
bool CheckArray(bool noRepetiton[], char c) {
    return !noRepetiton[c - 'a'];
}

// 将字符添加到字符集 `noRepetiton` 中
void AddToArray(bool noRepetiton[], char c) {
    noRepetiton[c - 'a'] = true;
}

bool isUnique(char* astr) {
    int length = strlen(astr);
    bool noRepetiton[26] = {false}; // 用于记录字符出现情况，假设只处理小写字母

    for (int i = 0; i < length; i++) {
        char c = astr[i];
        if (CheckArray(noRepetiton, c)) {
            AddToArray(noRepetiton, c);
        } else {
            return false; // 字符重复
        }
    }
    return true; // 字符唯一
}