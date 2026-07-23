#include <iostream>
using namespace std;
int main()
{
    /*static_cast<>是最常用的类型转换运算符，主要执行非多态的转换
     *1.基本数据类型之间的转换
     *2.将任何类型转换为void类型
     *3.把空指针转换成目标类型的指针
     *4.用于类层次结构中积基类和派生类之间指针或引用的转换，
     *向上转换(派生类转换为基类)是安全的，向下转换没有动态类型的检查，是不安全的
     */
    int a=1;
    double b=3.14;
    a=static_cast<double>(b);       //将double类型转换成int类型
    b=static_cast<int>(a);          //将int类型转换成double类型
    int *q1=nullptr;
    void *p1=nullptr;
    q1=p1;                            //将无类型指针转换成int类型指针不合法
    p1=q1;                            //int类型转换成无类型可以说是向上转换，合法
    q1=static_cast<int*>(p1);         //将无类型指针转换成int类型指针
    /*reininterpret_cast<>通常为操作数的位模式提供较低层的重新解释
     *例如：将int类型的转化成double类型的数据，仅仅将比特位复制过去，不做类型转换也不进行安全检查
     *reininterpret_cast<>要转换的类型必须是指针，引用或算数类型
     */
    char c='a';
    int d=reinterpret_cast<int&>(c);
    int *p2=nullptr;
    double *q2=nullptr;
    p2=q2;                                  //c语言可以，c++不可以
    q2=p2;                                  //c语言可以，c++不可以
    p2=static_cast<int>(q2);                //static_cast无法转换
    q2=static_cast<double>(p2);                //static_cast无法转换
    p2=reinterpret_cast<int*>(q2);
    q2=reinterpret_cast<double*>(p2);
    /*const_cast<>用于移除const对象的引用或指针具有的常量性质
     *可以去除const对引用和指针的限定
     */
    int num=100;
    const int * p3=&num;
    //将常量指针转换为普通类型指针，去除const属性
    int *p4=const_cast<int *>(p3);
    *p4=200;
    int e=100;
    const int &re=e;
    //将常量引用转换为普通类型引用，去除const属性
    const_cast<int&>(re)=200;
    /*dynamic_cast<>用于运行时检查类型转换是否安全，主要应用于类层次间的向上转换和向下转换，以及类之间的交叉转换
     *与static_cast相比，dynamic_cast<>能在运行时检查类型转换是否安全。当向下转换时，如果基类指针或引用指向
     *派生类对象，会返回转换后类型的指针，这是安全的，但如果基类指针或引用没有指向派生类对象，则转换是不安全的，转换失败
     *就返回null
     */
    return 0;
}