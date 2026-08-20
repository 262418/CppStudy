#include <iostream>
using namespace std;
class Shape{
public:
    Shape()
    {
        count++;
        if (count==3)
        {
            throw "纸张画不下了";
        }
        cout<<"Shape构造函数"<<endl;
    }
    ~Shape()
    {
        cout<<"Shape析构函数"<<endl;
    }
    static int count;
};
int Shape::count=0;
int main()
{
    /*C++不仅能够处理各种不同类型的异常，还可以在异常处理前释放所有局部对象。从进入try语句块
     *开始到异常被抛出之前，在栈上创建的所有对象都会被析构，析构的顺序与构造的顺序相反，
     *这一过程称为栈解旋或栈自旋
     */
    Shape circle;
    try
    {
        int num=2;
        cout<<"纸张可画图形个数:"<<num<<endl;
        Shape rectangle;
        Shape triangle;
    }catch (const char* e)
    {
        cout<<e<<endl;
    }
    return 0;
}