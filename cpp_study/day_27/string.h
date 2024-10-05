#include <cassert>
#include <iostream>
using namespace std;

namespace simulation {
    class string {
    public:
        // 类型定义：迭代器
        typedef char *iterator;

        // 构造函数，默认参数为""，即空字符串
        string(const char *str = "") {
            _size = strlen(str);
            _capacity = _size;
            _str = new char[_capacity + 1];
            strcpy_s(_str, _capacity + 1, str); // 使用安全的strcpy_s
        }

        // 拷贝构造函数，深拷贝
        string(const string &s) : _str(new char[strlen(s._str) + 1]) {
            strcpy_s(_str, strlen(s._str) + 1, s._str); // 使用安全的strcpy_s
            _size = s._size;
            _capacity = s._capacity;
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

        // += 运算符重载，添加字符
        string &operator+=(char ch) {
            this->push_back(ch);
            return *this;
        }

        // += 运算符重载，添加字符串
        string &operator+=(const char *str) {
            this->append(str);
            return *this;
        }

        // 迭代器起点
        iterator begin() {
            return _str;
        }

        // 迭代器终点
        iterator end() {
            return _str + _size;
        }

        // 获取字符串长度
        size_t size() const {
            return _size;
        }

        // 获取字符串容量
        size_t capacity() const {
            return _capacity;
        }

        // 返回 C 风格字符串
        const char *c_str() const {
            return _str;
        }

        // 添加单个字符
        void push_back(char ch) {
            if (_size == _capacity) {
                size_t newcapacity = _capacity == 0 ? 2 : _capacity * 2;
                reserve(newcapacity);
            }
            _str[_size] = ch;
            ++_size;
            _str[_size] = '\0'; // 保证最后一位为\0
        }

        // 保留容量
        void reserve(size_t n) {
            if (n > _capacity) {
                char *newstr = new char[n + 1];
                strcpy_s(newstr, _size + 1, _str); // 使用安全的strcpy_s
                delete[] _str;
                _str = newstr;
                _capacity = n;
            }
        }

        // 添加字符串
        void append(const char *str) {
            size_t len = strlen(str);
            if (_size + len > _capacity) {
                reserve(_size + len);
            }
            strcpy_s(_str + _size, len + 1, str); // 使用安全的strcpy_s
            _size += len;
        }

        // resize将字符串大小调整为 n 个字符
        // 插入单个字符
        string &insert(size_t pos, char ch) {
            assert(pos <= _size); // 修正条件，允许在末尾插入
            if (_size == _capacity) {
                size_t newcapacity = _capacity == 0 ? 2 : _capacity * 2;
                reserve(newcapacity);
            }
            int end = _size;
            while (end >= static_cast<int>(pos)) {
                _str[end + 1] = _str[end];
                --end;
            }
            _str[pos] = ch;
            ++_size;
            _str[_size] = '\0'; // 别忘了在结尾加上 '\0'
            return *this;
        }

        // 插入字符串
        string &insert(size_t pos, const char *stt) {
            assert(pos <= _size); // 插入位置不应超过现有字符串长度
            size_t len = strlen(stt);
            if (_size + len > _capacity) {
                reserve(_size + len);
            }
            for (int i = _size - 1; i >= static_cast<int>(pos); --i) {
                _str[i + len] = _str[i];
            }
            for (size_t i = 0; i < len; ++i) {
                _str[pos + i] = stt[i];
            }
            _size += len;
            _str[_size] = '\0'; // 别忘了更新结尾的 '\0'
            return *this;
        }

        void resize(size_t n, char ch = '\0') {
            if (n < _size) {
                _str[n] = '\0';
                _size = n;
            } else {
                if (n > _capacity) reserve(n);
                for (size_t i = _size; i < n; i++) _str[i] = ch;
                _str[n] = '\0';
                _size = n;
            }
        }

        void erase(size_t pos, size_t len) {
            assert(pos < _size);
            if (len >= _size - pos) {
                _str[pos] = '\0';
                _size = pos;
            } else {
                size_t i = pos + len;
                while (i <= _size) {
                    _str[i - len] = _str[i];
                    i++;
                }
                _size -= len;
            }
        }

        size_t find(char ch, size_t pos = 0) {
            for (size_t i = pos; i < _size; ++i) {
                if (_str[i] == ch) return i;
            }
            return npos;
        }

        size_t find(const char *str, size_t pos = 0) {
            char *p = strstr(_str, str);
            if (p == nullptr) return npos;
            else return p - _str;
        }

        bool operator<(const string &s) {
            int ret = strcmp(_str, s._str);
            return ret < 0;
        }

        bool operator==(const string &s) {
            int ret = strcmp(_str, s._str);
            return ret == 0;
        }

        bool operator<=(const string &s) {
            return *this == s || *this < s;
        }

        bool operator>(const string &s) {
            !(*this <= s);
        }

        bool operator>=(const string &s) {
            return !(*this < s);
        }

        bool operator !=(const string &s) {
        }

    private:
        char *_str; // 字符串指针
        size_t _size; // 字符串长度
        size_t _capacity; // 字符串容量
        static size_t npos;
    };

