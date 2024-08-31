//
// Created by 20212 on 1/9/2024.
//

//实例化 -> 就是用自己定义出的类型定义出对象
//1.内置类型,基本类型 int/char/double
//2.自定义类型,class/struct
#include <iostream>

using namespace std;

class Data {
public:
    //编译器处理时会加一个隐含的this指针
    //void Print(Data* this)

    //this是谁调用这个成员函数就指向谁
    void Print() {
        cout << _year << "-" << _month << "-" << _day << endl;
    }

    //形参
    void Init(int year, int month, int day) {//void Init(this* this)
        this->_year = year;
        this->_month = month;
        this->_day = day;
    }

private:
    int _year;
    int _month;
    int _day;
};

int main() {
//    int i1;
//    int ii1;
    Data d1;
    //实参
    d1.Init(2024, 1, 9);//d1.Init(&d1);
    d1.Print();
    return 0;
}
//算类型的大小,实际上是算这个类型定义出对象的大小

//this指针是存在进程地址空间的哪个区域 this指针是存在栈上的 因为它是一个形参,函数参数都是函数栈帧的一部分(ps:vs下是在ecs这个寄存器来传递)