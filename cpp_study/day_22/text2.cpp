//
// Created by 20212 on 24-9-23.
//
//泛型编程：使用模板，编写跟类型无关的代码

//一些函数和类，针对不同类型需要写很多重复的代码
//函数：比如我们想实现交换int,double,char等等各种类型对象函数Swap
//类:比如我们想实现一个数据结构栈 stack
//1.函数模板
//template<class T>
//void swap(T &a, T &b);
//2.类模板
//template<class T>
//class stack {
//private:
//    T *_a;
//    size_t _size;
//    size_t _capacity;
//};
//编译器根据调用的函数模板和类模板的类型，实例化出对应的函数和类
//编译器会根据调用的类型，生成对应的函数
//模板不会被编译成对应的指令放在代码段