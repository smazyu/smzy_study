//
// Created by 20212 on 14/9/2024.
//
#include <iostream>
using namespace std;

//初始化列表
class Date{
public:
    Date(int year,int month,int day):_year(year),
    _month(month),_day(day)
    {
//成员变量的定义
    }
private:
    int _year;
    int _month;
    int _day;
    //成员变量的声明
};


//定义开空间，声明承诺
//必须在初始化列表初始化 1.const成员变量 2.引用成员变量 3.没有默认构造函数的自定义成员变量

//成员变量在初始化列表初始化的顺序是声明的顺序，不是定义的顺序
//实际中，建议声明和定义的顺序写成一样的，这样不容易出错