//
// Created by Panda on 2026/7/23.
//
#include<iostream>
using namespace std;
//函数在设定默认参数后，因为默认参数赋值的顺序是从右到左，所以右侧不能有未赋值的形参
void add(const int x,const int y=1,const int z=2)
{
    cout<<x+y+z<<endl;
}
int main()
{
    add(1);
    add(1,2);
    add(1,2,3);
    return 0;
}