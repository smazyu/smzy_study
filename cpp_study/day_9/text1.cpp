//
// Created by 20212 on 1/9/2024.
//
#include <iostream>

using namespace std;

//栈分为栈顶和栈低
//class 新增加的关键词
//如何定义一个类
//封装
//1.将数据和方法定义到一起
//2.把想给你看到的数据给你看，不想给你看的封装起来。通过访问限定符来实现 分为共有私有和保护
class Stack {
    //1.成员函数

    //2.成员变量
public:
//    void Push(int x);
private:
    int *_a;
    int _size;
    int _capacity;//这里是声明
};

//c语言中struct是用来定义结构体的，在c++中兼容struct定义结构体的用法，但是同时可以用来定义类
struct ListNode {
    int _val;
    struct ListNode_C *_next;
    struct ListNode_C *_prev;
};
//C++中使用class和struct定义类的区别是什么 ->默认的访问限定符 ->class默认是私有的 ->struct 默认是共有的
struct ListNode_CPP {
    int _val;
    ListNode_CPP *_next;
    ListNode_CPP *_prev;
    //还可以定义函数 -> 成员函数
};

//声明和定义的区别是什么?声明可以认为是一种承诺,承诺要干嘛,但是还没有做,定义就是把这个事情落地了
int main() {
    //类实例化出对象,相当于定义出了类的成员变量
    //类实例出对象相当于拿着设计图去建房子
    Stack s1;
    Stack s2;
    Stack s3;
//    s1._a = nullptr;//报错,无法访问私有
    return 0;
}

