#include "Button.h"

Button::Button()
{
    //ctor
}

Button::~Button()
{
    //dtor
}

void Button::on()
{
   pCircuit->display(1);
}
void Button::off()
{
   pCircuit->display(0);
}
