
#include<time.h>
#define MAX 10000
int GetRandomNumber()
{
    srand(GetTickCount());
    int number = rand();
    return number;
}

int GetRandomNumber2()
{
    srand(GetTickCount()+2378);
    int number = rand();
    return number;
}

int GetRandomNumber3()
{
int Random;
srand( (unsigned)time( NULL ) );//srand()��������һ���Ե�ǰʱ�俪ʼ���������.Ӧ�÷���for��ѭ�����ǰ�� ��ȻҪ�ܳ�ʱ��ȴ�
Random=rand()%MAX;//MAXΪ���ֵ���������Ϊ0~MAX-1
return Random;
}
