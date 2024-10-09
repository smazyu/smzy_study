//
// Created by admin on 24-10-9.
//
template<class T>
class vector {
public:
    typedef T *iterator;

    vector(): _start(nullptr), _finish(nullptr), _endofstorage() {
    };

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

private:
    iterator _start;
    iterator _finish;
    iterator _endofstorage;
    //start指向第一个位置 finish指向最后一个位置的下一个位置
};
