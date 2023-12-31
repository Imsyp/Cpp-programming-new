#include <iostream>
using namespace std;

class FruitSeller
{
    int APPLE_PRICE; 
    int numOfApples;
    int myMoney;

public:
	FruitSeller(int price, int num, int money) // 생성자 정의
    {
        APPLE_PRICE = price;
        numOfApples = num;
        myMoney = money;
    }

    int SalesApples(int money) 
    {
        int num = money/1000; 
        numOfApples -= num; 
        myMoney += money; 
        return num; 
    }
    
    void ShowSalesResult()
    {
        cout<<"남은 사과 : "<<numOfApples<<endl;
        cout<<"판매 수익 : "<<myMoney<<endl;
    }
};

class FruitBuyer
{
    int myMoney; 
    int numOfApples;  

public:
    FruitBuyer(int money) // 생성자 정의
    {
        myMoney = money;
        numOfApples = 0;
    }

    void BuyApples(FruitSeller &seller, int money) 
    {
        numOfApples += seller.SalesApples(money);
        myMoney -= money;
    }
    void ShowBuyResult()
    {
        cout<<"현재 잔액 : "<<myMoney<<endl;
        cout<<"사과 개수 : "<<numOfApples<<endl;
    }
};

int main(void)
{
    FruitSeller seller(1000, 20, 0); // 생성자 호출
    FruitBuyer buyer(5000); // 생성자 호출
    buyer.BuyApples(seller, 2000);

    cout<<"과일 판매자의 현황"<<endl;
    seller.ShowSalesResult();
    cout<<"과일 구매자의 현황"<<endl;
    buyer.ShowBuyResult();

    return 0;
}