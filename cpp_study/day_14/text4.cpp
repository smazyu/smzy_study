//
// Created by 20212 on 12/9/2024.
//
#include <iostream>

using namespace std;

class Data {
public:
    Data(int year) : _year(year) {}

private:
    int _year;
    int _month;
    int _day;
};

int main() {
    Data d1(1);
    Data d2 = 2;//隐式类型的转换，构造出tmp(2),再用tmp拷贝构造d2(tmp) 最后编译器优化成直接构造
    Data d3 = d1;

    int i = 1;
    const double& d = i;//隐式类型转换，会产生中间的临时变量  引用的中间的临时变量， 类型为const

    //临时对象具有常性
}