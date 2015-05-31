#include "FlyingObject.h"

FlyingObject::FlyingObject(int nLeft,int nTop,int nWidth,int nHeight,int nSpeed)
{
    left=nLeft;
    top=nTop;
    width=nWidth;
    height=nHeight;
    speed=nSpeed;
}

FlyingObject::~FlyingObject()
{
    //dtor
}

void FlyingObject::draw()
{
    return;
}
