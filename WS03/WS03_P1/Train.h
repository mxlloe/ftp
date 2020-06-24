#ifndef SDDS_TRAIN_H 
#define SDDS_TRAIN_H 
#include "Cargo.h"
namespace sdds {
	const int MAX_NAME = 30;

	class Train {
		char m_name[MAX_NAME + 1];
		int m_id;
		Cargo* m_cargo;
	public:
		void initialize(const char* name, int id);
		bool isValid() const;
		void loadCargo(Cargo car);
		void unloadCargo();
		void display() const;
	};
}
#endif