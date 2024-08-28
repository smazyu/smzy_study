//
// Created by 20212 on 29/8/2024.
//
#include <iostream>
using namespace std;
int main(){
    int a = 0;
    auto b = a;//b的类型是根据a的类型推导出是a
    int& c = a;
    auto &d = a;
    auto *e = &a;
    auto f = &a;
    cout << typeid(a).name() << endl;
    cout << typeid(b).name() << endl;
    cout << typeid(c).name() << endl;
    cout << typeid(d).name() << endl;
    cout << typeid(e).name() << endl;
}