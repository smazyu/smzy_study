//
// Created by 20212 on 24-10-27.
//
//多态
//具体去完成某个行为，当不同的对象去完成时会产出不同的形态

//构成多态 必须通过基类的指针或者引用调用虚函数 被调用的函数
#include <iostream>
using namespace std;
class Person
{
public:
    virtual void BuyTicket()
    {
        cout << "买票全价"<< endl;
    }
private:
    int _a;
    char _ch;
};
int main()
{

}
//在成员函数前面加一个virtual的是虚函数

//1.满足多态的条件和对象有关，指向哪个对象就调用他的虚函数
//2.不满足多态的条件，跟对象的类型有关，调用的类型是谁，调用就是谁的