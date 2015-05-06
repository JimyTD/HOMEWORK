#include<iostream>
#include<stdlib.h>
using namespace std;
int hanoi(int number,char clfrom,char clto,char clbuffer);
int sum;
int main(int argc, char* argv[])
{
	char a='a',b='b',c='c';
	int n=8;
	hanoi(n,a,b,c);
	cout<<"The step is   "<<sum;
	system("pause");
	return 0;
}


int hanoi(int number,char clfrom,char clto,char clbuffer)//n means current hanoi rings.
{
	if(0==number)return 0;
	hanoi(number-1,clfrom,clbuffer,clto);//buffer move
	cout << clfrom  <<"->"<< clto<<endl ;//bottom move
	hanoi(number-1,clbuffer,clto,clfrom);//objecting move
	sum++;
	return 0;
}
