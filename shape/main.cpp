#include <iostream>
#include".\include\CCircle.h"
#include".\include\CRectangle.h"
#include".\include\CShape.h"
#include".\include\CCanvas.h"
#include<assert.h>
using namespace std;

int main()
{
    CCanvas canvas;

    CCircle c1(10,20,5);
    CCircle c2(20,30,100);


    CRectangle r1(10,20,3,3);

    canvas.append(&c1);
    canvas.append(&r1);
    canvas.append(&c2);
    canvas.draw();
    cout<<canvas.totalArea()<<endl;

    return 0;
}
