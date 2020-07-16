#pragma once
#ifndef SDDS_ENGINE_H
#define SDDS_ENGINE_H

namespace sdds {
	
	const int TYPE_MAX_SIZE = 30;

	class Engine {
		double m_size;	
		char m_type[TYPE_MAX_SIZE + 1];	
	public:
		Engine();
		Engine(const char*, double); 
		double get() const; 
		void display() const;
		friend class Ship;
	};
}
#endif