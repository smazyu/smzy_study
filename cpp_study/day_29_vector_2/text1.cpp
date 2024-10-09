//
// Created by admin on 24-10-9.
//
// #include <iostream>
// #include <string>
// using namespace std;
// string aa = "aaaa";
// int main() {
//
// }
#include <iostream>
#include <vector>
using namespace std;
//迭代器失效
void test_vector() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    vector<int>::iterator it = v.begin();
    //
    // v.push_back(5);
    // v.push_back(6);
    // v.push_back(7);
    //it指向增容前的地址 增容导致失效

    //push_back insert resize reserve等可能会扩容的接口都会导致迭代器失效
    while (it != v.end()) {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
}

int main() {
    test_vector();
}
