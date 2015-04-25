#ifndef CQUEUE_H
#define CQUEUE_H
#include"CItem.h"
//class CItem;
class CQueue
{
    public:
        CQueue();
        virtual ~CQueue();
        CItem* createIterator();
        void append(int data);
        int pop();
        friend int* next(void);
        int* GetHead()
        {
            return this->pHead;
        }
    protected:
    private:
        int *pArray;
        int nSize;
        int nUsed;
        int *pHead;
        int *pTail;

};

#endif // CQUEUE_H
