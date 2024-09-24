//
// Created by 20212 on 24-9-24.
//
#include <iostream>
#include <string>
using namespace std;

//1. 4个默认成员函数
void test_string1() {
    string s1;
    string s2("hello");
    string s3("hello", 3);
    string s4(s2);
    string s5(s2, 1, 2);
    string s6(10, 'a');
    string s7(s2, 1);
    // string s5()
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s4 << endl;
    cout << s5 << endl;
    cout << s6 << endl;
    cout << s7 << endl;
}

//npos -> static const size_t npos = -1;无符号整型没有负数，这里的意思是整型的最大值

void test_string2() {
    string name("John");
    name += "K.";
    cout << name << endl;
    //[] + 下标遍历
    //写
    for (size_t i = 0; i < name.size(); ++i) {
        name[i] += 1;
    }
    //读
    for (size_t i = 0; i < name.size(); ++i) {
        cout << name[i] << " ";
    }
    cout << endl;

    //迭代器
    string::iterator it = name.begin();
    while (it != name.end()) {
        //这里的end是最后一个字符的下一个位置
        *it -= 1;
        ++it;
    }
    it = name.begin(); //使用的还是迭代器变量,就没有重复定义
    while (it != name.end()) {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
    //范围for 基于范围自动遍历
    //原理是迭代器 原理是被替换成迭代器 在c++11中受支持
    for (auto ch: name) {
        cout << ch << " ";
    }
    cout << endl;
}

//迭代器就像指针一样
//1.迭代器不一定是指针，只是像指针一样的东西
int main() {
    // test_string1();
    test_string2();
    return 0;
}
