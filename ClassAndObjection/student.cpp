#include<iostream>
using namespace std;
/*public(公有类型)可以被所属类的成员函数，类对象，派生类对象，友元函数和友元类访问
 *protect(保护类型)可以被所属类的成员函数，派生类对象，友元函数和友元类访问
 *private(私有类型)只能被所属类的成员函数，友元函数和友元类访问
 */
class student
{
public:
    void study();
    void exam();
    string name;
    int age;
};
void student::study()
{
    cout<<"学习c++"<<endl;
}

void student::exam()
{
    cout<<"c++考试100分"<<endl;
}

int main()
{
    student s;              //创建student类的对象
    s.name="abc";
    s.age=18;
    cout<<s.name<<"-"<<s.age<<"岁"<<endl;
    s.study();
    s.exam();
    return 0;
}
