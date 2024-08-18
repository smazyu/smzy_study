//
// Created by 20212 on 17/8/2024.
//
//函数重载 -> 一词多义
#include <iostream>
using namespace std;
//函数重载 一个函数有多个意义
//函数重载，函数名相同，参数不同
//对返回值没有要求
//只是返回值不同，没办法构成重载
void Func(int i, char ch) {
    cout << "Func(int, char) called: " << i << " " << ch << endl;
}
void Func(char ch, int i) {
    cout << "Func(char, int) called: " << ch << " " << i << endl;
}

int main() {
    Func(1, 'a');  // Corrected this line
    Func('b', 2);  // Example of using the second overload
}

//重载:
//1.什么是函数重载
//2.c++是如何支持函数重载的，为什么c语言不支持