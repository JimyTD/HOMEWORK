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

int CRand::GetRandomNumber2()
{
    srand(GetTickCount()+2378);
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
//srand()��������һ���Ե�ǰʱ�俪ʼ���������.Ӧ�÷���for��ѭ�����ǰ�� ��ȻҪ�ܳ�ʱ��ȴ�
Random=rand()%MAX;//MAXΪ���ֵ���������Ϊ0~MAX-1
return Random;
}