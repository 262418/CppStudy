#include <cstring>
#include <iostream>
using namespace std;
class Sheep
{
private:
    string name;
    string color;
    char* home;
public:
    Sheep(const string& name,const string& color,const char* home);
    Sheep(const Sheep& sheep);
    void show();
    ~Sheep();
};
Sheep::Sheep(const string &name,const string &color,const char* home)
{
    cout<<"调用构造函数"<<endl;
    this->name=name;
    this->color=color;
    this->home=new char[20];
    int len=strlen(this->home)+1;
    memset(this->home,0,len);
    strcpy(this->home,home);
}
//浅拷贝：home指针只是简单的赋值,但是在析构时堆内存空间被释放了两次，被称为重析构;
// Sheep::Sheep(const Sheep& sheep)
// {
//     cout<<"调用拷贝构造函数"<<endl;
//     name=sheep.name;
//     color=sheep.color;
//     home=sheep.home;
// }
//深拷贝：在拷贝构造函数中完成更深层次的复制，当类中有指针成员时，深拷贝可以为新对象的指针分配一块内存空间，将数据复制到新空间
Sheep::Sheep(const Sheep& sheep)
{
    cout<<"调用拷贝构造函数"<<endl;
    name=sheep.name;
    color=sheep.color;
    //完成深拷贝
    int len=strlen(sheep.home)+1; //+1是因为strlen返回的是字符的个数但是在string类型的结尾还有一个\0
    this->home=new char[len];
    strcpy(this->home,sheep.home);
}
void Sheep::show()
{
    cout<<name<<" "<<color<<" "<<home<<endl;
}

Sheep::~Sheep()
{
    cout<<"调用析构函数"<<endl;
    delete[] home;
}

int main()
{
    Sheep sheepA("猪","粉色","北京");
    cout<<"SheepA:";
    sheepA.show();
    Sheep sheepB(sheepA);
    cout<<"SheepB:";
    sheepB.show();
    return 0;
}