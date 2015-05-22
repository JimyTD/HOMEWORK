#include "Fighter.h"

Fighter::Fighter(int nLeft,int nTop,int nWidth,int nHeight,CTexture &ct):FlyingObject(nLeft,nTop,nWidth,nHeight)
{
    switch(type)
   {
   case 1:
      setTexture(ct.pFighter,true);
      break;
   case 2:
    break;
   case 3:
    break;
   default:
    break;
    }//////
    setPosition(nLeft,nTop);
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
