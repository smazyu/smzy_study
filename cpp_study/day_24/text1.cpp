//
// Created by 20212 on 24-9-26.
//
//编码的本质是映射
#include <iostream>
#include <string>
using namespace std;

void test_string() {
    string s1("string.cpp.zip");
    string s2("string.c");
    string s3("string.txt");

    size_t pos1 = s1.rfind('.');
    if (pos1 != string::npos) {
        cout << s1.substr(pos1) << endl;
    }

    size_t pos2 = s2.find('.');
    if (pos2 != string::npos) {
        cout << s2.substr(pos2) << endl;
    }

    size_t pos3 = s3.find('.');
    if (pos3 != string::npos) {
        cout << s3.substr(pos3) << endl;
    }

    string url("https://blog.simazhangyu.com/");
    size_t i1 = url.find(':');
    if (i1 != string::npos) {
        cout << url.substr(0, i1) << endl;
    }
    size_t i2 = url.find('/', i1 + 3);
    if (i2 != string::npos) {
        cout << url.substr(i1 + 3, i2 - i1 - 3) << endl;
    }
    cout << url.substr(i2 + 1) << endl;
}

int main() {
    test_string();
}
