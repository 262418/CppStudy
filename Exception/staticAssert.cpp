#include<iostream>
using namespace std;
template<typename T,typename U>
void func(T& t,U& u)
{
    static_assert(sizeof(t) == sizeof(u),"the parameters must be the same width");
    cout<<t<<"与"<<u<<"字节大小相同"<<endl;
}
int main()
{
    int x=100;
    int y=20;
    char ch='a';
    func(x,y);
    func(x,ch);
    return 0;
}