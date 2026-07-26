#include <iostream>
using namespace std;
class Person
{
public:
    const string addr;
    Person(const string& addr,const string& name, int age);
    Person(const string& addr,const string& name, int age,const string& favFruit);
    ~Person();
    void myInfor() const;
    void myInfor();
    void place();
private:
    const string name;
    const int age;
    string favFruit;

};

Person::Person(const string& addr,const string& name, int age ):addr(addr),name(name),age(age)
{
    cout<<"初始化const修饰的成员变量"<<endl;
    cout<<"name:"<<this->name<<endl;
    cout<<"age:"<<this->age<<endl;
    cout<<"addr:"<<this->addr<<endl;
}
Person::Person(const string& addr,const string& name, int age,const string& favFruit):addr(addr),name(name),age(age),favFruit(favFruit)
{

}

void Person::myInfor() const
{
    //favFruit="桃子";
    //place();
    cout<<"我叫"<<name<<" 今年"<<age<<"岁 我喜欢吃"<<favFruit<<endl;
}
Person::~Person(){};

void Person::myInfor()
{
    favFruit="桃子";
    cout<<"我叫"<<name<<" 今年"<<age<<"岁 我喜欢吃"<<favFruit<<endl;
    place();
}
void Person::place()
{
    cout<<"我住在"<<addr<<endl;
}

int main()
{
    /*返回值类型  函数名() const;
     *在常成员函数内部，只能访问类的成员变量，而不能改变类的成员变量，而且常成员函数只能调用类的常成员函数，而不能调用类的非常成员函数。
     *类中定义的成员函数若与常成员函数名相同则构成重载，常成员函数只能由const修饰的对象进行访问,const 对象不能调用非const成员函数
     */
    Person a("老北京","abc",18);
    // a.addr="a";  不可修改
    Person p1("老北京","abc",18,"苹果");
    p1.myInfor();
    const Person p2("北京","ABC",20,"橘子");
    p2.myInfor();

    return 0;
}