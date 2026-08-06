#include <iostream>
using namespace std;
class Engine
{
public:
    Engine(string type,int power)
    {
        cout<<"调用发动机Engine构造函数"<<endl;
        this->type=type;
        this->power=power;
    }
    void show()
    {
        cout<<"发动机型号:"<<type<<",发动机功率:"<<power<<endl;
    }
    ~Engine()
    {
        cout<<"调用发动机Engine析构函数"<<endl;
    }
private:
    string type;
    int power;
};

class Vehicle
{
public:
    Vehicle(string name)
    {
        cout<<"调用交通工具Vehicle构造函数"<<endl;
        this->name=name;
    }
    void run()
    {
        cout<<name<<"正在行驶中"<<endl;
    }
    string getName()
    {
        return name;
    }
    ~Vehicle()
    {
        cout<<"调用交通工具Vehicle析构函数"<<endl;
    }
private:
    string name;
};
class Car:public Vehicle
{
public:
    Car(int seat,string color,string type,int power,string name):engine(type,power),Vehicle(name)
    {
        cout<<"调用小汽车Car构造函数"<<endl;
        this->seat=seat;
        this->color=color;
    }
    void brake()
    {
        cout<<getName()<<"停车"<<endl;
    }
    void display()
    {
        cout<<getName()<<"有"<<seat<<"个座位,颜色为"<<color<<endl;
    }
    ~Car()
    {
        cout<<"调用小汽车Car析构函数"<<endl;
    }
    Engine engine;
private:
    int seat;
    string color;
};
int main()
{
    /*派生类函数的定义，有以下几点要注意
     *1.派生类构造函数与基类构造函数的调用顺序是先调用基类构造函数，再调用派生类构造函数
     *2.派生类构造函数的参数列表中需要包含派生类新增成员变量和基类成员变量的参数值。调用基类构造函数时，基类构造函数从派生类的参数列表中获取实参，因此不需要类型名
     *3.如果基类没有构造函数或仅存在无参构造函数，则在定义派生类构造函数时可以省略对基类构造函数的调用
     *4.如果基类定义了有参构造函数，派生类必须定义构造函数，提供基类构造函数的参数，完成基类成员变量的初始化
     */
    Car car(5,"red","9527",140,"passat");
    car.run();
    car.brake();
    car.display();
    car.engine.show();

    return 0;
}