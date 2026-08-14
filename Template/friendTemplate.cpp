#include <iostream>
using namespace std;
template<class T>
class A
{
    T item;
    static int count;
public:
    A(const T& t):item(t)
    {
        count++;
    }
    ~A()
    {
        count--;
    }
    friend void func();
    friend void show(const A<T>& a);
};
template<typename  T>
int A<T>::count=0;
void func()
{
    cout<<"int count:"<<A<int>::count<<";";
    cout<<"double count:"<<A<double>::count<<";"<<endl;
}
void show(const A<int>& a)
{
    cout<<"int:"<<a.item<<endl;
}
void show(const A<double>& a)
{
    cout<<"double:"<<a.item<<endl;
}
int main()
{
    //非模板友元函数就是将一个普通函数声明为友元函数
    func();
    A<int> a(10);
    func();
    A<double> b(1.2);
    show(a);
    show(b);
    return 0;
}