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

//基础语法(如:函数重载)+类和对象+泛型编程：模板
//解决一些c语言解决得不好或者没有解决的问题。
//如果想同时定于两个栈 一个存int 一个存double 做不到
//template <class T> //T -> type t
#include <iostream>
#include <cassert>

using namespace std;

template<class T>
class vector {//动态增长的数组
public:
    vector() : _a(nullptr), _size(0), _capacity(0) {}

    ~vector() {
        delete[] _a;
        _a = nullptr;
        _size = _capacity = 0;
    }
    size_t size(){
        return _size;
    }
    void push_back(const T &x) ;

    //类里面声明，类外面定义
    void push_pop();


    T operator[](size_t i){
        assert(i <_size);
        return _a[i];
    }
private:
    T *_a;
    size_t _size;
    size_t _capacity;
};

template<class T>
void vector<T>::push_back(const T &x) {
    if(_size == _capacity){
        size_t newcapacity = _capacity == 0 ? 2: _capacity*2;
        T* tmp = new T[newcapacity];
        if(_a){
            memcpy(tmp,_a,sizeof(T)*_size);
            delete[] _a;
            _a = tmp;
        }
        _capacity = newcapacity;
    }
    _a[_size] = x;
    ++_size;
}