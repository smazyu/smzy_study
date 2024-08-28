//
// Created by 20212 on 28/8/2024.
//
//指针可以在任何时间指向任何实体
/*
int main(){
    char c1 = 10;
    char& c2 = c1;
    char* p1= &c1;

}*/
#include <iostream>
using namespace std;
int Add(int left,int right){
    return left + right;
}
inline void Swap(int&x1,int&x2){
    int tmp = x1;
    x1 = x2;
    x2 = tmp;
}//inline函数会在调用它的地方展开
//频繁调用Swap是有消耗的，调用函数需要建立栈帧
//如何解决:
//1.c语言中使用宏函数
//2.c++使用内联函数
int main(){
//    int ret = Add(1,2);
    int a = 0,b = 2;
    Swap(a,b);
    return 0;
}