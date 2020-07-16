// Sean Ramolete
// 155074198

#ifndef FRUIT_H
#define FRUIT_H

namespace sdds
{
	const int NAME_SIZE{30};

	struct Fruit
	{
		char m_name[NAME_SIZE + 1]; // the name of the fruit
		double m_qty;				// quantity in kilograms
	};
} // namespace sdds

#endif // FRUIT_H
