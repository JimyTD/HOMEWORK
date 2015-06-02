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
//srand()函数产生一个以当前时间开始的随机种子.应该放在for等循环语句前面 不然要很长时间等待
Random=rand()%MAX;//MAX为最大值，其随机域为0~MAX-1
return Random;
}
