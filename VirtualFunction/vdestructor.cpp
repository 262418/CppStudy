#include <iostream>
using namespace std;
class Base
{
public:
    virtual ~Base()
    {
        cout<<"Base类析构函数"<<endl;
    }
};
class Derive:public Base
{
public:
    ~Derive()
    {
        cout<<"Derive析构函数"<<endl;
    }
};
int main()
{
    Base* pb=new Derive;
    delete pb;
    return 0;
}