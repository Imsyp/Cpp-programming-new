#include <iostream>

int main(void)
{
    char name[100];
    char lang[200];

    std::cout<<"당신의 이름은 무엇입니까?: ";
    std::cin>>name;

    std::cout<<"당신이 가장 좋아하는 프로그래밍 언어는 무엇입니까?: ";
    std::cin>>lang;

    std::cout<<"내 이름은 "<<name<<" 입니다.\n";
    std::cout<<"내가 가장 좋아하는 프로그래밍 언어는 "<<lang<<" 입니다."<<std::endl;

    return 0;
}