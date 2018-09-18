#include "ButtonClient.hpp"

class lamp : public ButtonClient
{
public:
    virtual void TurnOn();
    virtual void TurnOff();
    lamp();
};
