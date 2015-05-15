#ifndef BUTTON_H
#define BUTTON_H
#include"Circuit.h"
class Circuit;

class Button
{
    public:
        Button();
        virtual ~Button();
        void on();
        void off();
        void setCircuit(Circuit* p)
        {
            pCircuit=p;
        }
    protected:
    private:
        Circuit* pCircuit;
};

#endif // BUTTON_H
