// Sean Ramolete
// 155074198


#include <iostream>
#include "Truck.h"

namespace sdds
{
    Truck::Truck()
    {
        this->maximum_capacity = 0.0;
        this->current_capacity = 0.0;
    }

    Truck::Truck(const char *license_plate, int year, double capacity, const char *address) : MotorVehicle(license_plate, year)
    {
        this->maximum_capacity = capacity;
        this->moveTo(address);
    }

    bool Truck::addCargo(double cargo)
    {
        if (this->current_capacity == this->maximum_capacity)
        {
            return false;
        }
        else if ((this->current_capacity + cargo) <= this->maximum_capacity)
        {
            this->current_capacity += cargo;
            return true;
        }
        else if ((this->current_capacity + cargo) > this->maximum_capacity)
        {
            this->current_capacity = this->maximum_capacity;
            return true;
        }
        else
        {
            return false;
        }
    }

    bool Truck::unloadCargo()
    {
        if (this->current_capacity != 0.0)
        {
            this->current_capacity = 0.0;
            return true;
        }
        else
        {
            return false;
        }
    }

    std::ostream &Truck::write(std::ostream &os) const
    {
        MotorVehicle::write(os);
        os << " | " << this->current_capacity << "/" << this->maximum_capacity;

        return os;
    }

    std::istream &Truck::read(std::istream &is)
    {
        MotorVehicle::read(is);
        std::cout << "Capacity: ";
        is >> this->maximum_capacity;
        is.ignore(1000, '\n');

        std::cout << "Cargo: ";
        is >> this->current_capacity;

        return is;
    }

    std::ostream &operator<<(std::ostream &os, const Truck &tr)
    {
        return tr.write(os);
    }

    std::istream &operator>>(std::istream &is, Truck &tr)
    {
        return tr.read(is);
    }

} // namespace sdds
