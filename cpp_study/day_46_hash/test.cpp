//
// Created by 20212 on 24-11-30.
//
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>
#include <vector>
#include <time.h>
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
void test_op()
{
    unordered_set<int> us;
    set<int> s;

    const int n = 1000000000;
    vector<int> v;
    v.reserve(n);
    srand(time(0));
    for (size_t i = 0;i < n;i++)
    {
        v.push_back(rand());
    }
    size_t begin1 = clock();
    for (size_t i = 0;i < n;i++)
    {
        us.insert(v[i]);
    }
    size_t end1 = clock();
    // cout << end1 - begin1;
    cout<<"unordered_set:"<<end1 - begin1 << endl;

    size_t begin2 = clock();
    for (size_t i = 0;i < n;i++)
    {
        s.insert(v[i]);
    }
    size_t end2 = clock();
    // cout << end2 - begin2;
    cout<<"set:"<<end2 - begin2 << endl;
}
int main()
{
    // test_unordered_map_set();
    test_op();
    return 0;

}
//map/set 和 unordered_map/unordered_set 有什么区别和联系
//1.他都可以实现key和value的搜索场景，并且功能和使用基本一样
//2.map/set的底层是使用红黑树实现的，遍历出来是有序的，增删查改的时间复杂度是O(logN)
//3.unordered_map/unordered_set的底层是使用哈希表实现的，增删查改的时间复杂度是O(1)
//4.map和set是双向迭代器,unordered_map和unordered_set是单向迭代器