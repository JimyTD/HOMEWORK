#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}


struct data
{
	int a;///数据区
	data* pNext;
	data* pLast;
};




class CChain
{
    public:
	data* pHead;
    int datalength;
	data* CreateData();
	int DeleteData(data* Data);
	~CChain();
};



data* CChain::CreateData()
{
	data* pEnd;
	data* temp;
	if(pHead==NULL)
	{
		pHead= new data;
        (*pHead).pNext=NULL;
		(*pHead).pLast=NULL;
		datalength++;
		return pHead;
	}
	else
		pEnd=pHead;
	while((*pEnd).pNext!=NULL)
		pEnd=(*pEnd).pNext;
	(*pEnd).pNext= new data;
	temp=(*pEnd).pNext;
	(*temp).pNext=NULL;
	(*temp).pLast=pEnd;
	datalength++;
	return temp;//返回新的元素以进行状态设置。
}

int CChain::DeleteData(data* Data)
{
	data* temp;
		//如果是头
	if((*Data).pLast==NULL)
	{
		if(datalength==1)
			pHead=NULL;//只有一个元素。
		else	{
			pHead=(*Data).pNext;
			(*pHead).pLast=NULL;
		}
		delete Data;
		datalength--;
		return 1;
	}

		temp=(*Data).pLast;
		(*temp).pNext=(*Data).pNext;//下一个链表元素接好
		temp=(*Data).pNext;
		if(temp!=NULL)
		(*temp).pLast=(*Data).pLast;
		delete Data;
		datalength--;
		return 1;
}



CChain::~CChain()
{
	data* temp;
	if(pHead!=NULL)
	{
		temp=pHead;
		while((*temp).pNext!=NULL)
		{
			temp=(*temp).pNext;
			delete (*temp).pLast;
		}
		delete temp;
	}
}
