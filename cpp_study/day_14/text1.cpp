#include <iostream>
using namespace std;

class Data {
public:
    Data(const Data& d) : _year(d._year), _month(d._month), _day(d._day) {}

    bool operator<(const Data& d) const {
        return _year < d._year || (_year == d._year && _month < d._month) ||
               (_year == d._year && _month == d._month && _day < d._day);
    }

    Data operator++() {
        ++_day;
        if (_day > daysInMonth(_year,_month)) {
            _day = 1;
            ++_month;
            if (_month > 12) {
                _month = 1;
                ++_year;
            }
        }
        return *this;
    }
    bool operator != (const Data &d){
        if(_year == d._year && _month == d._month && _day == d._day){
            return false;
        }
        return true;
    }
    int operator-(const Data& d) const {
        Data max = *this;
        Data min = d;
        if(*this < d){
            max = d;
            min = *this;
        }
        int n = 0;
        while(min != max){
            ++min;
            ++n;
        }
    }

private:
    int _year;
    int _month;
    int _day;

    // 判断是否是闰年
    bool isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    }

    // 获取某个月的天数
    int daysInMonth(int month, int year) {
        switch (month) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                return 31;
            case 4: case 6: case 9: case 11:
                return 30;
            case 2:
                return isLeapYear(year) ? 29 : 28;
            default:
                return 0;
        }
    }
};