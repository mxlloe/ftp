// Sean Ramolete
// 155074198
// I've done all the coding myself with some youtube tutorials and obviously the professors original source code.

#pragma once
#ifndef SDDS_MOTORCYCLE_H__
#define SDDS_MOTORCYCLE_H__

#include "Vehicle.h"
#include <iostream>

namespace sdds {
class Motorcycle : public Vehicle {
private:
    bool m_sideCar;

public:
    Motorcycle();
    Motorcycle(const char* license, const char* makeModel);
    Motorcycle(const Motorcycle&) = delete;
    Motorcycle& operator=(const Motorcycle&) = delete;
    std::istream& read(std::istream& is);
    std::ostream& write(std::ostream& os) const;
};
}

#endif