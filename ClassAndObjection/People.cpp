#include <iostream>
using namespace std;
class Birth
{
public :
    Birth(int year,int month,int day);
    void show();
private:
    int year;
    int month;
    int day;
};

Birth::Birth(int year, int month, int day):year(year),month(month),day(day)
{
    cout<<"Birth类构造函数"<<endl;
}
void Birth::show()
{
    cout<<"出生日期："<<year<<"-"<<month<<"-"<<day<<endl;
}
class People
{
private:
    string name;
    int idCard=0;
    Birth birth;
public:
    People(const string& name,int idCard,int year, int month, int day);
    void show();
};

People::People(const string& name,int idCard,int year, int month, int day):birth(year,month,day)
{
    cout<<"People类构造函数"<<endl;
    this->name=name;
    this->idCard=idCard;
}

void People::show()
{
    cout<<"姓名："<<name<<endl;
    cout<<"身份证号："<<idCard<<endl;
    birth.show();
}

int main()
{
    //birth 作为成员对象，必须在 People 构造函数体执行之前完成构造。
    People p("abc",10000,2000,8,8);
    p.show();
    return 0;
}