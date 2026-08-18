#include<iostream>
#include <array>
#include <list>
using namespace std;
template<typename T>
void scanList(list<T> l)
{

    for (typename list<T>::iterator it=l.begin(); it!=l.end(); ++it)
    {
        cout<<*it<<" ";
    }
}
int main()
{   //array创建后大小不可改变,且不可插入删除元素
    array<int,5> a={1,2,3,4,5};
    array<int,5> a1={2,3,4,5,6};
    a.swap(a1);     //交换a和a1的元素
    for (auto c : a1)
    {
        cout<<c<<" ";
    }
    cout<<endl;

    //list容器以双向链表实现所以无法通过索引的方式访问元素
    list<int> l;
    for (int i=0;i<10;i++){
        l.push_back(i+1);
    }
    cout<<"输出list容器中的元素"<<endl;
    scanList(l);
    cout<<endl;
    l.pop_back();
    l.push_front(5);
    scanList(l);
    cout<<endl;
    l.remove(5);
    scanList(l);
    return 0;
}