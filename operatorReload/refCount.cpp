#include <iostream>
using namespace std;
class Data
{
public:
    Data(string str):str(str)
    {
        cout<<"Data类构造函数"<<endl;
    }
    ~Data()
    {
        cout<<"Data类析构函数"<<endl;
    }
    void dis()
    {
        cout<<str<<endl;
    }
private:
    string str;
};
int main()
{
    /*C++没有垃圾回收机制，对内存资源的使用和释放需要自己编写程序实现，编写大型的程序可能会忘记释放内存，导致内存泄漏。
     *为了解决这个问题，C++标准提出了智能指针机制。
     *智能指针的本质是使用引用计数的方式解决悬空指针的问题，通过重载"*"和"->"运算符来实现
     */
    Data *pstr1=new Data("I love china");
    Data *pstr2=pstr1;
    Data *pstr3=pstr1;
    pstr1->dis();
    delete pstr1;
    pstr2->dis();
    //当pstr1被释放时，其他两个指针仍在使用此对象，造成悬空指针
    return 0;
}