#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Ship.h"

using namespace std;

namespace sdds {
	Ship::Ship()
	{
		m_type[0] = '\0';
		m_engCnt = 0;
	}

	Ship::Ship(const char* type, const Engine engines[], int cnt)
	{
		if (type != nullptr && engines != nullptr && cnt > 0)
		{
			// Set data members for current object:
			strcpy(m_type, type);
			m_engCnt = cnt;

			// Assign engines to the current object:
			for (int i = 0; i < cnt; i++)
			{
				m_engines[i] = engines[i];
			}
		}
		else
		{
			// Set default state:
			m_type[0] = '\0';
			m_engCnt = 0;
		}
	}

	Ship::operator bool() const
	{
		bool valid = true;

		if (m_type[0] == '\0' && m_engCnt == 0)
		{
			valid = false;
		}

		return valid;
	}

	bool Ship::operator<(double power) const
	{
		bool under_power = false;

		if (calculatePower() < power) {
			under_power = true;
		}

		return under_power;

	}

	double Ship::calculatePower() const {
		double total_power = 0;

		// Iterate through Ship's engines and add to total_power:
		for (int i = 0; i < m_engCnt; i++) {
			total_power += (double)((double)m_engines[i].get() * (double)5);
		}

		return total_power;
	}


	void Ship::display() const {
		if (*this) {
			// Display engines:
			cout << m_type << " - " << calculatePower() << endl;
			for (int i = 0; i < m_engCnt; i++) {
				m_engines[i].display();
			}
		}
		else
		{
			// Display message if no engine:
			cout << "No available data" << endl;
		}
	}

	Ship& Ship::operator+=(Engine engine) {
		// Check if engine count less than 10:
		if (m_engCnt < MAX_NUM_ENGINES) {
			// Check if Engine is valid:
			if (m_type[0] == '\0')
			{
				cout << "The object is not valid! Engine cannot be added!" << endl;
			}
			else {
				// If engine is valid and engine count less than maximum number of engines, add engine:
				m_engines[m_engCnt++] = engine;
			}
		}

		return *this;
	}

	bool operator<(double power, const Ship& ship)
	{
		bool under_powered = false;

		if (ship.calculatePower() > power) {
			under_powered = true;
		}

		return under_powered;
	}


}