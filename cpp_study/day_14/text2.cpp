//
// Created by 20212 on 12/9/2024.
//
/*
 *
 *
 *
 *
 * */
#include <iostream>
class Data {
public:
    Data(int year = 0, int month = 1,int day = 1) {
        _year = year;
        _month = month;
        _day = day;
    }
    void Print () const {
        std::cout << _year << "-" << _month << "-" << _day<<std::endl;
    }
    void f(const Data& d){
        d.Print();//实际上是传 d.Print(&d),隐含this指针,实际上这里的指针是 const Data*
    }
private:
    int _year;
    int _month;
    int _day;
}
;
int main() {
    Data d1(2020,4,18);
    d1.f(d1);
    return 0;
}