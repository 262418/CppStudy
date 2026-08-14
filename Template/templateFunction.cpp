#include <iostream>
using namespace std;
template<typename T>
T add(T t1,T t2)
{
    return t1+t2;
}
// template int add<int>(int t1,int t2);

//函数模板可以被重载，当进行函数调用时，编译器根据实参的类型与个数决定调用哪个函数模板实例化函数
int Max(const int& a,const int &b)
{
    return a>b?a:b;
}
template<typename T>
T Max(const T& t1,const T& t2)
{
    return t1>t2?t1:t2;
}
template<typename T>
T Max(const T&a,const T& b,const T& c)
{
    return max(a,max(b,c));
}
int main()
{
    /*隐式实例化是根据函数调用时传入的参数的数据类型确定模板参数T的类型，
     *如传入的参数是int类型就会实例化出一个int类型的该函数
     */
    cout<<add(1,2)<<endl;
    cout<<add(1.2,2.3)<<endl;
    /*显式实例化是当模板参数指定两种不同类型的数据时，将数据强制转换为指定类型的数据
     *随着编译器的不断完善，显示声明(第8行的代码)可以省略，在调用时显式指定要实例化的类型即可
     */
    cout<<add<int>(10,'B')<<endl;

    cout<<Max(1,2)<<endl;
    cout<<Max(1,2,3)<<endl;
    cout<<Max('a','e')<<endl;
    cout<<Max(6,3.2)<<endl;
    return 0;
}