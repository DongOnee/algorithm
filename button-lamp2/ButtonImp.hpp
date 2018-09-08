#include "Button.hpp"

class ButtonImplementation : public Button
{
    public:
    ButtonImplementation(ButtonClient*);
    virtual bool getState();
};
