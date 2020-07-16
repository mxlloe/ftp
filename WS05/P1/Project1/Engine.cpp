#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Engine.h"

using namespace std;

namespace sdds {
	Engine::Engine()
	{
		// Default state:
		m_type[0] = '\0';
		m_size = 0.0;
	}

	Engine::Engine(const char* type, double size)
	{
		// Validate explicit params:
		if (size > 0 && type[0] != '\0')
		{
			// Assign params to engine:
			strcpy(m_type, type);
			m_size = size;
		}
	}

	double Engine::get() const
	{
		// Return engine size:
		return m_size;
	}

	void Engine::display() const
	{
		cout << fixed << setprecision(2) << m_size << " liters - " << m_type << endl;
	}

}