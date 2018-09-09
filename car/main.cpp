#include <iostream>
#include "suv.hpp"
#include "motorcycle.hpp"

int main(int argc, char* argv[]) 
{
    SUV* newSUV = new SUV();

    newSUV->setWheels(4);
    std::cout << "The wheels are " << newSUV->getWheels() << std::endl;

    Car* motorcycle = new Motorcycle();
    motorcycle->setWheels(2);
    std::cout << "The wheels are " << motorcycle->getWheels() << std::endl;

    delete newSUV;
    delete motorcycle;
 
    return 0;
}