#include <iostream>
#include <math.h>
using namespace std;
class Point;

class Circle
{
    friend void getArea(Circle& circle);
private:
    float radius;
    const float PI=3.14;
public:
    Circle(float radius);
    ~Circle();
    float getArea(Point& p1,Point& p2);
};

Circle::Circle(float radius)
{
    this->radius=radius;
    cout<<"初始化圆的半径为:"<<radius<<endl;
}

Circle::~Circle()=default;

void getArea(Circle& circle)
{
    cout<<"圆的半径为："<<circle.radius<<endl;
    cout<<"圆的面积为："<<circle.radius*circle.radius*circle.PI<<endl;
    cout<<"友元函数修改半径："<<endl;
    circle.radius=1;
    cout<<"圆的半径为："<<circle.radius<<endl;
}

class Point
{
    friend float Circle::getArea(Point& p1,Point& p2);
public:
    Point(float x, float y);
    ~Point();
private:
    float x;
    float y;
};
Point::Point(float x,float y):x(x),y(y)
{
    cout<<"初始化坐标点"<<endl;
}

Point::~Point()=default;
float Circle::getArea(Point& p1, Point& p2)
{
    float x=abs(p1.x-p2.x);
    float y=abs(p1.y-p2.y);
    float len=sqrtf(x*x+y*y);
    cout<<"获取两个坐标点之间的距离"<<len<<endl;
    return len*len*PI;
}

int main()
{
    /*友元函数可以是类外定义的函数或者是其它类中的成员函数，若在类中声明某一函数为友元函数，
     *则该函数可以操作类中的所有数据
     */
    Circle circle(10);
    getArea(circle);
    /*其它类中的成员函数作为本类的成员函数时，需要在本类中表明该函数的作用域，并添加友元函数所在类的前向声明
     */
    Point p1(5,5);
    Point p2(10,10);
    float area=circle.getArea(p1,p2);
    cout<<"圆的面积是:"<<area<<endl;
    return 0;
}