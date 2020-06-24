#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>
#include "Saiyan.h"

using namespace std;

namespace sdds
{
	Saiyan::Saiyan()
	{
	}
	
	Saiyan::Saiyan(const char* name, int dob, int power)
	{
		set(name, dob, power);
	}

	void Saiyan::set(const char* name, int dob, int power, int level, bool super)
	{
		if (name != nullptr && name[0] != '\0')
		{
			if (m_name != nullptr)
			{
				delete[] m_name;
				m_name = nullptr;
			}
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
		}
		if (dob != 0 && dob < 2020)
		{
			m_dob = dob;
		}
		if (power > 0)
		{
			m_power = power;
		}
		if (level > 0)
		{
			m_level = level;
		}
		m_super = super;
	}
	
	bool Saiyan::isValid() const
	{
		bool valid_state = m_name != nullptr && m_dob != 0 && m_dob < 2020 && m_power > 0 && m_level >= 0;
		return valid_state;
	}

	void Saiyan::display() const
	{
		if (isValid())
		{
			cout << m_name << endl;
			
			cout.setf(ios::right);
			cout.width(10);
			cout << "DOB: " << m_dob << endl;
			cout.width(10);
			cout << "Power: " << m_power << endl;
			cout.width(10);
			if (m_super == true) {
				cout << "Super: " << "yes" << endl;
				cout.width(10);
				cout << "Level: " << m_level;
			}
			else
			{
				cout << "Super: " << "no";
			}
			cout.unsetf(ios::left);
		}
		else
		{
			cout << "Invalid Saiyan!";
		}
		cout << endl;
	}

	bool Saiyan::fight(Saiyan& other)
	{
		// Check both Saiyans for super level and power up accordingly:
		if (m_super == true)
		{
			m_power += int(m_power * (.1 * m_level));	// Cast an int to avoid possible memory loss.
		}
		if (other.m_super == true)
		{
			other.m_power += int(other.m_power * (.1 * other.m_level));
		}

		bool value = m_power > other.m_power;
		return value;
	}

	Saiyan::~Saiyan()
	{
		if (m_name != nullptr)
		{
			delete[] m_name;	// Deallocate memory of member.
			m_name = nullptr;
		}
	}
}
