// Sean Ramolete
// 155074198

#ifndef SDDS_ENGINEER_H
#define SDDS_ENGINEER_H

#define ENGINEER_MIN_HRS 30
#define ENGINEER_OSTREAM_FIELD_SIZE 20

#include "Employee.h"

namespace sdds
{
	class Engineer : public Employee
	{
	private:
		int engineer_level{0};

	public:
		Engineer();
		Engineer(double, int);
		double getSalary(int) const;
		std::ostream &display(std::ostream &) const;
	};
} // namespace sdds

#endif // SDDS_ENGINEER_H
