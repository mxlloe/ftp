// Name: Sean Lester Ramolete
// Student ID: 155074198
// Student Email: sramolete@myseneca.ca
// Section: NCC

// all code used is from the professors pdf instructions and me.



#pragma once
#include "Gift.h"
#include <iostream>
using namespace std;
namespace sdds
{
	void gifting(char* desc)
	{
		cout << "Enter gift description: ";
		cin.width(MAX_DESC + 1);
		cin >> desc;
	}

	void gifting(double &price)
	{
		do
		{
			cout << "Enter gift price: ";
			cin >> price;

			if ((price < 0) || (price > MAX_PRICE))
			{
				cout << "Gift price must be between 0 and " << MAX_PRICE << endl;
			}
		} while ((price < 0) || (price > MAX_PRICE));
	}

	void gifting(int& units)
	{
		do
		{
			cout << "Enter gift units: ";
			cin >> units;
			if (units < 1)
			{
				cout << "Gift units must be at least 1" << endl;
			}
		} while (units < 1);
	}

	void display(const Gift& theGift)
	{
		cout << "Gift details: " << endl;
		cout << "Description: " << theGift.m_description << endl;
		cout << "Price: " << theGift.m_price << endl;
		cout << "Units: " << theGift.m_units << endl;
	}
}




