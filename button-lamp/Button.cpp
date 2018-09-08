#include "Button.hpp"

void Button::Detect(bool buttonOn)
{
    if (buttonOn) itsLamp->TurnOn();
    else itsLamp->TurnOff();
}