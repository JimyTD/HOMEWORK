#include "CSafeArray.h"
using namespace std;
CSafeArray::CSafeArray(int size)
{
    nSize=size;
    p=new int[size];
}

CSafeArray::~CSafeArray()
{
    //dtor
}


ostream& operator <<(ostream &Out,CSafeArray arr)
{
    return Out;
}
