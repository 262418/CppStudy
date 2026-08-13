#include <iostream>
using namespace std;
/* override检查派生类中函数是否在重写基类虚函数
 * final修饰类或虚函数，使用final修饰类时表示该类不可继承
 */
class Animal
{
public:
    virtual void speak()
    {
        cout<<"动物叫声"<<endl;
    }
};
class Cat:public Animal
{
public:
    virtual void speak()
    {
        cout<<"猫叫"<<endl;
    }
};
class Dog:public Animal
{
public:
    virtual void speak()
    {
        cout<<"狗叫"<<endl;
    }
};
int main()
{
    /*多态的实现需要满足的3个条件
     *1.基类声明虚函数
     *2.派生类重写基类的虚函数
     *3.将基类指针指向派生类对象，通过基类指针访问派生类
     */
    /*声明虚函数时，有以下三点需要注意
     *1.构造函数不能声明为虚函数，但析构函数可以声明为虚函数
     *2.虚函数不能是静态成员函数
     *3.友元函数不能声明为虚函数，但虚函数可以作为另一个类的友元函数
     */
    Cat cat;
    Animal* a1=&cat;
    a1->speak();
    Dog dog;
    Animal* a2=&dog;
    a2->speak();

    return 0;
}