#include <iostream>
using namespace std;
int main()
{
    //put()函数用于输出单个字符，将字符插入输入输出流对象
    cout.put('t').put('t').put('\n');
    //writer()函数用于输出一个字符串，将指定个数的字符串插入输出流对象
    cout.write("I LOVE CHINA",12).write("\n",1);
    //get()函数用于从输入流中读取单个字符或多个字符
    char ch;
    cout<<"请输入一个字符串"<<endl;
    int n=cin.get();
    cout<<"第一种形式:"<<n<<endl;   //get()的返回值是int
    cin.get(ch);
    cout<<"第二种形式:"<<ch<<endl;   //get(char& ch)的返回值为istream类对象引用
    char buf[20];
    cin.get(buf,6,' ');
    cout<<"第三种形式:"<<buf<<endl;  //get(char* dst,streamsize count,char delimiter):dst指向一块内存区域，count-1表示读取字符个数，delimiter表示结束符
    //getline()函数用于从输入流中读取字符，直到读取到指定长度的字符或遇到终止字符时结束读取
    char buf1[4];
    cin.getline(buf1,4);           //getline(char* dst,streamsize count):dst指向一块内存区域，count-1表示读取字符个数
    // cin.getline(buf1,4,' ');  //前两个与上边相同，delimiter是终止符
    //ignore()函数的作用是跳过输入流中的n个字符
    // cin.ignore();
    //read()函数用于从输入流中读取指定字符个数的字符串
    char buf2[50]={0};
    cout<<"请输入一个字符串:"<<endl;
    cin.read(buf2,25);
    cout<<"输出:"<<endl<<buf2<<endl;
    //gcount()函数的作用是计算上次读取到的字符个数
    cout<<"上次读取到的字符个数:"<<cin.gcount()<<endl;
    //peek()的作用是检测输入流中待读取的字符，返回值为int类型
    //putback()函数的作用是将上一次读取的字符放回输入流中，使之可被下一次读取
    // char ch=cin.get();
    // cout<<ch<<endl;
    // cin.putback(ch);
    // cout<<cin.get()<<endl;
    return 0;
}