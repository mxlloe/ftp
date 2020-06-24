#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Cargo.h"
#include "Train.h"
using namespace std;

namespace sdds {
	// Initilizes object with data, and checks for valid params
	void Train::initialize(const char* name, int id) {
		// If params are invalid, set to empty states
		if (name == nullptr || id < 1 || name[0] == '\0') {
			m_name[0] = '\0';
			m_id = 0;
			// If params are valid, copy to attributes
		}
		else {
			strcpy(m_name, name);
			m_id = id;
		}
		// Initilize cargo to null
		m_cargo = nullptr;
	}
	// Determines if object contains valid data
	bool Train::isValid() const {
		bool valid = false;
		if (m_id != 0 || m_name[0] != '\0') {
			valid = true;
		}
		return valid;
	}
	// Displays data of current object
	void Train::display() const {
		cout << "***Train Summary***" << endl;
		// Prints this if the object contains invalid data
		if (isValid() == false) {
			cout << "This is an invalid train." << endl;
			// If object contains valid data, display data
		}
		else {
			cout << "    Name: " << m_name << "\n      ID: " << m_id << endl;
			// Displays data
			if (m_cargo != nullptr) {
				// Assigning existing cargo data
				ios_base::fmtflags existingFlag = cout.flags();
				std::streamsize existingPrec = cout.precision();
				// Display cargo data 
				cout << fixed << setprecision(2);
				cout << "   Cargo: " << m_cargo->getDesc() << "\n  Weight: " << m_cargo->getWeight() << endl;
				//  Display exisitng cargo data
				cout.precision(existingPrec);
				cout.flags(existingFlag);
			}
			else {
				cout << "No cargo on this train." << endl;
			}
		}
	}
	// Setting data for new cargo instance
	void Train::loadCargo(Cargo car)
	{
		// Detect if cargo exists:
		if (m_cargo != nullptr)
		{
			// If cargo exists, delete before loading next cargo:
			delete m_cargo;
			m_cargo = nullptr;
		}

		// Load new cargo:
		m_cargo = new Cargo;	// Set this.cargo_unit to the new Cargo.
		this->m_cargo->setDesc(car.getDesc());
		this->m_cargo->setWeight(car.getWeight());

		// strcpy(cargo_unit->cargo_description, car.cargo_description);
		// cargo_unit->cargo_weight = car.cargo_weight;
	}
	// Deallocating memory
	void Train::unloadCargo() {
		if (m_cargo != nullptr) {
			delete m_cargo;
			m_cargo = nullptr;
		}
	}
	// Swaps the cargo data members
	bool Train::swapCargo(Train& others) {
		bool swapped;
		// return false for invalid data
		if (m_cargo == nullptr || others.m_cargo == nullptr) {
			swapped = false;
			// return true for valid data
		}
		else {
			Cargo* temp = m_cargo;
			m_cargo = others.m_cargo;
			others.m_cargo = temp;
			swapped = true;
		}
		return swapped;
	}
	// Increases cargo weight
	bool Train::increaseCargo(double weight) {
		bool increased;
		if (m_cargo == nullptr || m_cargo->getWeight() == MAX_WEIGHT) {
			increased = false;
			// Only execute for valid data
		}
		else {
			if (m_cargo->getWeight() + weight > MAX_WEIGHT) {
				m_cargo->setWeight(MAX_WEIGHT);
			}
			else {
				m_cargo->setWeight(m_cargo->getWeight() + weight);
			}
			increased = true;
		}
		return increased;
	}
	// Decrease cargo weight
	bool Train::decreaseCargo(double weight) {
		bool decreased;
		if (m_cargo == nullptr || m_cargo->getWeight() == MIN_WEIGHT) {
			decreased = false;
		}
		else {
			if (m_cargo->getWeight() - weight < MIN_WEIGHT) {
				m_cargo->setWeight(MIN_WEIGHT);
			}
			else {
				m_cargo->setWeight(m_cargo->getWeight() - weight);
			}
			decreased = true;
		}
		return decreased;
	}
}