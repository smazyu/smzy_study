#include <iostream>
#include <cstring> // 需要包含这个头文件以使用 memcpy

namespace vector_study {
    template<class T>
    class vector {
    public:
        typedef T *iterator;

        vector() : _start(nullptr), _finish(nullptr), _endofstorage(nullptr) {
        }

        iterator begin() {
            return _start;
        }

        iterator end() {
            return _finish;
        }

        void reserve(size_t n) {
            if (n > capacity()) {
                size_t sz = size();
                T *tmp = new T[n]; // 新的内存
                if (_start) {
                    memcpy(tmp, _start, sizeof(T) * sz); // 复制已有元素
                    delete[] _start; // 释放旧内存
                }
                _start = tmp;
                _finish = _start + sz;
                _endofstorage = _start + n; // 更新 _endofstorage
            }
        }

        void push_back(const T &x) {
            if (_finish == _endofstorage) {
                // 修改为比较
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

    private:
        iterator _start;
        iterator _finish;
        iterator _endofstorage; // 用于存储容器的总容量
    };

    void test_vector1() {
        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
        v.push_back(5);
        v.push_back(6);

        vector<int>::iterator it = v.begin();
        while (it != v.end()) {
            // 使用当前实例的 end()
            std::cout << *it << " ";
            ++it;
        }
        std::cout << std::endl;
    }
}
