// Sean Ramolete
// 155074198

#include <iostream>
#include <iomanip>
#include "Engineer.h"

namespace sdds
{
    Engineer::Engineer(double salary, int level) : Employee(salary, ENGINEER_MIN_HRS)
    {
        this->engineer_level = level;
    }

    double Engineer::getSalary(int hours) const
    {
        double salary = (hours * this->get_hourly_rate()) + (40 * this->engineer_level);
        return hours < this->get_min_hours() ? salary * 0.80 : salary;
    }

    std::ostream &Engineer::display(std::ostream &out) const
    {
        out << "Engineer" << std::endl;
        out << std::setw(ENGINEER_OSTREAM_FIELD_SIZE) << std::right << "Level: " << this->engineer_level << std::endl;
        out << std::setw(ENGINEER_OSTREAM_FIELD_SIZE) << std::right << "Pay Rate: " << this->get_hourly_rate() << std::endl;
        out << std::setw(ENGINEER_OSTREAM_FIELD_SIZE) << std::right << "Min Hours: " << this->get_min_hours() << std::endl;

        return out;
    }
} // namespace sdds
