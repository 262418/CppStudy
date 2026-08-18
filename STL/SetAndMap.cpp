#include<iostream>
#include<set>
#include<map>
using namespace std;
int main()
{
    //set与multiset都是集合用于存储一组相同数据类型的元素，set只允许存储无重复的一组数据
    set<int,greater<int>> s;
    multiset<char> ms;
    pair<set<int>::iterator,bool> ps;
    //insert插入后会返回一个pair类型的返回值，第一个元素是插入位置的迭代器，第二个元素是是否插入成功的布尔值。
    ps=s.insert(12);
    if (ps.second==true)
    {
        cout<<"插入成功"<<endl;
    }
    s.insert(39);
    s.insert(32);
    s.insert(26);
    ms.insert('a');
    ms.insert('z');
    ms.insert('T');
    ms.insert('u');
    ms.insert('u');
    cout<<"set中的元素"<<endl;
    for (auto i : s)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"multiset中的元素"<<endl;
    for (auto i : ms)
    {
        cout<<i<<" ";
    }
    cout<<"ms中u的个数:"<<ms.count('u')<<endl;
    //map与multimap都是存储的元素对，因此也被理解为关联数组
    map<char,double> m;
    m['a']=1.2;
    m['b']=3.6;
    m['c']=6.4;
    m['d']=0.8;
    m['e']=5.3;
    m['f']=3.6;
    cout<<"Map"<<endl;
    for (auto i : m)
    {
        cout<<i.first<<"->"<<i.second<<endl;
    }
    cout<<"map中key=c的值为:"<<m.at('c')<<endl;
    //因为multimap中含有相同的键，因此无法通过[]来赋值或者访问元素
    multimap<int,string> mp;
    mp.insert(pair<int,string>(1,"Hello"));
    mp.insert(pair<int,string>(1,"China"));
    mp.insert(pair<int,string>(2,"！"));
    cout<<"multimap:"<<endl;
    for (auto i : mp)
    {
        cout<<i.first<<"->"<<i.second<<endl;
    }



    return 0;
}