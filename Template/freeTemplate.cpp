#include <iostream>
using namespace std;
template<class T>
class A
{
private:
    T item;
public:
    A(const T& t):item(t){}
    template<class U,class V>
    friend void show(U& u,V& v);
};
template<class U,class V>
void show(U& u,V& v)
{
    cout<<u.item<<","<<v.item<<endl;
}
int main()
{
    //非约束模板友元函数是将函数模板声明为类模板的友元函数，但函数模板的模板参数不受类模板影响
    //即友元函数模板的模板参数与类模板的模板参数不同
    A<int> a(10);
    A<int> b(20);
    A<double> c(1.2);
    cout<<"a,b:";
    show(a,b);
    cout<<"a,c:";
    show(a,c);
    return 0;
}