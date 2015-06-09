#include "FlyingObject.h"

FlyingObject::FlyingObject(int nLeft,int nTop,int nWidth,int nHeight,int nSpeed,CTexture *ct,int Count)
{
    left=nLeft;
    top=nTop;
    width=nWidth;
    height=nHeight;
    speed=nSpeed;
    this->ct=ct;
    nCount=Count;
}

FlyingObject::~FlyingObject()
{
    //dtor
}

void FlyingObject::draw()
{
    return;
}
