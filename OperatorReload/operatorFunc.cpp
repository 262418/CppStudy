#include <iostream>
using namespace std;
class Show
{
public:
    void operator()(const string str)
    {
        cout<<str<<endl;
    }
    float operator()(const float num)
    {
        return num*num;
    }
};

int main()
{
    //仿函数指的是在类中重载"()"运算符后，这个类的对象可以像函数一样使用
    Show s;
    s("ABCD");
    cout<<s(3)<<endl;
    return 0;
}