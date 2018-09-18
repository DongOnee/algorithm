#include "ButtonImp.hpp"
#include "lamp.hpp"

int main(void)
{
    ButtonClient* l = new lamp();
    ButtonImplementation* btn = new ButtonImplementation(l);
    while(1) btn->Detect();
}
