// Sean Ramolete
// 155074198

#ifndef SDDS_MOTORVEHICLE_H
#define SDDS_MOTORVEHICLE_H

namespace sdds
{
	const int LICENSE_PLATE_SIZE{32};
	const int ADDRESS_SIZE{64};

	class MotorVehicle
	{
	private:
		char license_plate_number[LICENSE_PLATE_SIZE];
		char current_address[ADDRESS_SIZE];
		int vehicle_build_year{0};

	public:
		MotorVehicle();
		MotorVehicle(const char *, int, const char * = "Factory");
		void moveTo(const char *);
		std::ostream &write(std::ostream &) const;
		std::istream &read(std::istream &);
	};
	std::ostream &operator<<(std::ostream &, const MotorVehicle &);
	std::istream &operator>>(std::istream &, MotorVehicle &);
} // namespace sdds

#endif // SDDS_MOTORVEHICLE_H
