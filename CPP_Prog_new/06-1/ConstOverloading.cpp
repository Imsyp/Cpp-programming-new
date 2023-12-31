#include <iostream>
using namespace std;

class SoSimple
{
private:
    int num;
public:
    SoSimple(int n) : num(n)
    { }
    SoSimple& AddNum(int n)
    {
        num += n;
        return *this;
    }
    void SimpleFunc()
    {
        cout<<"SimpleFunc : "<<num<<endl;
    }
    void SimpleFunc() const
    {
        cout<<"const SimpleFunc : "<<num<<endl;
    }    
};

void YourFunc(const SoSimple &obj) // const 참조자를 인자로 받음 
{
    obj.SimpleFunc(); // obj는 const 참조자이기 때문에 const 멤버함수가 호출된다.
}

int main(void)
{
    SoSimple obj1(2);
    const SoSimple obj2(7);

    obj1.SimpleFunc();
    obj2.SimpleFunc();

    YourFunc(obj1);
    YourFunc(obj2);

    return 0;
}