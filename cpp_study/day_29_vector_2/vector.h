//
// Created by admin on 24-10-9.
//
template<class T>


namespace vector_study {
    class vector {
    public:
        typedef T *iterator;

        vector(): _start(nullptr), _finish(nullptr), _endofstorage() {
        };

        iterator begin() {
            return _start;
        }

        iterator end() {
            return _finish;
        }

        void reserve(size_t n) {
            T *tmp = new T[n];
            if (n > capacity()) {
                if (_start) {
                    memcpy(tmp, _start, sizeof(T) * capacity());
                    delete[] _start;
                }
            }
            _start = tmp;
            _finish = _start + size();
            _endofstorage = _start + capacity();
        }

        void push_back(const T &x) {
            if (_finish = _endofstorage) {
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
            return _endofstorage - _finish;
        }

        void test_vector1() {
            vector<int> v;
            v.push_back(1);
            v.push_back(2);
            v.push_back(3);
            v.push_back(4);
            v.push_back(5);
            v.push_back(6);

            vector<int>::iterator it = begin();
            while (it != v.end()) {
                cout << *it << " ";
                ++it;
            }
            cout << endl;
        }

    private:
        iterator _start;
        iterator _finish;
        iterator _endofstorage;
        //start指向第一个位置 finish指向最后一个位置的下一个位置
    };
}
