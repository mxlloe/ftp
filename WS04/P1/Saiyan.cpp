#include "Saiyan.h"
#include <string.h>
#include <iostream>

using namespace std;

namespace sdds
{
	Saiyan::Saiyan() {
		// default state
		m_name[0] = '\0';
		m_dob = 0;
		m_power = 0;
		m_super = false;
	};

	Saiyan::Saiyan(const char* name, int dob, int power) {
		set(name, dob, power);
	};

	Saiyan::~Saiyan() {
	};

	void Saiyan::set(const char* name, int dob, int power, bool super) {
		if (name == nullptr || dob > 2020 || power < 0)
		{
			*this = Saiyan();
		}
		else
		{
			strcpy(m_name, name);
			m_dob = dob;
			m_power = power;
			m_super = super;
		}
	};

	bool Saiyan::isValid() const {
		// validate Saiyan
		bool valid_state = strlen(m_name) != '\0' && m_dob < 2020 && m_power > 0;
		return valid_state;
	};

	void Saiyan::display() const {
		if (isValid())
		{
			cout << m_name << endl;
			cout << "DOB: " << m_dob << endl;
			cout << "Power: " << m_power << endl;
			cout << "Super: ";

			m_super == true ? cout << "yes" : cout << "no";
		}
		else
		{
			cout << "Invalid Saiyan!";
		}
		cout << endl;
	};

	bool Saiyan::fight(const Saiyan& other) const {
		bool value = m_power > other.m_power;
		return value;
	};
}
