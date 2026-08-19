#include <fstream>
#include <iostream>
using namespace std;
struct Student
{
    char name[20];
    int age;
    char sex;
};
int main()
{
    //由于write()与read()的第一个参数都是char*，所以要将Student结构体变量的地址转换成char*类型
    Student student[3];
    cout<<"请输入三个学生的信息:\n(姓名,年龄,性别)"<<endl;
    for (int i = 0; i < 3; i++)
    {
        cin>>student[i].name>>student[i].age>>student[i].sex;
    }
    ofstream ofs("..\\IOstream\\student.dat",ios::out|ios_base::binary);
    if (!ofs)
    {
        cerr<<"写入时，文件打开失败"<<endl;
        exit(0);
    }
    for (int i=0;i<3;i++)
    {
        ofs.write(reinterpret_cast<char*>(&student[i]),sizeof(student[i]));
        ofs.flush();
    }
    ofs.close();
    cout<<"写入成功"<<endl<<"读取文件:"<<endl;
    ifstream ifs("..\\IOstream\\student.dat",ios::in|ios_base::binary);
    if (!ifs)
    {
        cerr<<"文件打开失败"<<endl;
        exit(0);
    }
    Student student1[3];
    for (int i=0;i<3;i++)
    {
        ifs.read(reinterpret_cast<char*>(&student1[i]),sizeof(student1[i]));
        cout<<student1[i].name<<" "<<student1[i].age<<" "<<student1[i].sex<<endl;
    }
    ifs.close();

    return 0;
}