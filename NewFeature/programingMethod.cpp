#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Animal
{
public:
    //定义了有参构造函数后则编译器不再提供默认构造函数
    /*  = default：“用编译器自动生成的默认版本”（让编译器帮你写函数体）
     *  = delete：“禁止使用这个函数”（告诉编译器：这个函数被删除了，不允许调用）
     */
    //如果你显式声明了特殊函数（默认构造函数、拷贝构造函数、赋值运算符、析构函数），但又想让编译器生成默认版本，就用 = default。
    Animal()=default;
    // Animal(const Animal& animal)=default;
    //= delete 告诉编译器：“这个函数不存在，谁调用谁编译错误”。
    Animal(const string &name)=delete;
    Animal(const Animal& animal)=delete;
private:
    string name;
};
int main()
{
    //auto让编译器根据变量的初始值来自动推断变量的类型，必须有初始值，依靠初始值进行推导
    //decltype：让编译器根据一个表达式来获取它的类型，而不去计算这个表达式的值。
    auto a=10;  //int
    auto b=3.14; //double
    auto c="C++"; //const char*
    //auto 会“剥掉”引用和 const，decltype 会“原样保留”
    int x = 10;
    const int& ref = x;
    auto a1 = ref;           // a 是 int（const 和 & 被剥掉了）
    decltype(ref) b1 = x;    // b 是 const int&（原样保留）
    cout << is_same<decltype(a1), int>::value << endl;       // 1（true）
    cout << is_same<decltype(b1), const int&>::value << endl; // 1（true）

    //nullptr是一个有类型的空指针变量，当使用nullptr给指针赋值时，nullptr可以隐式转换为等号左侧的指针类型，但不能转换为非指针类型
    int *p=nullptr;

    //基于范围的for循环
    vector<int> v={1,2,3,4,5,6};
    for (auto v1 : v)
    {
        cout<<v1<<" ";
    }
    cout<<endl;
    //Lambda 就是“即写即用”的函数，不需要单独定义一个函数名字，直接在代码里写一个临时的函数体。
    /*      [捕获列表](参数列表)->返回值类型{函数体}
     *根据捕获规则，捕获列表有以下五种常用的捕获形式
     *(1)[]:空捕获，表示lambda表达式不捕获任何变量
     *(2)[var]:变量捕获，表示捕获局部变量var。如果捕获多个变量，变量之间用"，"分隔
     *(3)[&var]:引用捕获，表示以引用方式捕获局部变量var
     *(4)[=]:隐式捕获，表示捕获所有的局部变量
     *(5)[&]:隐式引用捕获，表示以引用方式捕获所有的局部变量
     */
    int num=100;
    auto f=[num](int x)->int{return x+num;};
    cout<<f(10)<<endl;
    for_each(v.begin(),v.end(),[](int n){cout<<n<<" ";});
    return 0;
}