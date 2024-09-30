#include <cassert>
#include <iostream>
using namespace std;

namespace simulation {
    class string {
    public:
        // 构造函数，默认参数为""，即\0
        string(const char *str = "") {
            _size = strlen(str);
            _capacity = _size;
            _str = new char[_capacity + 1];
            strcpy_s(_str, _capacity + 1, str); // 使用安全的strcpy_s
        }

        // 析构函数
        ~string() {
            delete[] _str;
            _str = nullptr;
            _size = _capacity = 0;
        }

        // 赋值运算符重载，确保深拷贝
        string &operator=(const string &s) {
            if (this != &s) {
                char *tmp = new char[strlen(s._str) + 1];
                strcpy_s(tmp, strlen(s._str) + 1, s._str); // 使用安全的strcpy_s
                delete[] _str;
                _str = tmp;
                _size = s._size;
                _capacity = s._capacity;
            }
            return *this;
        }

        // 拷贝构造函数，深拷贝
        string(const string &s) : _str(new char[strlen(s._str) + 1]) {
            strcpy_s(_str, strlen(s._str) + 1, s._str); // 使用安全的strcpy_s
            _size = s._size;
            _capacity = s._capacity;
        }

        // 返回字符串的长度
        size_t size() const {
            return _size;
        }

        // 返回字符串的容量
        size_t capacity() const {
            return _capacity;
        }

        // 下标运算符重载，非const版本
        char &operator[](size_t i) {
            assert(i < _size);
            return _str[i];
        }

        // 下标运算符重载，const版本
        const char &operator[](size_t i) const {
            assert(i < _size);
            return _str[i];
        }

        // 返回C风格字符串
        const char *c_str() const {
            return _str;
        }

    private:
        char *_str; // 字符串指针
        size_t _size; // 字符串长度
        size_t _capacity; // 容量，_capacity >= _size
    };

    // 输出运算符重载
    ostream &operator<<(ostream &out, const string &s) {
        for (size_t i = 0; i < s.size(); ++i) {
            out << s[i];
        }
        return out;
    }

    // 测试用例1：测试字符串的修改和访问
    void test_string1() {
        string s1("hello");
        string s2;

        // 对s1中的字符逐个修改
        for (size_t i = 0; i < s1.size(); i++) {
            s1[i] += 1;
            cout << s1[i] << " ";
        }
        cout << endl;

        // 测试空字符串s2
        for (size_t i = 0; i < s2.size(); i++) {
            s2[i] += 1;
            cout << s2[i] << " ";
        }
        cout << endl;
    }

    // 测试用例2：测试深拷贝和输出
    void test_string2() {
        string s1("hello");
        string s2(s1); // 深拷贝

        // 输出s1和s2
        cout << s1 << endl;
        cout << s1.c_str() << endl;
        cout << s2.c_str() << endl;
    }
}

//常量，代码指令都在代码段
