#include "ButtonImp.hpp"
#include <iostream>
using namespace std;

ButtonImplementation::ButtonImplementation(ButtonClient* bc) : Button(bc) {};

bool ButtonImplementation::getState()
{
    int tmp;
    cin >> tmp;
    if (tmp ==1) return true;
    else return false;
}
