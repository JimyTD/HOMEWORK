#include "CEmployee.h"
#include<string.h>
CEmployee::CEmployee(char* name)
{
    strcpy(this->name,name);
}

CEmployee::~CEmployee()
{
    //dtor
}


int CEmployee::CalcSalary()
{
    switch(level)
    {
    case 1:
        return 1000;
    case 2:
        return 3000;
    case 3:
        return 8000;
    default:
        return 0;
    }
}

char* CEmployee::GetName()
{
    return name;
}

int CEmployee::GetLevel()
{
  return level;
}

void CEmployee::SetLevel(int newlevel)
{
    level=newlevel;
}

CSales::CSales(char* name):CEmployee(name)
{

}

CSales::~CSales()
{

}

void CSales::SetSaleCount(int nCount)
{
    nSaleCount=nCount;
}

int CSales::CalcSalary()
{
    int nlevel=GetLevel();
    switch(nlevel)
    {
    case 1:
        return 1000+nSaleCount;
    case 2:
        return 3000+nSaleCount;
    case 3:
        return 8000+nSaleCount;
    default:
        return 0;
    }
}
