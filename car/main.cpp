#include <iostream>
#include "suv.hpp"
#include "motorcycle.hpp"

int main(int argc, char* argv[]) { Car* myCar = new Car(4,10000); Car usedCar = *myCar; std::cout << usedCar << std::endl; delete myCar; return 0; }