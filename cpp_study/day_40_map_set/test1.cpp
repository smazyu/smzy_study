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
}

int main()
{
    test_set1();
}