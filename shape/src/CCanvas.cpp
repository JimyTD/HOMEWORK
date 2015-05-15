#include "../include/CCanvas.h"
#include<assert.h>
void CCanvas::append(CShape* newShape)
{
    //std::cout<<"shit";

    if(usage>9)return;
    arr[usage]=newShape;
    usage++;
}


void CCanvas::draw()
{
    //std::cout<<"shit";
    int i;
    for(i=0;i<usage;i++)
    {
       arr[i]->draw();
    }
}


CCanvas::~CCanvas()
{
    //dtor
}
