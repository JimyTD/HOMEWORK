#ifndef CEMPLOYEE_H
#define CEMPLOYEE_H


class CEmployee
{
    public:
        CEmployee(char* name);
        int CalcSalary();
        char* GetName();
        int GetLevel();
        void SetLevel(int newlevel);
        virtual ~CEmployee();
    protected:
    private:
        int level;
        char name[20];
};


class CSales:public CEmployee
{
    public:
        CSales(char* name);
        ~CSales();
        void SetSaleCount(int nCount);
        int CalcSalary();
    private:
        int nSaleCount;
};
#endif // CEMPLOYEE_H
