#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
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
		} else {
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
		} else {
			cout << "Name: " << m_name << "\nID: " << m_id << endl;
			// Displays data
			if (m_cargo != nullptr) {
				cout << "Cargo: " << m_cargo->m_description << "\nWeight: " << m_cargo->m_weight << endl;
			// If there is no cargo
			} else {
				cout << "No cargo on this train." << endl;
			}
		}
	}
	// Copying data into current instance
	void Train::loadCargo(Cargo car) {
		if (m_cargo == nullptr) {
			m_cargo = new Cargo;
			strcpy(m_cargo->m_description, car.m_description);
			m_cargo->m_weight = car.m_weight;
		}
	}
	// Deallocating memory
	void Train::unloadCargo() {
		if (m_cargo != nullptr) {
			delete m_cargo;
			m_cargo = nullptr;
		}
	}
}