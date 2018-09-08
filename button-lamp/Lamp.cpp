#include "Lamp.hpp"

Lamp::Lamp()
{
    state = false;
};

void Lamp::TurnOn()
{
    state = true;
};

void Lamp::TurnOff()
{
    state = false;
}

bool Lamp::getState()
{
    return state;
}