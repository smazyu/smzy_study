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
//     void f1(){
//            f2()突破类域加访问限定符就可以访问，类里面是一个整体都在这类域中，
//            类里面不受访问限定符限制
//     }
    // static void f2(){
    //     f1();//无法调用
    // }
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
    cout <<sizeof(long) << endl; //4个字节
    cout << sizeof(long long) << endl; //8个字节
}
//定义开空间，声明承诺
//必须在初始化列表初始化 1.const成员变量 2.引用成员变量 3.没有默认构造函数的自定义成员变量

//成员变量在初始化列表初始化的顺序是声明的顺序，不是定义的顺序
//实际中，建议声明和定义的顺序写成一样的，这样不容易出错

//静态成员变量只能在外面初始化

//static成员
//1.static成员变量不存在对象中，存在静态区，属于这个类的所有对象，也是属于这个类
//2.static成员函数没有this指针，可以不使用对象就调用 -> 类名 ::func（）

//static成员函数中，不能访问非静态的成员(成员变量 + 成员函数)
//非静态可以访问静态，静态不可以访问非静态
//类域是包裹类里面的成员
//突破类域就是指访问类里面的成员
//突破类域访问限定的两种方式 编译可以知道到哪个类域找 + 访问限定符是否可以访问
//:: 域作用限定符
//d.f()
//sum a[n] 创建n个 调用n次构造函数
//静态成员和全局成员差不多，只是需要突破类域才能访问

//自定义类型都必须调用构造函数初始化