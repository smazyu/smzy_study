//
// Created by 20212 on 24-10-28.
//
#include <iostream>
using namespace std;
//包含纯虚函数的类 抽象类 抽象类不能实例化出对象
// class Car
// {
// public:
//     virtual void Drive() = 0;//纯虚函数 不需要实现
// };
// class Benz:public Car
// {
// public:
//
// };
// int main()
// {
//     return 0;
// }
//纯虚函数强制重写
//动态绑定 -> 多态
//内联函数没有地址 所以内联函数不能是虚函数

//这里常考一道笔试题:sizeof(base)是多少
// class Base
// {
// public:
//     virtual void Func1()
//     {
//         cout << "Func1()" << endl;
//     }
//     //函数编译成指令放在了代码段
// private:
//     int _b = 1;
// };
// int main()
// {
//     cout << sizeof(Base) << endl;
//     // cout << sizeof(int) << endl;
// //Base内有 虚表指针 和 int
//     //虚函数表其实就是一个指针数组(虚函数指针)
//     return 0;
// }
class Person
{
public:
    virtual void BuyTicket()
    {
        cout << "买票-全价"<< endl;
    }

};
class Student:public Person
{
public:
    virtual void BuyTicket() override
    {
        cout << "买票-半价" << endl;
    }
};

void Func(Person &p)
{
    p.BuyTicket();
}
int main()
{
    Person Mike;
    Func (Mike);
}