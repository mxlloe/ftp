#pragma once
#ifndef SDDS_SHIP_H
#define SDDS_SHIP_H
#include "Engine.h"

namespace sdds {
	const double MIN_STD_POWER = 90.111;
	const double MAX_STD_POWER = 99.999;

	class Ship {
		Engine* m_engines;	
		char* m_type;
		int m_engCnt;
	public:
		Ship();	
		Ship(const char* type, Engine* engine, int size);
		~Ship();
		Ship& operator+=(Engine engine);
		bool operator<(double power) const;	
		void display() const;
		double calcPower() const;
		explicit operator bool() const;
	};
	bool operator<(double power, const Ship& theShip);
}
#endif