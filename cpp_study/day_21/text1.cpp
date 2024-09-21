//
// Created by 20212 on 21/9/2024.
//
#include <iostream>

using namespace std;

class A {
public:
    A() {
        cout << "A()" << endl;
    }

    ~A() {
        cout << "~A()" << endl;
    }

private:
    int _a;
};

int main() {
    A *p1 = (A *) malloc(sizeof(A));
    A *p2 = new A;
    A *p3 = (A *) operator new(sizeof(A));

    //operator new和malloc的区别是什么
    void* p4 = malloc()
    return 0;
}