#include <fstream>
#include <iostream>
using namespace std;
class AbstractException
{
public:
    virtual void printErr()=0;
};
class FileException:public AbstractException
{
public:
    virtual void printErr() override
    {
        cout<<"错误:文件不存在"<<endl;
    }
};
class DivideException:public AbstractException
{
public:
    virtual void printErr() override
    {
        cout<<"错误:除零异常"<<endl;
    }
};
void readFile()
{
    ifstream ifs("log.txt");
    if (!ifs)
    {
        throw FileException();
    }
    ifs.close();
}
void divide()
{
    int num1=100;
    int num2=2;
    if (num2==0)
    {
        throw DivideException();
    }
    int res=num1/num2;
    cout<<"两个数相除结果:"<<res<<endl;
}
int main()
{
    try
    {
        readFile();
        divide();
    }
    catch (FileException& fex)
    {
        fex.printErr();
    }
    catch (DivideException& dex)
    {
        dex.printErr();
    }catch (...)
    {
        cout<<"处理其他异常"<<endl;
    }
    cout<<"程序执行结束"<<endl;
    return 0;
}