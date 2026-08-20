#include <iostream>
using namespace std;
class Animal
{
public:
    virtual void speak()
    {
        cout<<"¶¯Îï½ÐÉù"<<endl;
    }
};
class Cat:public Animal
{
public:
    virtual void speak() override
    {
        cout<<"Ð¡Ã¨ß÷ß÷½Ð"<<endl;
    }
};

int main()
{
    Animal animal;
    Animal& ref=animal;
    ref.speak();
    try
    {
        Cat& cat=dynamic_cast<Cat&>(ref);
        cat.speak();
    }
    catch (bad_cast& ex)
    {
        cout<<ex.what()<<endl;
    }
    return 0;
}