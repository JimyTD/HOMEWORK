#ifndef CRAND_H
#define CRAND_H


class CRand
{
    public:
        CRand();
        virtual ~CRand();
        static int  GetRandomNumber();
        static int GetRandomNumber2();
        static int GetRandomNumber3();
        static void Prepare();
    protected:
    private:
};

#endif // CRAND_H
