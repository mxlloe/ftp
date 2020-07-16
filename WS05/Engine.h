#ifndef SDDS_ENGINE_H
#define SDDS_ENGINE_H

namespace sdds {
	const int TYPE_MAX_SIZE = 30;				// Max length of the type attribute in Engine class.

	class Engine {
		double m_size{};						// The size of an engine, as a floating point number in double precision.
		char m_type[TYPE_MAX_SIZE + 1];			// The engine model type, as an array of chars of size TYPE_MAX_SIZE.

	public:
		Engine();								// Default constructor.
		Engine(const char* type, double size);	// Custom constructor that rx's as params: engine type, size.
		double get() const;						// Query that returns the size of the engine.
		void display() const;					// Query that prints to the screen the content of an object in the format [SIZE] - liters - [TYPE] <ENDL>
	};
}
#endif 