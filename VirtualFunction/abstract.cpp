#include <iostream>
using namespace std;
class Animal
{
public:
    virtual void speak()=0;
    virtual void eat()=0;
    virtual ~Animal()
    {
        cout<<"调用Animal析构函数"<<endl;
    }
};
class Cat:public Animal
{
public:
    void speak()
    {
        cout<<"小猫喵喵叫"<<endl;
    }
    void eat()
    {
        cout<<"小猫吃鱼"<<endl;
    }
    ~Cat()
    {
        cout<<"调用Cat析构函数"<<endl;
    }
};
class Rabbit:public Animal
{
public:
    void speak()
    {
        cout<<"兔子咕咕叫"<<endl;
    }
    void eat()
    {
        cout<<"兔子吃白菜"<<endl;
    }
    ~Rabbit()
    {
        cout<<"调用Rabbit析构函数"<<endl;
    }
};
int main()
{
    Animal* a1=new Cat;
    a1->speak();
    a1->eat();
    delete a1;
    Animal* a2=new Rabbit;
    a2->speak();
    a2->eat();
    delete a2;
    return 0;
}