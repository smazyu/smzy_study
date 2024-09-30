#include <iostream>
using namespace std;

namespace simulation {
    class string {
    public:
        /*string(): _str(new char[0]) {
            _str[0] = '\0';
        }

        string(char *str): _str(new char[strlen(str) + 1]) {
            strcpy(_str, str);
        };
*/
        //全缺省 "" 这里是\0
        string(char *str = ""): _str(new char[strlen(str) + 1]) {
            strcpy_s(_str, strlen(str) + 1, str);
        }

        ~string() {
            delete[] _str;
            _str = nullptr;
        }

        string operator=(const string &s) {
            char *tmp = new char[strlen(s._str) + 1];
            strcpy(tmp, s._str);
            delete[] _str;
            _str = tmp;
        }

        //string s2(s1) -> 深拷贝
        string(const string &s)
            : _str(new char[strlen(s._str) + 1]) {
            strcpy_s(_str, strlen(s._str) + 1, s._str);
        }

        size_t size() {
            return strlen(_str);
        }

        char &operator[](int i) {
            return _str[i];
        }

        const char *c_str() {
            return _str;
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

        for (size_t i = 0; i < s2.size(); i++) {
            s2[i] += 1;
            cout << s2[i] << " ";
        }
        cout << endl;
    }

    void test_string2() {
        string s1("hello");
        string s2(s1);
        //浅拷贝 s1 和 s2 指向了同一个指针地址
        //然后析构的时候
        //调用默认拷贝 即浅拷贝-值拷贝
        //同一个地址被析构了两次导致报错
        // cout << s1.c_str() << endl;
        // cout << s2.c_str() << endl;
    }
}

//常量，代码指令都在代码段
