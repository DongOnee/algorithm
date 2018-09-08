#include "suv.hpp"

void SUV::setSpareWheels(int _spareWheels) 
{ 
    this->spareWheels = _spareWheels; 
} 

int SUV::getSpareWheels(void) 
{ 
    return this->spareWheels; 
}

int SUV::getTotalWheels()
{
    return this->getSpareWheels() + this->wheels;
}



