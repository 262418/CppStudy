#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    //c++文件流类提供了设置文件位置指针的函数，ifstream提供了tellg()与seekg(),osftream提供了tellp()与seekp()，其含义与用法相同
    ofstream ofs("..\\IOstream\\random.dat",ios::out|ios::binary);
    if (!ofs)
    {
        cout<<"文件打开失败"<<endl;
        exit(0);
    }
    cout<<"文件打开时，文件指针位置:"<<ofs.tellp()<<endl; //tellg()和tellp()函数用于返回文件位置的指针
    cout<<"请输入数据:"<<endl;
    char buf[1024]={0};
    cin.getline(buf,1024,'/');
    ofs.write(buf,30);
    cout<<"写入完成后，文件指针位置:"<<ofs.tellp()<<endl;
    /*seekp()和seekq()用于设置文件位置指针的位置
     *1.第一种重载形式有一个参数streampos,表示文件位置指针从文件开头移动streampos长度的距离
     *2.第二种重载形式有两个参数，第一个参数streamoff表示文件位置指针的移动距离，
     *第二个参数iOS::seek_dir表示参照位置,以下三个取值:
     *(1)ios::beg=0,表示从文件开头开始移动文件位置指针
     *(2)ios::cur=1,表示从当前位置开始移动文件位置指针
     *(3)ios::end=2,表示从文件结尾开始移动文件位置指针
     */
    ofs.seekp(-10,ios::end);
    cout<<"移动之后，文件位置指针:"<<ofs.tellp()<<endl;
    return 0;
}