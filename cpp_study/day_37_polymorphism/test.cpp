//
// Created by 20212 on 24-10-27.
//
//多态
//具体去完成某个行为，当不同的对象去完成时会产出不同的形态

//构成多态 必须通过基类的指针或者引用调用虚函数 被调用的函数
#include <iostream>
using namespace std;
// class Person
// {
// public:
//     virtual void BuyTicket()
//     {
//         cout << "买票全价"<< endl;
//     }
// private:
//     int _a;
//     char _ch;
// };
// int main()
// {
// //virtual关键字，可以修饰成原函数，为了完成虚函数的重写，满足多态的条件之一
//
// }
//在成员函数前面加一个virtual的是虚函数

//1.满足多态的条件和对象有关，指向哪个对象就调用他的虚函数
//2.不满足多态的条件，跟对象的类型有关，调用的类型是谁，调用就是谁的
//多态 -> 多种形态

//多态的两个条件
//1.虚函数的重写
//2.父类对象的指针或者引用去调用虚函数

//满足多态，跟指向对象有关,指向谁就调用谁

//虚函数的重写 参数 函数名 返回值都相同

//虚函数重写的两个例外
//1.协变 基类虚函数返回基类对象的指针或引用
//       派生类虚函数返回派生类对象的指针或引用
//2.重写的时候，派生类不加virtual关键字
class Person
{
public:
     virtual ~Person()
    //析构函数的函数名会被处理成destructor
    {
        cout <<"~Person"<<endl;
    }
};
class Student:public Person
{
public:
    virtual ~Student()
    //析构函数的函数名会被处理成destructor
    {
        cout << "~Student" <<endl;
    }
};
int main()
{
    Person * p1 = new Person;
    delete p1;
//重写是对函数体重写
    Person* p2 = new Student;
    delete p2;
    return 0;
}
//面试题 ：析构函数是否需要定义成虚函数?
//不构成多态：
//调用的指针类型是谁就调用谁的析构函数
//构成多态
//调用的指针指向谁就调用谁的析构函数