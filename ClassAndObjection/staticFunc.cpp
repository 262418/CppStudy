#include <iostream>
#include<math.h>
using namespace std;
class Student
{
public:
    Student(const string& name);
    ~Student();
    static int num;
private:
    string name;
};
class Point
{
public:
    Point(float x, float y);
    ~Point();
    static float getLen(Point& p1,Point& p2);
    static float len;
private:
    float x;
    float y;
};
Student::Student(const string& name)
{
    this->name=name;
    num++;
}
Student::~Student()=default;
int Student::num=0;
Point::Point(float x,float y)
{
    cout<<"初始化坐标点"<<endl;
    this->x=x;
    this->y=y;
}
Point::~Point()=default;
float Point::len=0;
float Point::getLen(Point& p1, Point& p2)
{
    float x=abs(p1.x-p2.x);
    float y=abs(p1.y-p2.y);
    len=sqrtf(x*x+y*y);
    return len;
}

int main()
{
    /*static修饰的静态成员变量只能在类内部定义，在类外部初始化。静态成员变量在调用时，可以通过对象和类进行访问。
     *由于static成员变量存储在类的外部，计算类的大小时不包含在内
     */
    Student s1("abc");
    Student s2("ABC");
    cout<<"人数为:"<<s1.num<<endl;
    cout<<"人数为:"<<s2.num<<endl;
    cout<<"人数为:"<<Student::num<<endl;
    cout<<"s1的大小为："<<sizeof(s1)<<endl;
    /*类中定义的普通函数只能通过对象调用，无法使用类调用。使用static修饰的成员函数，同静态成员变量一样，可以通过对象或类调用。
     *静态成员函数可以直接访问类中的静态成员变量和静态成员函数，对外提供了访问接口，实现了静态成员变量的管理。
     *需要注意的是，静态成员函数属于类，不属于对象，没有this指针
     */
    Point p1(1,2);
    Point p2(6,8);
    cout<<Point::getLen(p1,p2)<<endl;
    return 0;
}