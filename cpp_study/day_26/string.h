#include <iostream>
using namespace std;

namespace simulation {
    class string {
    public:
        string(): _str(nullptr) {
        }

        string(char *str): _str(new char[strlen(str) + 1]) {
            strcpy(_str, str);
        };

        size_t size() {
            return strlen(_str);
        }

        char &operator[](int i) {
            return _str[i];
        }

        //堆的特点是 自由管理
    private
    :
        char *_str;
    };

    void test_string1() {
        string s1("hello");
        string s2;
        //c++的缺陷之一就是 它是一个历史包袱很多的语言
        // string对象存指针，指针指向的数组存储字符，字符里面有\0
        for (size_t i = 0; i < s1.size(); i++) {
            s1[i] += 1;
            cout << s1[i] << " ";
        }
        cout << endl;
    }
}

//常量，代码指令都在代码段
