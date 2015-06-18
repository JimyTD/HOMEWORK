#include "CRand.h"
#include<windows.h>
#include<time.h>
#define MAX 10000
CRand::CRand()
{
    GetTickCount();
    //ctor
}

CRand::~CRand()
{
    //dtor
}

int CRand::GetRandomNumber()
{

    int number = rand();
    return number;
}



void CRand::Prepare()
{
  srand(GetTickCount());
}
int CRand::GetRandomNumber3()
{
int Random;

Random=rand()%MAX;//MAX为最大值，其随机域为0~MAX-1
return Random;
}
