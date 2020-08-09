// Sean Ramolete
// 155074198

#ifndef SDDS_DOCTOR_H
#define SDDS_DOCTOR_H

#define TYPE_MAX_SIZE 32
#define DOCTOR_OSTREAM_FIELD_SIZE 16

#include "Employee.h"

namespace sdds
{
	class Doctor : public Employee
	{
	private:
		char doctor_type[TYPE_MAX_SIZE];
		bool is_specialist{false};

	public:
		Doctor();
		Doctor(const char *, double, int, bool = false);
		double getSalary(int) const;
		std::ostream &display(std::ostream &) const;
	};
} // namespace sdds

#endif // SDDS_DOCTOR_H
