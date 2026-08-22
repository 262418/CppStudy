#include <cmath>
#include <functional>
#include <iostream>
using namespace std;
class A
{
public:
    A(int n):p(new int(n))
    {
        cout<<"A:构造函数"<<endl;
    }
    A(const A& a)
    {
        p=new int(*(a.p));
        cout<<"A:拷贝构造函数"<<endl;
    }
    A(A&& a)
    {
        p=a.p;
        a.p=nullptr;
        cout<<"A:移动构造函数"<<endl;
    }
    ~A()
    {
        cout<<"A:析构函数"<<endl;
    }
private:
    int* p;
};
A func()
{
    A a(10);
    return a;
}

template<typename T>
void transmit(T& t){cout<<"左值"<<endl;}
template<typename T>
void transmit(T&& t){cout<<"右值"<<endl;}
template<typename U>
void test(U&& u)
{
    transmit(forward<U>(u));
    transmit(move(u));
}

class Student
{
public:
    Student()=default;
    //目标构造函数
    Student(string name,int id,int score):name(name),id(id),score(score)
    {
        cout<<"基类Student构造函数(name，id，score)"<<endl;
    };
    //委托构造函数
    Student(string name,int score):Student(name,10,score)
    {
        cout<<"基类Student构造函数(name,score)"<<endl;
    };
    Student(int id):id(id){}
    int operator()(int num)
    {
        return id+num;
    }
private:
    string name;
    int id;
    int score;
};
class PrimaryStudent:public Student
{
public:
    using Student::Student;
    PrimaryStudent()
    {
        cout<<"派生类PrimaryStudent无参构造函数"<<endl;
    }
    PrimaryStudent(string a,int b):a(a),b(b)
    {
        cout<<"派生类PrimaryStudent构造函数(a,b)"<<endl;
    }
private:
    string a;
    int b;
};

template<typename T,typename U>
T func(T t,U u)
{
    static int count=0;
    count++;
    cout<<"count="<<count<<",&count="<<&count<<endl;
    return u(t);
}
int square(int a)
{
    return a*a;
}

int main()
{
    //左值有地址、能取地址的表达式        可以取地址的是左值，不可以的是右值
    /*右值临时值、没有地址的表达式 ，右值分为纯右值与将亡值   ps:一个已经定义的右值引用是一个左值
     *纯右值:字面常量，运算表达式，lambda表达式等
     *将亡值:即将被销毁却可以移动的值，如:函数返回值
     */
    int a=10,b=20;
    int&& r1=100;
    int&& r2=a+b;
    int&& r3=sqrt(9.0);
    // int&& r4=a;      错误

    /* RVO 是 Return Value Optimization（返回值优化）的缩写。
     * 它是 C++ 编译器做的一种优化技术，目的是避免函数返回时产生的额外拷贝/移动开销。
     * 简单说：RVO 让函数直接把要返回的对象构造在“接收者”的内存位置上，省掉了中间拷贝/移动的步骤
     */
    A m=func();
    //移动构造函数通过右值引用实现，move()将一个左值强制转换为右值
    int e=10;
    int&& r5=move(e);
    //参数转发,forward()能够使参数在转发过程中，参数类型一直保持不变，这种转发方式称为完美转发
    test(1);
    //委托构造函数:在构造函数定义时，调用另一个已经定义好的构造函数完成对象的初始化
    //目标构造函数:被委托的构造函数
    Student s1("1",2,3);
    Student s2("2",30);
    //继承构造
    PrimaryStudent ps1;
    PrimaryStudent ps2("张三",1,100);
    PrimaryStudent ps3("李四",200);
    //C++11提供了一个函数包装器function，可以包装除类成员函数之外的所有函数，包括普通函数，函数指针，lambda表达式和仿函数
    //在模板编程中，function能够使用统一的方式处理函数，减少函数模板的实例化，因此提升程序的运行效率
    int x=10;
    cout<<"square()函数:"<<func(x,square)<<endl;
    cout<<"Student类:"<<func(x,Student(1001))<<endl;
    cout<<"lambda表达式:"<<func(x,[](int b){return b/2;})<<endl;
    //三次调用地址都相同，表明func()函数只实例化了一次
    function<int(int)> fi1=square;
    function<int(int)> fi2=Student(1002);
    function<int(int)> fi3=[](int b){return b/2;};
    cout<<"square()函数:"<<func(x,fi1)<<endl;
    cout<<"Student类:"<<func(x,fi2)<<endl;
    cout<<"lambda表达式:"<<func(x,fi3)<<endl;

    return 0;
}