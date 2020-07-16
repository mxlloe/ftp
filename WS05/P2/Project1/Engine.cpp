#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Engine.h"
using namespace std;

namespace sdds {
	// Constructor
	Engine::Engine() {
		this->m_size = 0;
		this->m_type[0] = '\0';
	}
	// Custom constructor
	Engine::Engine(const char* type, double size) {
		this->m_size = size;
		strcpy(this->m_type, type);
	}
	// Returns the size of the engine object
	double Engine::get() const {
		return this->m_size;
	}
	// Display content of an object in format
	void Engine::display() const {
		cout << this->m_size << " liters - " << this->m_type;
	}
}