#include <iostream>
using namespace std;
class Wood
{
public:
    Wood()
    {
        cout<<"木材析构函数"<<endl;
    }
    ~Wood()
    {
        cout<<"木材析构函数"<<endl;
    }
};
class Sofa
{
public:
    Sofa()
    {
        cout<<"沙发构造函数"<<endl;
    }
    ~Sofa()
    {
        cout<<"沙发析构函数"<<endl;
    }
    void sit()
    {
        cout<<"沙发用来坐"<<endl;
    }
};
class Bed
{
public:
    Bed()
    {
        cout<<"床的构造函数"<<endl;
    }
    ~Bed()
    {
        cout<<"床的析构函数"<<endl;
    }
    void sleep()
    {
        cout<<"床用来睡觉"<<endl;
    }
};
class SofaBed:public Sofa,public Bed
{
public:
    SofaBed()
    {
        cout<<"沙发床构造函数"<<endl;
    }
    ~SofaBed()
    {
        cout<<"沙发床析构函数"<<endl;
    }
    Wood pearWood;
};
int main()
{
    SofaBed sbed;
    sbed.sit();
    sbed.sleep();
    return 0;
}