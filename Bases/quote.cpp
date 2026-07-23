#include <iostream>
using namespace std;
void exchange(int &x,int &y)
{
    const int temp=x;
    x=y;
    y=temp;
}
int main()
{
    /*需要注意的是
     *1.引用在定义时必须初始化并且与变量类型保持一致
     *2.引用在初始化时不能绑定常量值
     *3.引用在初始化后，其值不能再更改，不能再用作其他变量的引用
     */
    constexpr int a=10;
    const  int& b=a;
    cout<<"&a="<<&a<<endl;
    cout<<"&b="<<&b<<endl;
    cout<<"b="<<b<<endl;
    /*另外引用不等于指针
     *1.指针指向一个变量需要占用额外的内存，而引用不需要(逻辑上不占，物理上还是占用的)
     *2.作为函数参数时，指针的实参是变量的内存地址，而引用的实参是变量本身(可以理解成给变量起了个外号),
     *但是系统向引用传递的是变量的地址(这也是为什么下边的函数示例为什么成功交换了变量的值，而不是生成变量副本)
     */
    int x,y;
    cin>>x>>y;
    //传入的实际是地址
    exchange(x,y);
    cout<<"x="<<x<<",y="<<y;
    return 0;
}