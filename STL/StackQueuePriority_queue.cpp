#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
class Comp
{
public:
    bool operator()(int x,int y)
    {
        return x>y;
    }
};
template<typename T>
void print(T& q)
{
    while (!q.empty())
    {
        cout<<q.top()<<" ";
        q.pop();
    }
    cout<<endl;
}
int main()
{
    //stack的元素具有先进后出的特点，只能从一端插入删除读取元素
    vector<int> v={1,2,3};
    stack<int,vector<int>> s(v);
    s.push(4);
    s.emplace(5);
    s.pop();
    while (!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    //queue的元素具有先进先出的特点，只能从一端用push插入，从另一端用pop删除；
    list<int> l={1,2,3};
    queue<int,list<int>> q(l);
    q.push(4);
    q.emplace(5);
    q.pop();
    cout<<"第一个元素:"<<q.front()<<endl;
    cout<<"最后一个元素:"<<q.back()<<endl;
    while (!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    //priority_queue中的元素可以按照自定义的方式进行动态排序，插入或删除元素时会动态的调整，以保证元素有序
    priority_queue<int> q1;
    for (int n : {1,4,9,6,7,2,8,3,5})
    {
        q1.push(n);
    }
    print(q1);
    priority_queue<int,vector<int>,greater<int>> q2;
    for (int n : {1,4,9,6,7,2,8,3,5})
    {
        q2.push(n);
    }
    print(q2);
    priority_queue<int,vector<int>,Comp> q3;
    for (int n : {1,4,9,6,7,2,8,3,5})
    {
        q3.push(n);
    }
    print(q3);
    return 0;
}