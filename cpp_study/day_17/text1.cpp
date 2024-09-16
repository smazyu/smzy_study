//
// Created by 20212 on 16/9/2024.
//
#include <iostream>
using namespace std;
class Date{
    friend void f(Date&d);
public:
    Date():_year(10){}
    void Print(){
        cout <<_year<<"-"<<_month<<"-"<<_day<<endl;
    }
    void operator << (ostream&out){
        out << _year <<"/" <<_month <<"/" << _day << endl;
    }
private:
    //c++11
    //声明时给缺省值
    int _year = 0;
    int _month = 1;
    int _day = 1;
    //static int _n 这个不能给初始值 必须在类外面去定义
};
//int Date::n = 1;
void f(Date &d){
    d._year = 10;
    cout << d._year <<endl;
}
int main(){
    Date d1;
    d1.Print();
    d1 << cout;
    f(d1);
    return 0;
}
//类里面都是声明
//友元 类外面访问类里面私有的方式
//友元 类外面访问