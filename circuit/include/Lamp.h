#ifndef LAMP_H
#define LAMP_H
#include"Electric.h"
#include<iostream>

class Lamp:public Electric
{
    public:
        Lamp();
        virtual ~Lamp();
        void display(int num)
        {
            if(num==1)
                std::cout<<"Lamp Open!"<<"\n";
            else
                std::cout<<"Lamp Closed!"<<"\n";
        }
    protected:
    private:
};

#endif // LAMP_H
