//
#include <iostream>
#include <set>
using namespace std;
void test_set1()
{
    set<int> s;
    s.insert(3);
    s.insert(1);
    s.insert(4);
    s.insert(3);
    s.insert(7);
    s.insert(8);
    // 排序＋去重
    set<int>::iterator it = s.begin();
    while (it != s.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    for (auto e : s)
    {
        cout << e << " ";
    }
    cout << endl;

    // set<int> copy(s);

    // for (auto e : copy)
    // {
    //     cout << e << " ";
    // }
    // cout << endl;
    // auto pos = s.find(3);
    set<int>::iterator pos = s.find(3);
    // 使用算法find和使用set内置find的区别
    s.erase(pos);
    for (auto e : s)
    {
        cout << e << " ";
    }
    cout << endl;
}
// erase 传值 底层就是由迭代器实现
// erase 传迭代器可以判断是否找到了这个值
int main()
{
    test_set1();
}