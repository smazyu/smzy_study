//
// Created by 20212 on 1/9/2024.
//
#include <iostream>
using namespace std;
//栈分为栈顶和栈低
//class 新增加的关键词
//封装
//1.将数据和方法定义到一起
//2.把想给你看到的数据给你看，不想给你看的封装起来。通过访问限定符来实现 分为共有私有和保护
class Stack{
    //1.成员函数

    //2.成员变量
public:
//    void Push(int x);
private:
    int *_a;
    int _size;
    int _capacity;
};
int main(){
    return 0;
}