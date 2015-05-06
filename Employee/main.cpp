#include <iostream>
#include"CEmployee.h"
using namespace std;

int main()
{
    CEmployee a("HHZZY");
    CSales b("NICK");
    a.SetLevel(3);
    cout<<a.GetName()<<"   "<<a.CalcSalary()<<endl;
    b.SetLevel(2);
    b.SetSaleCount(500);
    cout<<b.GetName()<<"   "<<b.CalcSalary()<<endl;
    return 0;
}

