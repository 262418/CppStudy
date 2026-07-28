#include <iostream>
#include <cstring>
using namespace std;
class A
{
public:
    A(int x=0,int y=0):x(x),y(y){};
    friend ostream& operator<<(ostream& os,const A& a);
    friend istream& operator>>(istream& is,A& a);
private:
    int x;
    int y;
};
ostream& operator<<(ostream& os, const A& a)    //重载<<运算符
{
    os<<"(x,y)="<<"("<<a.x<<","<<a.y<<")";
    return os;
}
istream& operator>>(istream& is, A& a)      //  重载>>运算符
{
    is>>a.x>>a.y;
    return is;
}

class Student
{
public:
    Student(int id,double score):id(id),score(score){};
    void display()
    {
        cout<<"学号:"<<id<<",成绩:"<<score<<endl;
    }
    //重载关系运算符
    friend bool operator==(const Student& s1,const Student& s2);
    friend bool operator!=(const Student& s1,const Student& s2);
    friend bool operator>(const Student& s1,const Student& s2);
    friend bool operator<(const Student& s1,const Student& s2);
private:
    int id;
    double score;
};
bool operator==(const Student& s1, const Student& s2)
{
    return s1.score==s2.score;
}
bool operator!=(const Student& s1, const Student& s2)
{
    return s1.score!=s2.score;
}
bool operator<(const Student& s1, const Student& s2)
{
    return s1.score<s2.score;
}
bool operator>(const Student& s1, const Student& s2)
{
    return s1.score>s2.score;
}

class Assign
{
public:
    Assign(const char* name,const char* url);
    Assign(const Assign& temp);
    ~Assign()
    {
        delete[] name;
        delete[] url;
    }
    Assign& operator=(Assign& temp);
    char *name;
    char *url;
};
Assign::Assign(const char* name, const char* url)
{
    this->name=new char[strlen(name)+1];
    this->url=new char[strlen(url)+1];
    if (name){
        strcpy(this->name,name);
    }
    if (url){
        strcpy(this->url,url);
    }
}
Assign::Assign(const Assign& temp)
{
    this->name=new char[strlen(temp.name)+1];
    this->url=new char[strlen(temp.url)+1];
    if (temp.name){
        strcpy(this->name,temp.name);
    }
    if (temp.url){
        strcpy(this->url,temp.url);
    }
}
Assign& Assign::operator=(Assign& temp)
{
    delete[] name;
    delete[] url;
    this->name=new char[strlen(temp.name)+1];
    this->url=new char[strlen(temp.url)+1];
    if (temp.name){
        strcpy(this->name,temp.name);
    }
    if (temp.url){
        strcpy(this->url,temp.url);
    }
    return *this;
}

class Tag
{
public:
    Tag(int n);
    Tag(const char* src);
    ~Tag()
    {
        delete[]buf;
    }
    char& operator[](int n);
    void show()
    {
        for (int i=0;i<size;i++)
        {
            cout<<buf[i];
        }
        cout<<endl;
    }
private:
    int size;
    char* buf;
};

Tag::Tag(int n)
{
    size=n;
    buf=new char[size+1];
    *(buf+size)='\0';
}

Tag::Tag(const char* src)
{
    buf=new char[strlen(src)+1];
    strcpy(buf,src);
    size=strlen(buf);
}

char& Tag::operator[](int n)
{
    static char ch=0;
    if (n>size||n<0)
    {
        cout<<"越界"<<endl;
        return ch;
    }else{
        return *(buf+n);
    }
}

int main()
{
    //输入输出运算符只能重载为类的友元函数
    A a1(1,2);
    cout<<"a1:"<<a1<<endl;
    cout<<"请重新为a1对象输入数据"<<endl;
    cin>>a1;
    cout<<"重新输入a1后:"<<a1<<endl;
    /*通常关系运算符都要成对地重载
     *通常情况下==具有传递性，例如a=b,b=c则a=c
     *可以把一个运算符的作用交给另一个运算符,通过结果进行判断，比如!=和==
     */
    Student s1(1001,90),s2(1002,93);
    if (s1>s2){
        cout<<"s1>s2"<<endl;
        s1.display();
    }else if(s1<s2){
        cout<<"s1<s2"<<endl;
        s2.display();
    }else{
        cout<<"s1=s2"<<endl;
    }
    /*对于赋值运算符来说，如果不重载，类会自动提供一个赋值赋值运算符。
     *这个默认运算符和默认的拷贝析构函数一样实现的是浅拷贝
     */
    Assign a("github","https://github.com"),b("bilibili","https://www.bilibili.com"),c(a);
    cout<<"a:"<<a.name<<" "<<a.url<<endl;
    cout<<"c:"<<c.name<<" "<<c.url<<endl;
    c=b;
    cout<<"b:"<<b.name<<" "<<b.url<<endl;
    cout<<"c:"<<c.name<<" "<<c.url<<endl;
    /*重载运算符[]有两个目的
     *1.对象[下标] 的形式类似于 数组[下标]，更加符合用户的编写习惯
     *2.可以对下标进行越界检查
     */
    Tag arr1(20);
    for (int i = 0; i < 20; ++i)
    {
        arr1[i]=65+i;
    }
    arr1.show();
    Tag arr2("ABCDEF!");
    cout<<arr2[6]<<endl;
    arr2[6]='A';
    arr2.show();
    return 0;
}