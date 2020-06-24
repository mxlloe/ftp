// Name: Sean Lester Ramolete
// Student ID: 155074198
// Student Email: sramolete@myseneca.ca
// Section: NCC

// all code used is from the professors pdf instructions and me.

#pragma once
#ifndef SDDS_GIFT_H
#define SDDS_GIFT_H
namespace sdds
{
	const char MAX_DESC = 15;
	const double MAX_PRICE = 999.999;

	struct Gift {
		char m_description[MAX_DESC+1];
		double m_price;
		int m_units;


	};

	void gifting(char* desc);
	void gifting(double& price);
	void gifting(int& units);
	void display(const Gift& theGift);

};
#endif