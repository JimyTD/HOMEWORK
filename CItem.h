#ifndef CITEM_H
#define CITEM_H
class CQueue;

class CItem
{
    public:
        CItem(CQueue* object);
        virtual ~CItem();
        int* next(void);
    protected:
    private:
        CQueue* pObject;
        int* pNow;

};

#endif // CITEM_H
