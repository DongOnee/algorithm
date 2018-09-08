#include <iostream>
#include "Button.hpp"

using namespace std;

int main(void)
{
    Lamp * l = new Lamp();
    Button * btn = new Button(l);
    btn->Detect(false);
    if (l->getState()) cout << "ON" << endl;
    else cout << "OFF" << endl;
    

    return 0;
};