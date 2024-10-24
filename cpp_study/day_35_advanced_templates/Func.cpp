//
// Created by 20212 on 24-10-24.
//
#include "Func.h"
void F1()
{
    cout << " F1()" << endl;
}
template<class T>
void F2(const T&x)
{
    cout << "F2(const T& x)" << endl;
}
//解决模板不能分离编译的方法
//1.显示实例化 不常用，因为不方便
//2.不要分离编译了
template
void F2<int>(const int& x);

//模板复用了代码，节省资源，更快的迭代开放，c++的标准模板库因此而产生
//导致代码膨胀

//出错之后报错很凌乱