    size_t string::npos = -1;

    // 输出运算符重载
    ostream &operator<<(ostream &out, const string &s) {
        for (size_t i = 0; i < s.size(); ++i) out << s[i];
        return out;
    }

    istream &operator>>(istream &in, string &s) {
        while (1) {
            char ch;
            in >> ch;
            if (ch == '\0' || ch == '\n') {
                break;
            } else {
                s += ch;
            }
        }
        return in;
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

    // 测试用例3：测试字符串的迭代器操作
    void test_string3() {
        string s1("hello");
        string s2(s1);

        for (size_t i = 0; i < s2.size(); ++i) {
            s2[i] += 2;
            cout << s2[i] << " ";
        }
        cout << endl;

        string::iterator it2 = s2.begin();
        while (it2 != s2.end()) {
            *it2 -= 1;
            cout << *it2 << " ";
            ++it2;
        }
        cout << endl;

        // 范围for最终会被替换为迭代器
        for (auto e: s2) {
            cout << e << " ";
        }
        cout << endl;
    }

    void test_string4() {
        string s1("hello");
        s1.insert(1, 'x');
        cout << s1 << endl;
        s1.insert(1, "helloworld");
        cout << s1 << endl;
    }

    void test_string5() {
        std::string s2("hello");

        // 输出初始状态
        std::cout << "Initial size: " << s2.size() << std::endl;
        std::cout << "Initial string: " << s2 << std::endl;
        std::cout << "Initial capacity: " << s2.capacity() << std::endl;

        // 扩展到 8 个字符，应该用 '\0' 填充多余的部分
        s2.resize(8);
        std::cout << "\nAfter resize(8):" << std::endl;
        std::cout << "Size: " << s2.size() << std::endl;
        std::cout << "String: " << s2 << std::endl;
        std::cout << "Capacity: " << s2.capacity() << std::endl;

        // 扩展到 10 个字符，用 'a' 填充
        s2.resize(10, 'a');
        std::cout << "\nAfter resize(10, 'a'):" << std::endl;
        std::cout << "Size: " << s2.size() << std::endl;
        std::cout << "String: " << s2 << std::endl;
        std::cout << "Capacity: " << s2.capacity() << std::endl;

        // 扩展到 20 个字符，用 'y' 填充
        s2.resize(20, 'y');
        std::cout << "\nAfter resize(20, 'y'):" << std::endl;
        std::cout << "Size: " << s2.size() << std::endl;
        std::cout << "String: " << s2 << std::endl;
        std::cout << "Capacity: " << s2.capacity() << std::endl;
    }

    void test_string6() {
        string s1("abcde");

        // 插入单个字符
        s1.insert(2, 'X');
        cout << "After inserting 'X' at index 2: " << s1 << endl; // abXcde

        // 插入字符串
        s1.insert(4, "YZ");
        cout << "After inserting 'YZ' at index 4: " << s1 << endl; // abXYcYZde
    }

    // 测试用例7：测试字符串删除
    void test_string7() {
        string s1("abcdefgh");

        // 删除从索引2开始的3个字符
        s1.erase(2, 3);
        cout << "After erasing 3 characters from index 2: " << s1 << endl; // abfgh

        // 删除超出范围的字符，应该处理得当
        s1.erase(3, 10);
        cout << "After trying to erase more characters than available: " << s1 << endl; // abf
    }

    // 测试用例8：测试字符串查找
    void test_string8() {
        string s1("hello world");

        // 查找字符
        size_t pos1 = s1.find('o');
        cout << "First occurrence of 'o': " << pos1 << endl; // 4

        // 查找不存在的字符
        size_t pos2 = s1.find('z');
        if (pos2 == -1)
            cout << "'z' not found" << endl; // 'z' not found

        // 查找子字符串
        size_t pos3 = s1.find("world");
        cout << "Position of 'world': " << pos3 << endl; // 6

        // 从指定位置开始查找
        size_t pos4 = s1.find('o', 5);
        cout << "First occurrence of 'o' after index 5: " << pos4 << endl; // 7
    }

    // 测试用例9：测试+= 运算符
    void test_string9() {
        string s1("abc");

        // 添加单个字符
        s1 += 'd';
        cout << "After adding 'd': " << s1 << endl; // abcd

        // 添加字符串
        s1 += "efg";
        cout << "After adding 'efg': " << s1 << endl; // abcdefg
    }

    // 测试用例10：测试扩容与 push_back
    void test_string10() {
        string s1;

        // 添加字符，测试自动扩容
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            s1.push_back(ch);
            cout << "String: " << s1 << ", Size: " << s1.size() << ", Capacity: " << s1.capacity() << endl;
        }
    }
}

// 常量，代码指令都在代码段
