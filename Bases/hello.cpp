/*
 *#include其实就是一个预处理，意思是将后边这个文件的内容复制到这里
 *<iostream>是输入输出流的头文件
 */
#include <iostream>
//使用标准库的命名空间 std->standard
using namespace std;
//一般来说一个c++项目只有一个main函数
int main(){
    // 没有 using namespace std 时，要这么写：
    std::cout << "hello world" << std::endl;
    // 有了 using namespace std，可以简写成：
    cout<<"hello world"<<endl;
    //返回给操作系统的值，表示“程序正常结束”
    return 0;
}