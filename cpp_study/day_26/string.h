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

        // cout << s1.c_str() << endl;
        // cout << s2.c_str() << endl;
        
    }
}

//常量，代码指令都在代码段
