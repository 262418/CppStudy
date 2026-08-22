#include <iostream>
#include <memory>
using namespace std;
void func(weak_ptr<string>& pw)
{
    //lock()用于返回一个shared_ptr对象，如果weak_ptr指向的new对象没有shared_ptr引用，则返回nullptr
    shared_ptr<string> ps=pw.lock();
    if (ps!=nullptr)
    {
        cout<<"编程语言是:"<<*ps<<endl;
    }else
    {
        cout<<"shared_ptr智能指针失效"<<endl;
    }

}
int main()
{
    //智能指针是 C++ 中自动管理内存的指针，核心作用是帮你自动释放内存，避免内存泄漏和野指针
    /*(1)unique_ptr	独占	        不能拷贝	                明确只有一个人拥有
     *(2)shared_ptr	共享	        能拷贝（引用计数）	        多个人共同拥有
     *(3)weak_ptr	    弱引用	    能拷贝（不影响计数）	    配合 shared_ptr，打破循环引用
     */
    unique_ptr<string> ps(new string("c++"));
    unique_ptr<string> pt=std::move(ps);     //move()将new对象指针的所有权转给pt；

    shared_ptr<string> s1(new string("c++"));
    shared_ptr<string> s2=s1;
    shared_ptr<string> s3=s1;
    cout<<"s1:"<<s1.get()<<endl;        //get()函数:用于获取shared_ptr管理的new对象指针
    cout<<"s2:"<<s2.get()<<endl;
    cout<<"s3:"<<s3.get()<<endl;
    cout<<s1.use_count()<<" ";          //use_count()用于获取new对象的引用次数
    cout<<s2.use_count()<<" ";
    cout<<s2.use_count()<<endl;;
    s1.reset();                         //reset()用于取消shared_ptr智能指针对象对new对象的引用
    cout<<s1.use_count()<<" ";
    cout<<s2.use_count()<<" ";
    cout<<s2.use_count()<<endl;;
    cout<<"s1:"<<s1.get()<<endl;
    cout<<"s2:"<<s2.get()<<endl;
    cout<<"s3:"<<s3.get()<<endl;

    shared_ptr<string> pt1(new string("C++"));
    shared_ptr<string> pt2=pt1;
    weak_ptr<string> pw=pt1;
    func(pw);
    *pt1="Java";
    pt1.reset();
    func(pw);
    pt2.reset();
    func(pw);       //此时对new的shared_ptr引用为0；
    return 0;
}
