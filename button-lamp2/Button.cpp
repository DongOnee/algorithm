#include "Button.hpp"
#include "ButtonClient.hpp"

Button::Button(ButtonClient* bc) : itsClient(bc) {};

void Button::Detect()
{
    bool ButtonOn = getState();
    if (ButtonOn) itsClient->TurnOn();
    else itsClient->TurnOff();
}
