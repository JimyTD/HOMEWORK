#include<stdio.h>
#include<stdlib.h>
#include<string>
////////////class
struct PCdata
{
	char name[10];
	int amount;
};





class PCmanager
{
private:
	PCdata data[10];
    
public:
	PCmanager();
	~PCmanager();
    int ChangeData(PCdata change);
	void display();
};



/////////////////main//////////////////
int main()
{
	int flag;
	PCdata newdata;
	PCmanager mydata;
	do
	{
		printf("Welcome! Please input the name of PC\n");
		scanf("%s",newdata.name);
		printf("\n");
		printf("Please input changing number\n");
		scanf("%d",&newdata.amount);
		mydata.ChangeData(newdata);
		printf("\n");
		mydata.display();
		printf("Anymore Operations?1 or 0\n");
		scanf("%d",&flag);
	}while(flag==1);
		return 0;
}



///////////////////////////////
PCmanager::~PCmanager()
{
}

PCmanager::PCmanager(void)
{
	for(int i=0;i<10;i++)
	{
		data[i].amount=0;
		strcpy(data[i].name,"0");
	}
}



void PCmanager::display()
{
	for(int i=0;i<10;i++)
	{
		if(strcmp("0",data[i].name)==0)break;
		printf("There is %d %s left~\n",data[i].amount,data[i].name);
		
	}
	
}



int PCmanager::ChangeData(PCdata change)
{
	for(int i=0;i<10;i++)
	{
		if(strcmp("0",data[i].name)==0)
		{
			if(change.amount<0)
				printf("Sorry,we cannot find this kind of PC.Something must be wrong.\n");
			else
			{
				strcpy(data[i].name,change.name);
				data[i].amount+=change.amount;
			}
		break;
		}
		if(!strcmp(change.name,data[i].name))
		{
			data[i].amount+=change.amount;	
			break;
		}
		
	}
	return 0;
}
