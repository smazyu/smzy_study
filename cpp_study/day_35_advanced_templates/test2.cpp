//
// Created by 20212 on 24-10-23.
//
#include <iostream>
#include <string.h>
using namespace std;
//模板的特化
template <class T>
bool IsEqual(T& left, T& right)
{
    return left == right;
}

//特化 （针对某些类型的特殊化处理）
template <>
bool IsEqual<char*>(char*& left, char*& right)
{
    return strcmp(left,right) == 0;
}
//特化 <>
int main()
{
    int a = 0, b = 1;
    cout << IsEqual(a, b) << endl;
    char* p1 = "hello";
    char* p2 = "world";
    cout << IsEqual(p1, p2) << endl;
    return 0;
}
