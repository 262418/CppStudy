#include <cstring>
#include <iostream>
using namespace std;
class Student
{
public:
    Student( const string& id,const char* name):id(id)
    {
        this->name=new char[strlen(name)+1];
        strcpy(this->name,name);
    }
    ~Student()
    {
        delete[] name;
    }
    operator char*() const
    {
        return name;
    }
    void show() const
    {
        cout<<"ID:"<<id<<",name:"<<name<<endl;
    }
private:
    string id;
    char* name;
};

class Solid
{
public:
    Solid(int x,int y,int z):x(x),y(y),z(z){};
    void show()
    {
        cout<<"三维坐标:"<<x<<","<<y<<","<<z<<endl;
    }
    friend class Point;
private:
    int x;
    int y;
    int z;
};

class Point
{
public:
    Point(int x,int y):x(x),y(y){};
    Point(const Solid& solid)
    {
        this->x=solid.x;
        this->y=solid.y;
    }
    void show()
    {
        cout<<"平面坐标:"<<x<<","<<y<<endl;
    }
private:
    int x;
    int y;
};
int main()
{
    /*在重载的数据类型前不能指定返回值类型，返回值的类型由重载的数据类型名确定，且函数没有参数。
     *由于类型转换函数的主体是本类的对象，因此只能将类型转换函数重载为类的成员函数
     */
    Student s1("1001","小明");
    cout<<"s1:";
    s1.show();
    char* ch=s1;
    cout<<ch<<endl;
    /*转换构造函数指的是构造函数只有一个参数，且参数不是本类的const引用。用转换构造函数不仅可以将一个标准类型数据转换为类对象
     *亦可以将另一个类的对象转换为转换构造函数所在的类对象
     */
    cout<<"原始坐标"<<endl;
    Point p(1,2);
    p.show();
    Solid s(3,4,5);
    s.show();
    cout<<"三位转换平面坐标"<<endl;
    p=s;
    p.show();
    return 0;
}