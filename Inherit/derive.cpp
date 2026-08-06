#include <iostream>
using namespace std;
class Animal
{
public:
    void move()
    {
        cout<<"动物行为"<<endl;
    }
};
class Cat:public Animal
{
public:
    Cat(string name)
    {
        this->name=name;
    }
    void walk()
    {
        cout<<name<<"会走"<<endl;
    }
private:
    string name;
};
int main()
{
    /*在类的继承中有几点需要注意
     *1.基类的构造函数与析构函数不能被继承
     *2.派生类对基类成员的继承没有选择权，不能选择继承或者不继承某些成员
     *3.派生类中可以增加新的成员，用于实现新功能，保证派生类的功能在基类基础上有所扩展
     *4.一个基类可以派生出多个派生类，一个派生类也可以继承多个基类
     */
    Cat cat("猫");
    cat.move();
    cat.walk();
    return 0;
}