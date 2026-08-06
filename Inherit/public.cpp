#include <iostream>
using namespace std;
class Student
{
public:
    void setGrade(string grade)
    {
        this->grade=grade;
    }
    string getGrade()
    {
        return grade;
    }
    void setName(string name)
    {
        this->name=name;
    }
    string getName()
    {
        return name;
    }
protected:
    string grade;
private:
    string name;
};
class Undergraduate:public Student
{
public:
    Undergraduate(string major)
    {
        this->major=major;
    }
    void show()
    {
        cout<<"姓名:"<<getName()<<"  年级:"<<getGrade()<<"  专业:"<<major<<endl;
    }
private:
    string major;
};
int main()
{
    Undergraduate ug("计算机技术");
    ug.setGrade("研一");
    ug.setName("李四");
    ug.show();
    return 0;
}