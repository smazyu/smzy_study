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

int main(){
    Date d1(1,2,3);
//    Date d2 = 1;
//    Date d3 = {1,2};
    Date d4 = {1,2,3}; //隐式类型转换 c++11支持
    //如果不希望隐式类型转换 构造函数前面加explicit
    //explicit会禁止单参数的隐式转换
}
//定义开空间，声明承诺
//必须在初始化列表初始化 1.const成员变量 2.引用成员变量 3.没有默认构造函数的自定义成员变量

//成员变量在初始化列表初始化的顺序是声明的顺序，不是定义的顺序
//实际中，建议声明和定义的顺序写成一样的，这样不容易出错

//静态成员变量只能在外面初始化

//static成员
//1.static成员变量不存在对象中，存在静态区，属于这个类的所有对象，也是属于这个类
//2.static成员函数没有this指针，可以不使用对象就调用 -> 类名 ::func（）