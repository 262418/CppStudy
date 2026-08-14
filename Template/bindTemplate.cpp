#include <iostream>
using namespace std;
template<class T>
void func();
template<class T>
void show(T& t);
template<class U>
class A
{
    U item;
    static int count;
public:
    A(const U& t):item(t)
    {
        count++;
    }
    ~A()
    {
        count--;
    }
    friend void func<U>();
    friend void show<>(A<U>& a);
};
template<typename  T>
int A<T>::count=0;
template<class T>
void func()
{
    cout<<"template size:"<<sizeof(A<T>)<<";";
    cout<<"template func():"<<A<T>::count<<endl;
}
template<class T>
void show(T& t)
{
    cout<<t.item<<endl;
}

int main()
{
    /*约束模板友元函数是将一个函数模板声明为类的友元函数。函数模板的实例化类型取决于类模板被实例化时的类型
     *类模板实例化时会产生与之匹配的具体化友元函数
     */
    func<int>();
    A<int> a(10);
    A<int> b(20);
    A<double> c(1.2);
    show(a);
    show(b);
    show(c);
    cout<<"func<int>output:\n";
    func<int>();
    cout<<"func<double>()output:\n";
    func<double>();
    return 0;
}