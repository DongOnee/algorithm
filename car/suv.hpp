#ifndef SUV_H
#define SUV_H

#include "car.hpp"

class SUV : public Car
{
    private:
    int spareWheels;

    public:
    void setSpareWheels(int);
    int getSpareWheels();

    int getTotalWheels();
};

#endif