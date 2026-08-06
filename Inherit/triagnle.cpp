#include <iostream>
using namespace std;
class Sofa
{
public:
    void rest()
    {
        cout<<"沙发可以坐着休息"<<endl;
    }
};
class Bed
{
public:
    void rest()
    {
        cout<<"床可以躺着休息"<<endl;
    }
};
class SofaBed:public Sofa,public Bed
{
public:
    void function()
    {
        cout<<"沙发床综合了沙发和床的功能"<<endl;
    }
};
int main()
{
    SofaBed sbed;
    sbed.rest();
    return 0;
}