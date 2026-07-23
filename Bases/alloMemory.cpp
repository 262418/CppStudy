#include <iostream>
using namespace std;
int main()
{
    //new申请的是堆内存，delete释放的是堆内存
    //申请一块内存空间初始化为10，并将其地址赋给p;
    int* p=new int(10);
    cout<<"*p="<<*p<<endl;
    *p=20;
    cout<<"*p="<<*p<<endl;
    //申请十块连续的内存空间，并将其首地址赋给pc;
    char* pc=new char[10];
    for (int i = 0; i < 10; ++i)
    {
        pc[i]=i+65;
        cout<<pc[i]<<" ";
    }
    delete[]pc;     //释放空间
    delete p;       //释放空间
    return 0;
}