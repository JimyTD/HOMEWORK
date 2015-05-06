////////////坐标系向下为X向右为Y

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


#define GROUND 0
#define WALL 1
#define CASES 2
#define PLAYER 3
#define OBJECT 4
#define FINISHONE 5






//////////////////////////////////////CLASSES//////////////////////////////////////////
struct pos
{
	int xpos;
	int ypos;
};





class Cmap
{
public:
	int maze[12][12];  
   	pos caseposition[3];
	pos objectposition[3];
	
	Cmap(int out[12][12],pos outcase[3],pos object[3]);
	int getmap1(int out[12][12]);
	//int getmap2();
};

class Cplayer
{
public:
	int currentx;
	int currenty;
	Cmap* map;
	int buffermaze[12][12];
	
	
	void copybasemaze();
	void changemap();
	int displaymap();
	int move(char key);
	int push(int x,int y);
	int win();
	Cplayer(Cmap* a,int startx,int starty);
	
};








///////////////main///////////////
int main()
{
	char key;
	int startx=2,starty=2,Ifwin=0;
	int a[12][12]={1,1,1,1,1,1,1,1,1,1,1,1,
		1,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,1,
		1,1,1,1,1,1,1,1,1,1,1,1};
	pos xz[3]={4,4,4,8,7,6};
	pos ob[3]={9,3,9,5,9,7};
    Cmap map(a,xz,ob);
	
	Cplayer player(&map,startx,starty);
	player.displaymap();
	while(key=_getch())
	{
		system("CLS");
		player.copybasemaze();
		player.move(key);
		player.changemap();
		player.displaymap();
	    Ifwin=player.win();
		if(Ifwin==1)break;
	}
	printf("Congratulations!!");
	
	system("pause");
	
	return 0;
}

















////////functions inplementation//////////////
Cplayer::Cplayer(Cmap* a,int startx,int starty)
{
	map=a;
	currentx=startx;
	currenty=starty;
	copybasemaze();
}

int Cplayer::move(char key)
{
	switch(key)
	{
	case 'W':
	case 'w':
		{
			if(buffermaze[currentx-1][currenty]==WALL)break;
			if(buffermaze[currentx-1][currenty]==CASES)
			{
				if(buffermaze[currentx-2][currenty]==CASES)break;
				if(buffermaze[currentx-2][currenty]==WALL)break;
				push(-1, 0);
			}
			currentx--;
			break;
		}
	case 'A':
	case 'a':
		{
			if(buffermaze[currentx][currenty-1]==WALL)break;
			if(buffermaze[currentx][currenty-1]==CASES)
			{
				if(buffermaze[currentx][currenty-2]==CASES)break;
				if(buffermaze[currentx][currenty-2]==WALL)break;
				push(0,-1);
			}
			currenty--;
			break;
		}
	case 'S':
	case 's':
		{
			if(buffermaze[currentx+1][currenty]==WALL)break;
			if(buffermaze[currentx+1][currenty]==CASES)
			{
				if(buffermaze[currentx+2][currenty]==CASES)break;
				if(buffermaze[currentx+2][currenty]==WALL)break;
				push(1,0);
			}
			currentx++;
			break;
		}
	case 'D':
	case 'd':
		{
			if(buffermaze[currentx][currenty+1]==WALL)break;
			if(buffermaze[currentx][currenty+1]==CASES)
			{
				if(buffermaze[currentx][currenty+2]==CASES)break;
				if(buffermaze[currentx][currenty+2]==WALL)break;
				push(0,1);
			}
			currenty++;
			break;
		}
		
		
	}
	changemap();
	return 0;
}



int Cplayer::push(int x,int y)
{
	for(int i=0;i<=2;i++)
	{
		if(((*map).caseposition[i].xpos==currentx+x)&&((*map).caseposition[i].ypos==currenty+y))
		{
			(*map).caseposition[i].xpos+=x;
			(*map).caseposition[i].ypos+=y;
			break;
		}
		
		
	}
	
	return 0;
}

int Cplayer::displaymap()
{
	int i,j;
	for(i=0;i<=11;i++)
	{
		for(j=0;j<=11;j++)
		{
			switch(buffermaze[i][j])
			{
			case GROUND:
				printf(" ");
				break;
			case WALL:
				printf("%c",4);
				break;
			case PLAYER:
				printf("%c",3);
				break;
			case OBJECT:
				printf("%c",'O');
				break;
			case CASES:
				{
					int Isfinish=0;
					for(int k=0;k<=2;k++)
					{
						if((*map).objectposition[k].xpos==i&&(*map).objectposition[k].ypos==j)
						{
							printf("%c",2);
							Isfinish=1;
							break;
						}
					}	
					if(Isfinish==0)printf("%c",'X');
					break;
				}
			default :break;
			}
			
		}
		printf("\n");
	}
	return 0;
}


void Cplayer::copybasemaze()
{
	int i,j;
	for(i=0;i<=11;i++)
	{
		for(j=0;j<=11;j++)
			buffermaze[i][j]=(*map).maze[i][j];
	}
	for( j=0;j<=2;j++)
	{
		buffermaze[(*map).objectposition[j].xpos][(*map).objectposition[j].ypos]=OBJECT;
	}
	for( i=0;i<=2;i++)
	{
		buffermaze[(*map).caseposition[i].xpos][(*map).caseposition[i].ypos]=CASES;
	}
}


void Cplayer::changemap()
{
	for(int j=0;j<=2;j++)
	{
		buffermaze[(*map).objectposition[j].xpos][(*map).objectposition[j].ypos]=OBJECT;
	}
	for(int i=0;i<=2;i++)
	{
		buffermaze[(*map).caseposition[i].xpos][(*map).caseposition[i].ypos]=CASES;
	}
	buffermaze[currentx][currenty]=PLAYER;
}



int Cplayer::win()
{
	int finishnumber=0;
	for(int i=0;i<=2;i++)
		for(int j=0;j<=2;j++)
		{
			if((*map).caseposition[i].xpos==(*map).objectposition[j].xpos)
				if((*map).caseposition[i].ypos==(*map).objectposition[j].ypos)
					finishnumber++;
		}
	if(finishnumber==3)return 1;
	return 0;
}
////////////////////////////
Cmap::Cmap(int out[12][12],pos outcase[3],pos object[3])
{
	for(int i=0;i<=11;i++)
		for(int j=0;j<=11;j++)
			maze[i][j]=out[i][j];
		for(int k=0;k<=2;k++)
		{
			caseposition[k].xpos=outcase[k].xpos;
			caseposition[k].ypos=outcase[k].ypos;
		}
		for(int l=0;l<=2;l++)
		{
			objectposition[l].xpos=object[l].xpos;
			objectposition[l].ypos=object[l].ypos;
		}
		
}


