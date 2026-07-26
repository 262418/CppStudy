#include<iostream>
using namespace std;
class student
{
public:
    void study();
    void exam();
    void setName(const string& name);
    void setAge(int age);
    string getName();
    int getAge();
private:
    string name;
    int age=0;
};
void student::study()
{
    cout<<"学习c++"<<endl;
}
void student::exam()
{
    cout<<"c++考试100分"<<endl;
}
void student::setName(const string& name)
{
    this->name=name;
}
void student::setAge(int age)
{
    if (age<0||age>100)
    {
        cout<<"年龄输入错误"<<endl;
        this->age=0;
    }else{
        this->age=age;
    }
}
string student::getName()
{
    return name;
}
int student::getAge()
{
    return age;
}
int main()
{
    student s;              //创建student类的对象
    s.setName("abc");
    s.setAge(-1);
    cout<<s.getName()<<"-"<<s.getAge()<<"岁"<<endl;
    s.study();
    s.exam();
    student s1;              //创建student类的对象
    s1.setName("ABC");
    s1.setAge(18);
    cout<<s1.getName()<<"-"<<s1.getAge()<<"岁"<<endl;
    s1.study();
    s1.exam();
    return 0;
}
