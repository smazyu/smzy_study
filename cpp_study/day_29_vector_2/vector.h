//
// Created by admin on 24-10-9.
//
template<class T>
class vector {
public:
    typedef T* iterator;

    vector():_start(nullptr),_finish(nullptr),_endofstorage() {

    };
    void push_back(const T& x) {

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