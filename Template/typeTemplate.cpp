#include <iostream>
using namespace std;
template<typename T,unsigned len>
class Array
{
public:
    T& operator[](unsigned i)
    {
        if (i>=len)
        {
            cout<<"数组越界"<<endl;
        }else
        {
            return arr[i];
        }
    }
private:
    T arr[len];
};
int main()
{
    //由class或者typename标记的参数称为类型参数
    /*使用非类型参数时，有以下几点要注意
     *1.调用非类型参数的实参必须是常量表达式，即必须能在编译时计算出结果
     *2.任何局部对象、局部变量的地址都不是常量表达式，不能用作非类型的实参，全局指针类型、全局变量也不是常量表达式，也不能用作非类型的实参
     *3.sizeof()表达式结果是一个常量表达式，可以用作非类型的实参
     *4.非类型参数一般不用于函数模板
     */
    //模板类型参数就是模板的参数为另一个模板
    Array<char,5> arr1;
    Array<int,10> arr2;
    arr1[0]='A';
    cout<<arr1[0]<<endl;
    for (int i = 0; i < 10; ++i)
    {
        arr2[i]=i+1;
        cout<<arr2[i]<<" ";
    }
    return 0;
}