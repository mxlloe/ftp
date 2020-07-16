// Sean Ramolete
// 155074198

#include <iostream>
#include <cstring>
#include <iomanip>

#include "MotorVehicle.h"

namespace sdds
{
	MotorVehicle::MotorVehicle()
	{
		this->license_plate_number[0] = '\0';
		this->current_address[0] = '\0';
		this->vehicle_build_year = 0;
	}

	MotorVehicle::MotorVehicle(const char *incoming_license_plate, int incoming_year, const char *incoming_addr)
	{
		// assuming valid data is passed in as per professor specifications
		int license_plate_size = std::strlen(incoming_license_plate) <= LICENSE_PLATE_SIZE ? std::strlen(incoming_license_plate) : LICENSE_PLATE_SIZE;
		int address_size = std::strlen(incoming_addr) <= ADDRESS_SIZE ? std::strlen(incoming_addr) : ADDRESS_SIZE;

		std::strncpy(this->license_plate_number, incoming_license_plate, license_plate_size);
		this->license_plate_number[license_plate_size] = '\0';

		this->vehicle_build_year = incoming_year;

		std::strncpy(this->current_address, incoming_addr, address_size);
		this->current_address[address_size] = '\0';
	}

	void MotorVehicle::moveTo(const char *address)
	{
		if (std::strncmp(this->current_address, address, ADDRESS_SIZE) != 0)
		{
			std::cout << "|";
			std::cout << std::setw(10) << std::right << this->license_plate_number << "| ";
			std::cout << "|";
			std::cout << std::setw(20) << std::right << this->current_address << " --->--- ";
			std::cout << std::setw(20) << std::left << address;
			std::cout << "|" << std::endl;

			int address_size = std::strlen(address) <= ADDRESS_SIZE ? std::strlen(address) : ADDRESS_SIZE;
			std::strncpy(this->current_address, address, address_size);
			this->current_address[address_size] = '\0';
		}
	}

	std::ostream &MotorVehicle::write(std::ostream &os) const
	{
		os << "| " << this->vehicle_build_year
		   << " | " << this->license_plate_number
		   << " | " << this->current_address;

		return os;
	}

	std::istream &MotorVehicle::read(std::istream &in)
	{
		std::cout << "Built year: ";
		std::cin >> this->vehicle_build_year;
		std::cin.ignore(1000, '\n');

		std::cout << "License plate: ";
		in.getline(this->license_plate_number, LICENSE_PLATE_SIZE, '\n');

		std::cout << "Current location: ";
		in.getline(this->current_address, ADDRESS_SIZE, '\n');

		return in;
	}

	std::ostream &operator<<(std::ostream &os, const MotorVehicle &mv)
	{
		return mv.write(os);
	}

	std::istream &operator>>(std::istream &is, MotorVehicle &mv)
	{
		return mv.read(is);
	}
} // namespace sdds
