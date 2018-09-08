#include "Lamp.hpp"

class Button
{
    private:
    Lamp* itsLamp;

    public:
    Button(Lamp* l) : itsLamp(l) {};
    void Detect(bool);
};