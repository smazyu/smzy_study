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
}

int main() {
    // test_string1();
    test_string2();
    return 0;
}
