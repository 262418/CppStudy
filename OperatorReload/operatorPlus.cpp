#include <iostream>
using namespace std;
class A
{
public:
    A(int x=0,int y=0):x(x),y(y){};
    void show()const;
    A operator++();
    A operator++(int);
    friend A operator+(const A& a1,const A& a2);
    friend A operator-(const A& a1,const A& a2);
private:
    int x;
    int y;
};

void A::show() const
{
    cout<<"(x,y)="<<"("<<x<<","<<y<<")"<<endl;
}

A A::operator++()
{
    ++x;
    ++y;
    return *this;
}

A A::operator++(int)
{
    A a=*this;
    ++(*this);
    return a;
}

A operator+(const A& a1, const A& a2)
{
    return A(a1.x+a2.x,a1.y+a2.y);
}

A operator-(const A& a1, const A& a2)
{
    return A(a1.x-a2.x,a1.y-a2.y);
}

int main()
{
    /*运算符重载的具体规则
     *1.只能重载C++中已有的运算符，且不能创建新的运算符比如**重载为幂运算符是不可行的
     *2.重载后运算符不能改变优先级和结合性，也不能改变操作数和语法结构
     *3.运算符中重载的目的是针对实际运算数据类型的需要，重载要保持原有运算符的语义，并且要避免没有意义的使用运算符重载
     *4.不是所有c++运算符都可以重载，具体可以自行查询
     */
    A a1(1,2),a2(3,4);
    cout<<"a1:";
    a1.show();
    cout<<"a2:";
    a2.show();
    //双目运算符有两个操作数，左边是它本身的数据由this指针指出，右操作数通过运算符重载函数的参数操作列表
    A a=a1+a2;
    cout<<"a:";
    a.show();
    a=a1-a2;
    cout<<"a:";
    a.show();
    //重载为类的友元函数时，由于没有隐含的this指针，因此操作数的个数没有变化，操作数都必须通过通过函数的参数进行传递，
    //函数的参数与操作数自左至右保持一致
    (a1++).show();
    (++a2).show();
    return 0;
}