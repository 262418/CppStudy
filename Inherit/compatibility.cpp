#include <iostream>
using namespace std;
class Base
{
public:
    Base()
    {
        name="base";
    }
    void show()
    {
        cout<<name<<"  Base show()"<<endl;
    }
protected:
    string name;
};
class Derive:public Base
{
public:
    Derive()
    {
        name="Derive";
    }
    void display()
    {
        cout<<name<<"  Derive show()"<<endl;
    }
};
void func(Base* pbase)
{
    pbase->show();
}
int main()
{
    /*C++的类型兼容情况主要有以下几种
     *1.使用公有派生类对象为基类对象赋值；
     *2.使用公有派生类对象为基类对象的引用赋值
     *3.使用公有派生类对象的指针为基类指针赋值
     *4.如果函数的参数是基类对象，积累对象的引用、基类指针，则函数在调用时可以使用公有派生类对象、公有派生类对象的地址作为实参
     */
    Derive derive;
    Base base=derive;
    Base &pbase=derive;
    Base* qbase=&derive;
    base.show();
    pbase.show();
    qbase->show();
    func(&derive);
    return 0;
}