// Sean Ramolete
// 155074198

#include <iostream>
#include <iomanip>
#include <cstring>

#include "Doctor.h"

namespace sdds
{
    Doctor::Doctor(const char *type, double salary, int hours, bool specialist) : Employee(salary, hours)
    {
        std::strncpy(this->doctor_type, type, TYPE_MAX_SIZE);
        this->doctor_type[TYPE_MAX_SIZE - 1] = '\0';

        this->is_specialist = specialist;
    }

    double Doctor::getSalary(int hours_worked) const
    {
        if (hours_worked <= this->get_min_hours())
        {
            double standard_pay = this->get_hourly_rate() * hours_worked;
            return this->is_specialist ? standard_pay + 2000 : standard_pay;
        }
        else
        {
            double standard_pay = this->get_hourly_rate() * this->get_min_hours();
            double overtime_pay = (this->get_hourly_rate() * 1.5) * (hours_worked - this->get_min_hours());

            return this->is_specialist ? (standard_pay + overtime_pay + 2000) : (standard_pay + overtime_pay);
        }
    }

    std::ostream &Doctor::display(std::ostream &out) const
    {
        out << "Doctor" << std::endl;
        out << std::setw(DOCTOR_OSTREAM_FIELD_SIZE) << std::right << "Type: " << this->doctor_type << (this->is_specialist ? " (specialist)" : "") << std::endl;
        out << std::setw(DOCTOR_OSTREAM_FIELD_SIZE) << std::right << "Pay Rate: " << this->get_hourly_rate() << std::endl;
        out << std::setw(DOCTOR_OSTREAM_FIELD_SIZE) << std::right << "Min Hours: " << this->get_min_hours() << std::endl;

        return out;
    }
} // namespace sdds
