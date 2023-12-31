#include <iostream>
#include <cstring>
using namespace std;

class SoSimple
{
private:
    int num;
public:
    SoSimple(int n) : num(n)
    {
        cout<<"num = "<<num<<", ";
        cout<<"address = "<<this<<endl;
    }

    void ShowSimpleData()
    {
        cout<<num<<endl;
    }

    SoSimple * GetThisPointer()
    {
        return this;
    }
};

int main(void)
{
    SoSimple sim1(100);
    SoSimple * ptr1 = sim1.GetThisPointer(); // sim1 객체의 주소값 저장
    cout<<ptr1<<", ";
    ptr1 ->ShowSimpleData(); // ptr1이 가리키는 객체의 ShowSimpleData 함수를 호출

    SoSimple sim2(200);
    SoSimple * ptr2 = sim2.GetThisPointer(); // sim2 객체의 주소값 저장
    cout<<ptr2<<", ";
    ptr2 ->ShowSimpleData(); // ptr2이 가리키는 객체의 ShowSimpleData 함수를 호출
    return 0;
}

