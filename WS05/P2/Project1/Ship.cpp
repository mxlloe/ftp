#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Ship.h"
using namespace std;

namespace sdds {
	// Constuctor
	Ship::Ship() {
		// Set to empty states
		this->m_engines = nullptr;
		this->m_type = nullptr;
		this->m_engCnt = 0;
	}
	// Custom constructor
	Ship::Ship(const char* type, Engine* engines, int size) {
		this->m_engines = new Engine[size];
		// If the data is valid, store data inside object
		if (size < 10) {
			// Iterate through array of engines and store data isnide current instance
			for (int i = 0; i < size; i++) {
				strcpy(this->m_engines[i].m_type, (engines + i)->m_type);
				this->m_engines[i].m_size = (engines + i)->m_size;
			}
			// Assign data for new object
			int length = strlen(type);
			this->m_type = new char[length + 1];
			strncpy(this->m_type, type, length);
			this->m_type[length] = '\0';
			this->m_engCnt = size;
		} else {
			// Set to empty state
			delete[] this->m_engines;
			*this = Ship();
		}
		// Set invalid objects to empty states
		if (!this) {
			delete[] this->m_engines;
			delete[] this->m_type;
			*this = Ship();
		}
	}
	// Conversion to bool
	Ship::operator bool() const {
		bool valid = true;
		int i = 0;
		// Returns true for valid objects
		do {
			if (this->m_engCnt <= 0 && this->m_type == nullptr && (this->m_engines + i) == nullptr) {
				valid = false;
			}
			i++;
		} while (valid == true && i < this->m_engCnt);

		return valid;
	}
	// Member operator - adds engine to array of engines
	Ship& Ship::operator+=(Engine engine) {
		if (this->m_engCnt >= 10 || engine.m_size == 0 || engine.m_type[0] == '\0') {
			cout << "The object is not valid! Engine cannot be added!" << endl;
		} else {
			// Add new engine
			Engine* temp;
			int resize = this->m_engCnt + 1;
			// Resize array of engines
			temp = new Engine[resize];
			// Iterate through engine array of new engine
			for (int i = 0; i < resize - 1; i++) {
				// Assign instance variables
				strcpy(temp[i].m_type, this->m_engines[i].m_type);
				temp[i].m_size = this->m_engines[i].m_size;
			}
			strcpy(temp[resize - 1].m_type, engine.m_type);
			temp[resize - 1].m_size = engine.m_size;
			// Deallocate memory
			delete[] this->m_engines;
			this->m_engines = nullptr;
			// Assign data to current instance
			this->m_engines = new Engine[resize];
			for (int i = 0; i < resize; i++) {
				strcpy(this->m_engines[i].m_type, temp[i].m_type);
				this->m_engines[i].m_size = temp[i].m_size;
			}
			// Deallocate memory for new engine
			delete[] temp;
			temp = nullptr;
			this->m_engCnt++;
		}
		return *this;
	}
	// Checks the total output number 
	bool Ship::operator<(double power) const {
		bool results = false;
		double shipPower = calcPower();
		// Check power of ship
		if (shipPower < power) {
			results = true;
		}
		return results;
	}
	// Check total output number
	bool operator<(double power, const Ship& theShip) {
		// If first param is smaller than output number, return true
		bool returnVal = !(theShip < MAX_STD_POWER);
		return returnVal;
	}
	// Display content of object
	void Ship::display() const {
		if (this->m_engCnt == 0) {
			cout << "No available data" << endl;
			cout << "The object is not valid! Engine cannot be added!" << endl;
		}
		else {
			double shipPower = calcPower();

			cout << this->m_type << " - ";
			// Display format
			cout.setf(ios::fixed);
			cout.width(6);
			// Print numbers with 2 significant digits
			cout.precision(2);
			cout << shipPower << endl;
			// Display content of
			for (int i = 0; i < this->m_engCnt; i++) {
				cout.precision(2);
				cout << (this->m_engines + i)->m_size << " liters - "
					<< (this->m_engines + i)->m_type << endl;
			}

			cout.precision(3);
		}
	}
	// Calculates ship power
	double Ship::calcPower() const {
		double power = 0;
		for (int i = 0; i < this->m_engCnt; i++) {
			power += ((this->m_engines + i)->m_size * 5);
		}
		return power;
	}
	// Deconstructor
	Ship::~Ship() {
		// Deallocate memory
		delete[] this->m_engines;
		this->m_engines = nullptr;

		delete[] this->m_type;
		this->m_type = nullptr;
	}
}