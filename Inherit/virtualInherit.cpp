#include <iostream>
using namespace std;
class Furniture
{
public:
    Furniture(string wood)
    {
        this->wood=wood;
    }
protected:
    string wood;
};

class Sofa:virtual public Furniture
{
public:
    Sofa(float length,string wood):Furniture(wood)
    {
        this->length=length;
    }
protected:
    float length;
};

class Bed:virtual public Furniture
{
public:
    Bed(float width,string wood):Furniture(wood)
    {
        this->width=width;
    }
protected:
    float width;
};

class SofaBed:public Sofa,public Bed
{
public:
    SofaBed(float length,string wood1,float width,string wood2):Sofa(length,wood1),Bed(width,wood2),Furniture(wood1){}
    void getSize(){
        cout<<"沙发床长:"<<length<<"米"<<endl;
        cout<<"沙发床宽:"<<width<<"米"<<endl;
        cout<<"沙发材质为:"<<wood<<endl;
    }
};
int main()
{
    SofaBed sb(1.8,"梨木",1.5,"檀木");
    sb.getSize();
    return 0;
}
