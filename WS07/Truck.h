// Sean Ramolete
// 155074198


#ifndef SDDS_TRUCK_H
#define SDDS_TRUCK_H

#include "MotorVehicle.h"

namespace sdds
{
	class Truck : public MotorVehicle
	{
	private:
		double maximum_capacity{0.0};
		double current_capacity{0.0};

	public:
		Truck();
		Truck(const char *, int, double, const char *);
		bool addCargo(double);
		bool unloadCargo();
		std::ostream &write(std::ostream &) const;
		std::istream &read(std::istream &);
	};
	std::ostream &operator<<(std::ostream &, const Truck &);
	std::istream &operator>>(std::istream &, Truck &);
} // namespace sdds

#endif // SDDS_TRUCK_H

// adasdsd