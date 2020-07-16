// Workshop 5: Operator Overloading
// Version: 2.0
// Date: 2/2/2020
// Author: Elnaz Delpisheh
// Update: 10.05.2020 by Cornel
// Description:
// This file tests lab section of your workshp
/////////////////////////////////////////////



#include <iostream>
#include "Ship.h"
#include "Ship.h"
#include "Engine.h"
#include "Engine.h"
#include <iomanip>

using namespace std;
using namespace sdds;

void printHeader(const char* title)
{
	char oldFill = cout.fill('-');
	cout.width(40);
	cout << "" << endl;

	cout << "|> " << title << endl;

	cout.fill('-');
	cout.width(40);
	cout << "" << endl;
	cout.fill(oldFill);
}

int main()
{
	{
		printHeader("T1: Testing Constants");

		cout << "TYPE_MAX_SIZE: " << sdds::TYPE_MAX_SIZE << endl;
		cout << "MIN_STD_POWER: " << sdds::MIN_STD_POWER << endl;
		cout << "MAX_STD_POWER: " << sdds::MAX_STD_POWER << endl;
		cout << endl;
	}

	{
		printHeader("T2: Testing Default Constructor");

		Ship invalid;
		invalid.display();
		invalid += Engine("D2", 2.1);
		cout << endl;
	}

	Engine engines[] = {
		Engine("V8", 4.4),
		Engine("V8", 5.0),
		Engine("Inline", 4.1),
		Engine("D3", 7.0),
		Engine("D0", 2.0),
		Engine("D1", 3.2),
	};

	{
		printHeader("T3: Testing Custom Constructor");
		
		Ship titanic("cruiser", engines, 6);
		cout.setf(ios::fixed);
		cout.precision(2);
		titanic.display();
		cout << endl;
	}

	{
		printHeader("T4: Testing Conversion to Bool Operator");
		Ship invalid;
		Ship titanic("liner", engines, 1);

		if (invalid)
			cout << "1. Test Failed! Object should be invalid.\n";
		else
			cout << "1. Test succeeded!\n";

		if (titanic)
			cout << "2. Test succeeded!\n";
		else
			cout << "3. Test Failed! Object should be valid.\n";
		
		cout << endl;
	}

	{
		printHeader("T5: Testing += and < Operators");

		Ship titanic("liner", engines, 3);

		char type[]{ "D0" };
		while (titanic < sdds::MIN_STD_POWER)
		{
			type[1]++;
			cout << "Ship not up to standard. Required power: "
			     << sdds::MIN_STD_POWER << endl;
			titanic += Engine(type, 2.1);
		}

		titanic.display();

		if (sdds::MAX_STD_POWER < titanic)
			cout << "Too much power." << endl;
		else
			cout << fixed << setprecision(3) << "Ship doesn't exceed power regulation of: "
			     << sdds::MAX_STD_POWER << endl;
	}

	return 0;
}
