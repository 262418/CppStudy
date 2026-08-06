#include <iostream>
using namespace std;
class Vehicle
{
public:
    void run()
    {
        cout<<"基类run()函数:行驶"<<endl;
    }
};
class Car:public Vehicle
{
public:
    void run()
    {
        cout<<"小汽车需要燃烧汽油，行驶速度快"<<endl;
    }
};
int main()
{
    Car car;
    car.run();
    car.Vehicle::run();
    Vehicle* pv=&car;
    pv->run();
    return 0;
}