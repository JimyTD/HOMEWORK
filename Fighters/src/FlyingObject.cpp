#include "FlyingObject.h"

FlyingObject::FlyingObject(int nLeft,int nTop,int nWidth,int nHeight)
{
    left=nLeft;
    top=nTop;
    width=nWidth;
    height=nHeight;
}

FlyingObject::~FlyingObject()
{
    //dtor
}

void FlyingObject::draw()
{
    return;
}
