//
// Created by 20212 on 24-11-30.
//
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>
using namespace std;

void test_unordered_map_set()
{
    // unordered_set<int> us;

    set<int> s;
    s.insert(4);
    s.insert(3);
    s.insert(1);
    s.insert(7);

    // unordered_set<int>:: iterator it = us.begin();
    set<int>:: iterator it = s.begin();
    while (it != s.end())
    {
        cout << *it << " ";
        ++ it;
    }
    cout << endl;
    //unordered_set 无序 set 有序
    unordered_map<string,string> dict;
    dict.insert(make_pair("sort","排序"));
    dict["string"] = "字符串";
    dict.insert(make_pair("left","左边"));
    unordered_map<string,string>::iterator dit  = dict.begin();
    while (dit != dict.end())
    {
        cout << dit->first << " " << dit->second << endl;
        ++dit;
    }
    cout << "----------------" << endl;
}
int main()
{
    test_unordered_map_set();
    return 0;
}
// unordered map