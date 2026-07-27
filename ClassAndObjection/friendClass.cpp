#include <iostream>
using namespace std;
class Time
{
public:
    Time(int hour,int minute,int second);
    //如果没有 friend class Date; 这一行，time.hour、time.minute、time.second 会报错（因为它们是私有的）。
    friend class Date;
private:
    int hour;
    int minute;
    int second;
};
class Date
{
public:
    Date(int year,int month,int day);
    void showTime(Time& time);
private:
    int year;
    int month;
    int day;
};

Date::Date(int year, int month, int day)
{
    this->year=year;
    this->month=month;
    this->day=day;
}

void Date::showTime(Time& time)
{
    cout<<year<<"-"<<month<<"-"<<day<<" "<<time.hour<<":"<<time.minute<<":"<<time.second<<endl;
}

Time::Time(int hour, int minute, int second)
{
    this->hour=hour;
    this->minute=minute;
    this->second=second;
}
int main()
{
    /*友元类可以声明在类中任意位置，声明友元类之后，友元类中的所有成员函数都是该类的友元函数，能够访问该类的所有成员
    *1.可以声明在类的任何位置（public/private/protected 都可以）
    *2.友元关系是单向的：Date 可以访问 Time，但 Time 不能访问 Date
    *3.友元关系不能传递：如果 A 是 B 的友元，B 是 C 的友元，不代表 A 是 C 的友元
    *4.友元关系不能被继承
     */
    Time time(21,50,52);
    Date date(2026,7,27);
    date.showTime(time);
    return 0;
}