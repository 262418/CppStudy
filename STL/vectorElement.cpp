#include<iostream>
#include <vector>
using namespace std;
//范围for循环遍历
void scanVector(const vector<int> &vector)
{
    for (const auto&v:vector)
    {
        cout<<v<<" ";
    }
}
//迭代器遍历
void scanIterator(const vector<int> &v)
{
    for (vector<int>::const_iterator pos=v.begin();pos!=v.end();++pos)
    {
        cout<<*pos<<" ";
    }
    cout<<endl;
    for (vector<int>::const_reverse_iterator pos_r=v.rbegin();pos_r!=v.rend();++pos_r)
    {
        cout<<*pos_r<<" ";
    }
}
int main()
{
    //vector是顺序容器，在内存中是一块连续的内存，当插入或删除某个元素，迭代器可能会失效
    vector<int> v1={1,2,3,4,5};
    vector<int> v2;
    //assign函数初始化容器的两种方式
    cout<<"assign第一种初始化后:"<<endl;
    v2.assign(3,5);
    scanVector(v2);
    cout<<endl;
    cout<<"assign第二种初始化后:"<<endl;
    v2.assign(v1.begin(),v1.begin()+4);
    v2.push_back(6);
    v2.push_back(6);
    scanVector(v2);
    cout<<endl;
    scanIterator(v2);
    cout<<endl;
    cout<<"insert插入两个数据后:"<<endl;
    v2.insert(v2.begin(),20);
    v2.insert(v2.begin(),30);
    scanVector(v2);
    cout<<endl;
    cout<<"在erase删除后"<<endl;
    v2.erase(v2.begin(),v2.begin()+4);
    scanVector(v2);
    return 0;
}