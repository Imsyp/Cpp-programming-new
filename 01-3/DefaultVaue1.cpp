#include <iostream>

int Adder(int num1=1, int num2=2) //Adder의 매개변수 디폴트값 설정
{
    return num1+num2;
}

int main(void)
{
    std::cout<<Adder()<<std::endl;
    std::cout<<Adder(3)<<std::endl;
    std::cout<<Adder(3,5)<<std::endl;

    return 0;
}