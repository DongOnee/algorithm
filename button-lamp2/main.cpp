#include <iostream>
#include "ButtonImp.hpp"
#include "lamp.hpp"
using namespace std;

int main(void)
{
    ButtonClient* l = new lamp();
    Button* btn = new ButtonImplementation(l);
    while(1) btn->Detect();
}
