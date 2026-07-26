#include <iostream>
#include <iomanip>
using namespace std;
class Clock
{
public:
    Clock();
    // Clock(int hour,int minute);
    Clock(int hour,int minute,int sec);
    void showTime();
private:
    int hour;
    int minute;
    int sec;
};
Clock::Clock()
{
    hour=0;
    minute=0;
    sec=0;
}
// Clock::Clock(int hour,int minute)
// {
//     this->hour=hour;
//     this->minute=minute;
//     sec=3;
// }
Clock::Clock(int hour, int minute, int sec=10)
{
    this->hour=hour;
    this->minute=minute;
    this->sec=sec;
}
void Clock::showTime()
{
    cout<<setw(2)<<setfill('0')<<hour<<":"
        <<setw(2)<<setfill('0')<<minute<<":"
        <<setw(2)<<setfill('0')<<sec<<endl;
}

int main()
{
    /*构造函数定义格式的说明
     *1.构造函数函数名必须与类名相同
     *2.构造函数名的前面不需要设置返回值类型
     *3.构造函数中无返回值，不能使用return返回
     *4.构造函数的成员权限控制符一般设置为pubic
     */
    Clock clock1;
    cout<<"clock1:";
    clock1.showTime();
    Clock clock2(10,20);        //如果没有注释8和22行这一行会报错，构造函数同样要注意二义性
    cout<<"clock2:";
    clock2.showTime();
    return 0;
}