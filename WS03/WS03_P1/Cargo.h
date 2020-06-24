#ifndef SDDS_CARGO_H 
#define SDDS_CARGO_H  

namespace sdds {
	const int MAX_DESC = 20;

	struct Cargo {
		char m_description[MAX_DESC + 1];
		double m_weight;
	};
}
#endif
