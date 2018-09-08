#include "Button.hpp"
#include "ButtonClient.hpp"

void Button::Detect() 
{
    bool ButtonOn = getState();
    if (ButtonOn) itsClient->TurnOn();
    else itsClient->TurnOff();
}
