#ifndef CSAFEARRAY_H
#define CSAFEARRAY_H
#include<assert.h>
#include<iostream>
using namespace std;

class CSafeArray
{
    public:
        CSafeArray(int size);
        virtual ~CSafeArray();
        int& operator [](int index)
        {
            if(index<0)assert(0);
            if(index>9)assert(0);
            return p[index];
        }
       friend ostream& operator <<(ostream &Out,CSafeArray arr);

    protected:
    private:
        int *p;
        int nSize;
};

#endif // CSAFEARRAY_H
