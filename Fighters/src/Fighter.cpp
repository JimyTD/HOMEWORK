#include "Fighter.h"
#include<iostream>
#define TP_BULLET 20
#define TP_ENEMY 30
#define TP_NORMAL 44
#define TP_BOSS 88
#define TP_BOMB 987
#define TP_EXPLODE 785
#define TP_ENEMYBULLET 826

Fighter::Fighter(int nLeft,int nTop,int nWidth,int nHeight,int nSpeed,CTexture *ct):FlyingObject(nLeft,nTop,nWidth,nHeight,nSpeed)
{
   setTexture(ct->pFighter);
   life=3;
   nCount=0;

   /*   switch(type)
   {
   case 1:
      setTexture(ct->pFighter,true);
      break;
   case 2:
    break;
   case 3:
    break;
   default:
    break;
    }//////*/
    setPosition(nLeft,nTop);
    addSpeed=2;
}

Fighter::~Fighter()
{
    //dtor
}

void Fighter::draw()
{
   switch(type)
   {
   case 1:
   break;
   case 2:
    break;
   case 3:
    break;
   default:
    break;
    }//////
    int a=0;
    a++;
    return ;
}


int Fighter::death()
{
    life--;
    type=TP_EXPLODE;
    nCount=120+5;
    setTexture(ct->pBomb);
    if(life<=0)return -1;
    return 0;
}
