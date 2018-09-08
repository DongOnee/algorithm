#include "ButtonImp.hpp"
#include <iostream>
using namespace std;

ButtonImplementation::ButtonImplementation(ButtonClient* bc)
{
    cout << "TEst";
}

bool ButtonImplementation::getState()
{
    int tmp;
    cin >> tmp;
    if (tmp ==1) return true;
    else false;
}
