#ifndef CAR_H
#define CAR_H

#include <iostream>

class Car
{
    protected:
    int wheels;
    int price;

    public:
    Car();
    Car(int, int);
    ~Car();
    void setWheels(int);
    void setPrice(int);
    int getWheels(void);
    int getPrice(void);

    virtual void beep();

    Car& operator=(const Car&);
    friend std::ostream& operator<<(std::ostream&, const Car&);

    friend class Engineer;
};

#endif