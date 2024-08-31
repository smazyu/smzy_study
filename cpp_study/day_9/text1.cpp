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
    int _capacity;
};

int main() {
    return 0;
}

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