#include <iostream>
#include <string>
using namespace std;
int main()
{   //c语言中用字符数组来处理字符串
    string s1;
    s1="I am a gentleman";              //第一种
    string s2="I am a gentleman";       //第二种
    string s3={"I am a gentleman"};   //第三种
    string s4{6,'a'};                   //第四种
    //c++中string类重载了[]，可以通过索引来操作指定位置的字符
    string s5="hello world";
    s5[2]='W';
    s5[7]='C';
    cout<<s5<<endl;
    //c语言中连接两个字符串需要使用strcat()，还要考虑内存溢出，string重载了+，可以直接用+连接字符串
    string s6="hello",s7="C++";
    cout<<s6+s7<<endl;
    //c语言中连接两个字符串需要使用strcmp()，string重载了< > ==，可以直接用与比较字符串
    string s8,s9;
    cin>>s8>>s9;
    //比较的是ASCLL值，第一个字符就决定大小，如果前几个字符大小一样比较长短
    if (s8>s9){
        cout<<"s8大于s9"<<endl;
    }else if (s8<s9){
        cout<<"s8小于s9"<<endl;
    }else{
        cout<<"两个字符串相同"<<endl;
    }
    //string类提供了length()函数获取字符串长度，类似于c语言中的strlen()函数
    string s10="Hello C++";
    cout<<s10.length()<<endl;
    //string类提供了swap()函数交换两个字符串的值，但是c语言风格的字符串不能交换
    string s11="HELLO C++";
    string s12="hello c++";
    s11.swap(s12);                          //通过.运算符交换
    swap(s11,s12);                //通过函数调用交换
    cout<<"s11="<<s11<<",s12="<<s12<<endl;
    return 0;
}