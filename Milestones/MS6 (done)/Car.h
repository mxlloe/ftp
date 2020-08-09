// Sean Ramolete
// 155074198
// I've done all the coding myself with some youtube tutorials and obviously the professors original source code.

#pragma once
#ifndef SDDS_CAR_H__
#define SDDS_CAR_H__

#include "Vehicle.h"
#include <iostream>
using namespace std;

namespace sdds {
class Car : public Vehicle {
private:
    bool m_carWash;

public:
    Car();
    Car(const char* license, const char* makeModel);
    Car(const Car&) = delete;
    Car& operator=(const Car&) = delete;
    std::istream& read(std::istream& is);
    std::ostream& write(std::ostream& os) const;
};
}

#endif