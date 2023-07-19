#include <iostream>
#include <cstring>
using namespace std;

class Employee
{
private:
    char name[100];
public:
    Employee(char * name)
    {
        strcpy(this->name, name);
    }
    void ShowYourName() const
    {
        cout<<"name : "<<name<<endl;
    }
    virtual int GetPay() const          //가상함수 선언
    { 
        return 0;    
    }
    virtual void ShowSalaryInfo() const //가상함수 선언
    { }
};

class TemporaryWorker : public Employee
{
private:
    int workTime;     
    int payPerHour;     
public:
    TemporaryWorker(char * name, int pay)
        : Employee(name), workTime(0), payPerHour(pay)
    { }
    void AddWorkTime(int time) 
    {
        workTime += time;
    }
    int GetPay() const         
    {
        return workTime*payPerHour;
    }
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout<<"salary : "<<GetPay()<<endl<<endl;
    }
};

class PermanentWorker : public Employee
{
private:
    int salary; 
public:
    PermanentWorker(char * name, int money)
        : Employee(name),salary(money)
    { }
    int GetPay() const
    {
        return salary;
    }
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout<<"salary : "<<GetPay()<<endl<<endl;
    }
};

class SalesWorker : public PermanentWorker
{
private:
    int salesResult;     
    double bonusRatio;   
public:
    SalesWorker(char * name, int money, double ratio)
        : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
    { }
    void AddSalesResult(int value)
    {
        salesResult += value;
    }
    int GetPay() const
    {
        return PermanentWorker::GetPay()    
                    +(int)(salesResult*bonusRatio);
    }
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout<<"salary : "<<GetPay()<<endl<<endl;    
    }
};

class EmployeeHandler
{
private:
    Employee* empList[50];
    int empNum;
public:
    EmployeeHandler() : empNum(0)
    { }
    void AddEmployee(Employee* emp)
    {
        empList[empNum++]=emp;
    }
    void ShowAllSalaryInfo() const
    {
        for(int i=0; i<empNum; i++)
            empList[i]->ShowSalaryInfo(); 
    }
    void ShowTotalSalaryInfo() const
    {
        int sum = 0;
        for(int i=0; i<empNum; i++)
            sum += empList[i]->GetPay();  
        cout<<"salary sum : "<<sum<<endl;      
    }
    ~EmployeeHandler()
    {
        for(int i=0; i<empNum; i++)
            delete empList[i];
    }
};

int main(void)
{
    // 직원 관리를 목적으로 설계된 컨트롤 클래스의 객체 생성
    EmployeeHandler handler;

    // 정규직 등록
    handler.AddEmployee(new PermanentWorker("KIM", 1000));
    handler.AddEmployee(new PermanentWorker("LEE", 1500));

    // 임시직 등록
    TemporaryWorker * alba = new TemporaryWorker("Jung", 700);
    alba -> AddWorkTime(5); 
    handler.AddEmployee(alba);  
    // AddEmployee는 매개변수를 Employee형 포인터 변수로 선언하여 받지만, 가상함수이기 때문에 포인터가 가리키는 객체의 자료형에 영향을 받음.           

    // 영업직 등록
    SalesWorker * seller = new SalesWorker("Hong", 1000, 0.1);
    seller->AddSalesResult(7000); 
    handler.AddEmployee(seller);
    // AddEmployee는 매개변수를 Employee형 포인터 변수로 선언하여 받지만, 가상함수이기 때문에 포인터가 가리키는 객체의 자료형에 영향을 받음.

    // 이번 달에 지불해야 할 급여의 정보
    handler.ShowAllSalaryInfo();

    // 이번 달에 지불해야 할 급여의 총합
    handler.ShowTotalSalaryInfo();

    return 0;
}