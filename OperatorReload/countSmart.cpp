#include<iostream>

using namespace std;
class Data
{
public:
    Data(string str):str(str)
    {
        cout<<"Data类构造函数"<<endl;
    }
    ~Data()
    {
        cout<<"Data类析构函数"<<endl;
    }
    void dis()
    {
        cout<<str<<endl;
    }
private:
    string str;
};

class Count
{
public:
    friend class  SmartPtr;
    Count(Data *pdata):pdata(pdata),count(1)
    {
        cout<<"Count类构造函数"<<endl;
    };
    ~Count()
    {
        cout<<"Count类析构函数"<<endl;
        delete pdata;
    }
private:
    Data *pdata;
    int count;
};

class SmartPtr
{
public:
    SmartPtr(Data *pdata):reNum(new Count(pdata))
    {
        cout<<"创建基类对象"<<endl;
    };
    SmartPtr(const SmartPtr& another):reNum(another.reNum)
    {
        ++reNum->count;                     //等价于++(reNum->count)
        cout<<"SmartPtr类复制构造函数"<<endl;
    }
    ~SmartPtr()
    {
        if (--reNum->count==0)
        {
            delete reNum;
            cout<<"SmartPtr类析构函数"<<endl;
        }
    }
    Data* operator->()
    {
        return reNum->pdata;
    }
    Data& operator*()
    {
        return *reNum->pdata;  //等价于*(reNum->pdata)
    }
    int disCount()
    {
        return reNum->count;
    }
private:
    Count *reNum;
};
int main()
{
    Data *pstr1=new Data("I love china");
    SmartPtr pstr2=pstr1;
    (*pstr1).dis();
    SmartPtr pstr3=pstr2;
    pstr2->dis();
    cout<<"使用基类对象的指针数量:"<<pstr2.disCount()<<endl;
    return 0;
}