#ifndef CIRCUIT_H
#define CIRCUIT_H
#include"Electric.h"
#include"Button.h"
class Button;
class Circuit
{
    public:
        Circuit();
        virtual ~Circuit();
        void setSwitch(Button* button);
        void append(Electric* electric);
        void display(int num);
    protected:
    private:
        Electric* elect[20];
        int eUsage,bUsage;
        Button* but[10];
};

#endif // CIRCUIT_H
