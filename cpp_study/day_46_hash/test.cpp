//
// Created by 20212 on 24-11-30.
//
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

void test_unordered_map_set()
{
    unordered_set<int> us;
    us.insert(4);
    us.insert(3);
    us.insert(1);
    us.insert(7);

    unordered_set<int>:: iterator it = us.begin();
    while (it != us.end())
    {
        cout << *it << " ";
        ++ it;
    }
    cout << endl;
}
int main()
{
    test_unordered_map_set();
    return 0;
}
// unordered map