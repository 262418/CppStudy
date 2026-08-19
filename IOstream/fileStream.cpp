#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    /*ios::in:以只读模式打开文件，若文件不存在，则发生错误
     *ios::out:以只写模式打开文件，写入时覆盖写入；若文件不存在，则创建一个新文件
     *ios::app:以追加模式打开文件，若文件不存在，则创建一个新文件
     *ios::ate:打开一个已存在文件，并将文件位置指针移动到文件末尾
     *ios::trunc:打开一个文件，将文件内容删除。若文件不存在，则创建一个新文件
     *ios::binary:以二进制方式打开文件
     */
    ofstream ofs;
    ofs.open("..\\IOstream\\text.txt",ios::out);
    if (!ofs){
        cout<<"写文件时,文件打开失败"<<endl;
        exit(0);
    }
    // cout<<"请输入要写入文件的数据:"<<endl;
    //手动输入要输入的内容
    // char str[1024]={0};
    // cin>>str;
    // ofs<<str;
    cout<<"将26个字母写入文件:"<<endl;
    for (int i=0;i<26;i++)
    {
        ofs.put('a'+i);
    }
    cout<<"文件写入成功"<<endl;
    ofs.close();

    ifstream ifs;
    ifs.open("..\\IOstream\\text.txt",ios::in);
    if (!ifs){
        cout<<"文件打开失败"<<endl;
        exit(0);
    }else{
        cout<<"文件打开成功"<<endl;
    }
    cout<<"文件读取成功,内容如下:"<<endl;
    // char buf[1024]={0};
    // ifs>>buf;
    // cout<<buf<<endl;
    char ch;
    ifs.get(ch);
    while (!ifs.eof())
    {
        cout<<ch<<" ";
        ifs.get(ch);
    }
    ifs.close();
    /*eof():用于检测文件是否到达末尾。在读文件时，如果文件到达末尾，eof会返回true(但是此次循环还会进行，可以理解为是在循环体中变为true)
     *bad():用于检测文件在读写过程中是否出错。如果文件读写出错，bad会返回true
     *fail():也用于检测文件在读写过程中是否出错。但是比bad的检错范围更广泛，文件到达末尾或读写过程没有达到预期条件，例如:要读取整数却获得了一个字母
     *good():用于检测文件流状态和文件读写过程是否正常。如果文件流状态和文件读写过程没有错误就返回true
     *clear():用于清除文件流的错误状态，即重置文件流的状态标志位。
     */
    return 0;
}