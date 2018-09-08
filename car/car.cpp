#include <iostream> 
#include "car.hpp"
using namespace std;

Car::Car() {
    this->wheels = 0;
    this->price = 0;
    cout << "Instance is created" << endl;
}

Car::~Car() {
    cout << "Instance is deleted" << endl;
}

/* declare the overloading constructor */ 
Car::Car(int _wheels, int _price) 
{ 
    this->wheels = _wheels; 
    this->price = _price; 

    cout << "Instance is created with wheels(" << _wheels << "), price(" << _price << ")" << endl; 
}

void Car::setWheels(int _wheels) {
    this->wheels = _wheels;
}

void Car::setPrice(int _price) {
    this->price = _price;
}

int Car::getWheels(void) {
    return this->wheels;
}

int Car::getPrice(void) {
    return this->price;
}

void Car::beep()
{
    cout << "NO Horne" << endl;
}

Car& Car::operator=(const Car& rightCar) 
{ 
    this->wheels = rightCar.wheels; 
    this->price = rightCar.price; 

    return *this; 
}

std::ostream& operator<<(std::ostream& os, const Car& car)
{
    os << "This car is" << car.wheels << " wheels, and the price is " << car.price;
    return os;
}