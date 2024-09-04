//
// Created by 20212 on 4/9/2024.
//
//拷贝构造传引用
//Data(const Data& d)

//const避免d被修改，出现权限缩小.d是只读
//拷贝构造是构造的一种重载

class Data{
public:
    Data(const Data & d1){
        _year = d1._year;
        _day = d1._day;
        _month = d1._month;
    }
    Data(int year = 0,int month = 1,int day =1){
        _year = year;
        _month = month;
        _day = day;
    }
    //Data d2(d1) //对象初始化时自动调用构造函数(拷贝构造)
    Data(Data &d){
        _year = d._year;
        _month = d._month;
        _day = d._day;
    }
    void Print(){
        cout << _year << "-" << _month << "-" <<_day <<endl;
    }
private:
    int _year;
    int _month;
    int _day;
};