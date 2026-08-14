#include <iostream>
using namespace std;
//类模板派生普通类：在派生过程中需要指定模板参数类型
template<class T>
class Base1
{
public:
    Base1();
    Base1(T x,T y);
    Base1 getX();
    Base1 getY();
    ~Base1();
private:
    T x;
    T y;
};
class Derive1:public Base1<double>
{
public:
    Derive1(double a,double b,double c):num(c),Base1<double>(a,b){}
private:
    double num;
};
//类模板派生类模板
template<class T>
class Base2
{
public:
    T a;
    Base2(T n):a(n){}
    T get() const
    {
        return a;
    }
};
template<class T,class U>
class Derive2:public Base2<U>
{
public:
    U b;
    Derive2(T t,U u):Base2<T>(t),b(u){}
    U sum()const
    {
        return b+ Base2<U>::get();
    }
};
//普通类派生类模板
class Base3
{
public:
    Base3(int n):a(n){};
    int get() const
    {
        return a;
    };
private:
    int a;
};
template<class T>
class Derive3:public Base3
{
public:
    Derive3(int n,T t):Base3(n),b(t){};
    T sum() const
    {
        return b+(T)get();
    }
private:
    T b;
};
int main()
{

    return 0;
}