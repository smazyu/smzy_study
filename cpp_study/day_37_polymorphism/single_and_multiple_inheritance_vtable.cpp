//
// Created by 20212 on 24-10-28.
//
using namespace std;
#include <iostream>

class Base
{
public:
    virtual void Func1()
    {
        cout << "Base::Func1()" << endl;
    }

    virtual void Func2()
    {
        cout << " Base::Func2()" << endl;
    }

private:
    int a;

private:
    int _b = 1;
};

class Derive : public Base
{
public:
    virtual void Func1() override
    {
        cout << "Derive::Func1()" << endl;
    }

    virtual void Func3()
    {
        cout << "Derive::Func3()" << endl;
    }

    virtual void Func4()
    {
        cout << "Derive::Func4()" << endl;
    }

private:
    int b = 2;
};
int main()
{
    return 0;
}