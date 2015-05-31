
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
srand( (unsigned)time( NULL ) );//srand()函数产生一个以当前时间开始的随机种子.应该放在for等循环语句前面 不然要很长时间等待
Random=rand()%MAX;//MAX为最大值，其随机域为0~MAX-1
return Random;
}
