#include <iostream>

class Data {
public:
    // 获取指定年份和月份的天数
    int GetMonthDay(int year, int month) {
        int monthDays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        // 是二月且是闰年，返回29天
        if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)) {
            return 29;
        }
        return monthDays[month];
    }

    // 构造函数
    Data(int year = 0, int month = 1, int day = 1) {
        if (year >= 0 && month >= 1 && month <= 12 && day >= 1 && day <= GetMonthDay(year, month)) {
            _year = year;
            _month = month;
            _day = day; // 修正：将 day 赋值给 _day
        } else {
            std::cout << "非法日期" << std::endl;
            _year = 0;
            _month = 1;
            _day = 1;
        }
    }

    // 拷贝构造函数
    Data(const Data &d) { // 使用 const 引用以避免修改原对象
        _year = d._year;
        _month = d._month;
        _day = d._day;
    }

    //d1 < d2
    //d1.operator<(&d1,d2)
    bool operator<(const Data &d) const {
        if (_year < d._year) {
            return true;
        } else if (_year == d._year && _month < d._month) {
            return true;
        } else if (_year == d._year && _month == d._month && _day < d._day) {
            return true;
        }
        return false;
    }

    bool operator==(const Data &d) const {
        return _year == d._year && _month == d._month && _day == d._day;
    }

    bool operator<=(const Data &d) const {
        return *this < d || *this == d;
    }

    bool operator>(const Data &d){
        return !(*this <= d);
    }

    void Print() {
        std::cout << _year << "-" << _month << "-" << _day << std::endl;
    }

private:
    int _year;
    int _month;
    int _day;
};

int main() {
    Data d1;
    d1.Print();
    Data d2(2021, 2, 29); // 输入一个非法日期
    d2.Print();
}
//一年公转一圈，地球自转365天，每年365天，大概多出5h
//每过四年，多出接近24小时