#include <iomanip>
#include<iostream>
using namespace std;
//函数重载就是在同一个作用域内函数名相同但参数类型或个数不同的函数
void add(const int x,const int y)
{
    cout<<x+y<<endl;
}
void add(const double x,const double y)
{
    //在这里如果把精度调高你会发现输出的不是2.3，这是因为二进制无法准确的表示小数，就像十进制无法精准表示1/3
    cout<<setprecision(2)<<setiosflags(ios::fixed)
    <<x+y<<endl;
}
//函数重载时要注意二义性，比如下边的两个函数如果只传入一个参数就会产生歧义，
//即编译器无法确定调用哪个函数
void illustration(const int x,const int y=2){};
void illustration(const int x){};
int main()
{
    add(1,2);
    add(1.1,1.2);
    return 0;
}