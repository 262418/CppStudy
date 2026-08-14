#include <iostream>
using namespace std;
template<class T>
class Array
{
public:
    Array(T arr[],int s)
    {
        this->ptr=new T[s];
        this->size=s;
        for (int i = 0; i < size; i++)
        {
            ptr[i]=arr[i];
        }
    }
    void show();
private:
    int size;
    T* ptr;
};
template<typename T> //类模板外定义成员函数
void Array<T>::show()
{
    for (int i=0;i<size;i++)
    {
        cout<<*(ptr+i)<<" ";
    }
    cout<<endl;
}
int main()
{
    char cArr[]={'a','b','c','d','e'};
    Array<char> a1(cArr,5);
    a1.show();
    int iArr[10]={1,2,3,4,5,6};
    Array<int> a2(iArr,10);
    a2.show();
    return 0;
}