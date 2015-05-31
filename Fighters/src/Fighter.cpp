#include "Fighter.h"

Fighter::Fighter(int nLeft,int nTop,int nWidth,int nHeight,int nSpeed,CTexture *ct):FlyingObject(nLeft,nTop,nWidth,nHeight,nSpeed)
{
   setTexture(ct->pFighter);
   life=3;

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
    if(life<=0)return -1;
}
