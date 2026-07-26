#include <cstring>
#include <iostream>
using namespace std;
class Rabbit
{
private:
    string name;
    char* food;
public:
    Rabbit(const string& name,const char* food);
    void eat();
    ~Rabbit();
};

Rabbit::Rabbit(const string& name,const char* food)
{
    cout<<"调用构造函数"<<endl;
    this->name=name;
    this->food=new char[20];
    memset(this->food,0,20);
    strcpy(this->food,food);
}

void Rabbit::eat()
{
    cout<<name<<"正在吃"<<food<<endl;
}

Rabbit::~Rabbit()
{
    cout<<"调用析构函数"<<name<<endl;
    if (food!=NULL)
    {
        delete[] food;
    }
}

int main()
{
    /*析构函数的注意事项
     *1.析构函数的名称与类名相同，在析构函数的名称前添加“~”符号
     *2.析构函数没有参数，因为没有参数，所以析构函数不能重载，一个类中只有一个析构函数
     *3.析构函数没有返回值，不能在析构函数名称前添加任何返回值类型，在析构函数内部，也不能通过析构函数释放资源
     *4.默认的析构函数只能完成栈内存对象的资源清理，无法完成堆内存对象的资源清理
     */
    /*析构函数的调用情况
     *1.在一个函数中定义了一个对象，当函数调用结束时，对象应当被释放，，对象释放之前编译器会调用析构函数释放资源
     *2.对于static修饰的对象和全局对象，只有在程序结束时编译器才会调用析构函数
     *3.对于new运算符创建的对象，在调用delete释放时，编译器会调用析构函数释放资源
     */
    Rabbit A("A","萝卜");
    A.eat();
    Rabbit B("B","白菜");
    B.eat();
    return 0;
}