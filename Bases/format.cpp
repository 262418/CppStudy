#include<iostream>
//输入输出操纵器提供带参数的操纵器
#include<iomanip>
using namespace std;
int main(){
    //和const的区别是后者可以在运行时，前者必须在编译时确定
    constexpr  int a=10;
    //分别以8进制，10进制和16进制输出
    cout<<"oct:"<<oct<<a<<endl;
    cout<<"dec:"<<dec<<a<<endl;
    cout<<"hex:"<<hex<<a<<endl;
    double x,y;
    //cin从键盘输入值赋给x,y,中间用空格隔开
    cin>>x>>y;
    cout<<"默认输出:"<<x<<endl;
    //setprecision(6) 设置的是 “有效数字位数”。在没有开启 fixed 的情况下，
    //6 表示 6 位有效数字；在开启 fixed 之后，6 表示小数点后固定 6 位。
    //而 fixed 和 precision(6) 都是粘性的，后续的 y 输出会沿用这个设置，所以只显示 6 位小数。
    cout<<"精确输出:"<<setprecision(6)<<setiosflags(ios::fixed)<<x<<endl;
    //setw()指定域宽,setfill()设置填充方式,setiosflags()设置对齐方式
    cout<<setw(10)<<y<<endl;
    cout<<setw(10)<<setfill('0')<<y<<endl;
    cout<<setw(10)<<setfill('0')<<setiosflags(ios::left)<<y<<endl;
    cout<<setw(10)<<setfill('0')<<setiosflags(ios::right)<<y<<endl;

    return 0;
}