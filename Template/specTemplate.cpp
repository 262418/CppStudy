#include <cstring>
#include <iostream>
using namespace std;
template<class T>
class Special
{
public:
    Special(T a, T b)
    {
        this->a=a;
        this->b=b;
    }
    T compare()
    {
        cout<<"类模板"<<endl;
        return a>b?a:b;
    }
private:
    T a;
    T b;
};
//类模板全特化
template<>
class Special<const char*>
{
public:
    Special(const char* a,const char* b)
    {
        this->a=a;
        this->b=b;
    }
    const char* compare()
    {
        cout<<"类模板特化"<<endl;
        if (strcmp(a,b)>0)
        {
            return a;
        }else
        {
            return b;
        }
    }
private:
    const char* a;
    const char* b;
};
int main()
{
    /*特化就是将泛型的东西具体化，模板特化就是唯一有的模板参数进行具体化的指定
     *使得不受任何约束的模板参数收到特定约束或完全被指定
     */
    //全特化就是将模板中的模板参数全部指定为确定的类型，其标志就是产生出完全确定的东西
    Special<string> s1("hello","nihao");
    cout<<s1.compare()<<endl;
    Special<const char*> s2("hello","nihao");
    cout<<s2.compare()<<endl;
    /*偏特化就是模板中的模板参数没有被全部指定，需要编译器在编译时进行确定
     *如：
     *template<class T,class U>
     * class A{}
     *
     * template<T>
     * class A<T,int>{}
     */
    return 0;
}