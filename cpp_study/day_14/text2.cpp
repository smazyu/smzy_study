//
// Created by 20212 on 12/9/2024.
//
/*
 *
 *
 *
 *
 * */

class Data{
public:
    Data(int year = 0, int month = 1,int day = 1){
        _year = year;
        _month = month;
        _day = day;
    }
    void print(){

    }
private:
    int _year;
    int _month;
    int _day;
};
int main(){
    Data d1(2020,4,18);
    return 0;
}