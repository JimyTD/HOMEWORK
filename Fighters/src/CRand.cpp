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

Random=rand()%MAX;//MAXΪ���ֵ���������Ϊ0~MAX-1
return Random;
}
