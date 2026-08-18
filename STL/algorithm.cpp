#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>
using namespace std;
template<typename  T>
class Multi
{
public:
    Multi(const T& v):value(v){}
    void operator()(T& elem)const
    {
        elem*=value;
    }
private:
    T value;
};
int main()
{
    int arr[]={5,3,2,1,6,4};
    vector<int> v;
    v.assign(arr,arr+sizeof(arr)/sizeof(int));
    for_each(v.begin(),v.begin(),Multi<int>(2));
    copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
    cout<<endl;
    vector<int>::iterator it=find(v.begin(),v.end(),200);
    if (it!=v.end())
    {
        cout<<"容器中有值为200的元素"<<endl;
    }else
    {
        cout<<"容器中没有值为200的元素"<<endl;
    }
    sort(v.begin(),v.end());
    cout<<"排序之后:"<<endl;
    copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
    cout<<endl;
    int sum=accumulate(v.begin(),v.end(),0);
    cout<<"sum="<<sum<<endl;
    return 0;
}