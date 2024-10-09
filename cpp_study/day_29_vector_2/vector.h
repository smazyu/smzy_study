#include <iostream>
#include <cstring> // 需要包含这个头文件以使用 memcpy

using namespace std;

namespace vector_study {
    template<class T>
    class vector {
    public:
        typedef T *iterator;

        vector() : _start(nullptr), _finish(nullptr), _endofstorage(nullptr) { }

        iterator begin() {
            return _start;
        }

        iterator end() {
            return _finish;
        }

        void reserve(size_t n) {
            if (n > capacity()) {
                T *tmp = new T[n]; // 新的内存
                if (_start) {
                    memcpy(tmp, _start, sizeof(T) * size()); // 复制已有元素
                    delete[] _start; // 释放旧内存
                }
                _start = tmp;
                _finish = _start + size();
                _endofstorage = _start + n; // 更新 _endofstorage
            }
        }

        void push_back(const T &x) {
            if (_finish == _endofstorage) { // 修改为比较
                size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;
                reserve(newcapacity);
            }
            *_finish = x;
            ++_finish;
        }

        size_t size() {
            return _finish - _start;
        }

        size_t capacity() {
            return _endofstorage ? (_endofstorage - _start) : 0; // 修正计算方式
        }

        void test_vector1() {
            push_back(1);
            push_back(2);
            push_back(3);
            push_back(4);
            push_back(5);
            push_back(6);

            iterator it = begin();
            while (it != end()) { // 使用当前实例的 end()
                cout << *it << " ";
                ++it;
            }
            cout << endl;
        }

    private:
        iterator _start;
        iterator _finish;
        iterator _endofstorage; // 用于存储容器的总容量
    };
}

