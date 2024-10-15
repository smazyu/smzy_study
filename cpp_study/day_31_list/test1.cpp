#include <iostream>
// Created by 20212 on 24-10-15.
//
#include <list>

using namespace std;

void print_list(const list<int>& l)
{
    list<int>::const_iterator it = l.begin();
    for (; it != l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test_list()
{
    list<int> lit1;
    lit1.push_back(1);
    lit1.push_back(2);
    lit1.push_back(3);
    lit1.push_back(4);
    lit1.push_back(5);
    lit1.push_back(6);
    list<int>::iterator it1 = lit1.begin();
    while (it1 != lit1.end())
    {
        cout << *it1 << " ";
        ++it1;
    }
    cout << endl;
    print_list(lit1);

    list<int> lt2;
    lt2.push_back(1);
    lt2.push_back(2);
    lt2.push_back(3);
    lt2.push_back(4);
    for (auto e : lt2)
    {
        cout << e << " ";
    }
    cout << endl;

    //reverse 逆置
    //reserve 保留

    list<int>::reverse_iterator rit2 = lt2.rbegin();
    while(rit2 != lt2.rend())
    {
        cout << *rit2 << " ";
        ++rit2;
    }
    cout << endl;
}

void test_list2()
{
    list<int> lit1;
    lit1.push_back(1);
    lit1.push_back(2);
    lit1.push_back(3);
    lit1.push_back(4);
    lit1.push_back(0);
    lit1.push_front(-1);
    print_list(lit1);
    lit1.pop_front();
    lit1.pop_back();
}
//迭代器从使用性质分为三种 ：单向forword_list 双向list 随机vector
//从使用的场景分迭代器 ：正向迭代器 反向迭代器 + const迭代器

void test_list3()
{
    list<int> lit1;
    lit1.push_back(1);
    lit1.push_back(2);
    lit1.push_back(3);
    lit1.push_back(4);
    lit1.push_back(5);
    lit1.push_front(-1);
    print_list(lit1);
    lit1.pop_front();
    lit1.pop_back();
}
int main()
{
    test_list2();
    // test_list();
}
