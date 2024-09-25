//
// Created by 20212 on 24-9-25.
//
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

void test_string() {
    string s1("hello world");
    s1 += ' ';
    s1 += "world";
    cout << s1 << endl;

    for (size_t i = 0; i < s1.size(); i++) {
        cout << s1[i] << " ";
    }
    cout << endl;
    string::iterator it1 = s1.begin();
    while (it1 != s1.end()) {
        cout << *it1 << " ";
        ++it1;
    }
    cout << endl;

    for (auto ch: s1) {
        cout << ch << " ";
    }
    cout << endl;
    //返回c形式的str
    //返回的是指针

    //获取字符数组首地址，用c字符串形式遍历
    const char *str = s1.c_str();
    printf("%s \n", str);
    while (*str) {
        cout << *str << " ";
        ++str;
    }
    cout << endl;

    cout << s1 << endl; //调用string重载的operator <<
    cout << s1.c_str() << endl; //直接输出const char*
    cout << "-------" << endl;

}

int main() {
    test_string();
}
