#include <iostream>
#include <sstream>
using namespace std;
template<class  T>
inline T swapString(const string &str)
{
    /*i/ostringstream用于实现字符串对象的输入/输出,i/ostringstream类的构造函数有三个;
     *1.i/ostringstream(openmode=ios_base::in):有一个默认参数openmode默认值为ios_base::in
     *2.i/ostringstream(const string& str,openmode=ios_base::in):第一个参数时string对象的常引用
     *3.i/ostringstream(i/ostringstream&& x):为移动构造函数
     */
    istringstream istr(str);    //  创建istringstream类对象istr
    T t;
    istr>>t;                    //将对象istr中的数据输入t中
    return t;
}
int main()
{
    int num=swapString<int>("10");
    cout<<"num="<<num<<endl;
    double d=swapString<double>("3.14");
    cout<<"d="<<d<<endl;
    float f=swapString<float>("abc");       //输出0转换失败
    cout<<"f="<<f<<endl;

    ostringstream ostr;         //  创建ostringstream类对象ostr
    string str;
    cout<<"请输入一个字符串:"<<endl;
    getline(cin,str);
    ostr<<str;                  //将str对象插入到ostr类对象中
    string result=ostr.str();   //使用str()成员函数获取ostr对象缓冲区内容
    cout<<result<<endl;
    return 0;
}