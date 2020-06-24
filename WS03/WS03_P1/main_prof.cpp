/*
 * WS03 - Classes and Privacy
 * Author: Michael Huang
 * Modified: Cornel
 */

#include <iostream>
#include "Cargo.h"
#include "Cargo.h" // intentional
#include "Train.h"
#include "Train.h" // intentional
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
    sdds::Cargo c1{ "Boxes", 55.55 };
    sdds::Cargo c2{ "Flowers", 66.666 };
    sdds::Cargo c3{ "Ore", 77.7777 };
    sdds::Train t1;
    sdds::Train t2;
    sdds::Train t3;

    {
        printHeader("T1: Create Invalid Objects");
        t1.initialize(nullptr, 1);
        t2.initialize("", 1);
        t3.initialize("Birthday Train", -5);

        if (t1.isValid() == false && t2.isValid() == false && t3.isValid() == false)
            cout << "Success! Each Train is in empty state" << endl;
        cout << endl;
    }

    {
        printHeader("T2: Display Invalid Objects");
        t1.display();
        t2.display();
        t3.display();
        cout << endl;
    }

    {
        printHeader("T3: Create Valid Objects");
        t1.initialize("Birthday Train", 1);
        t2.initialize("Choo Choo Train", 2);
        t3.initialize("Hype Train", 3);

        if (t1.isValid() && t2.isValid() && t3.isValid())
            cout << "Success! Each train is in non empty state" << endl;
        cout << endl;
    }

    {
        printHeader("T4: Display Valid Objects");
        t1.display();
        t2.display();
        t3.display();
        cout << endl;
    }

    {
        printHeader("T5: Load Cargo onto a Train");
        t1.loadCargo(c1);
        t2.loadCargo(c2);
        t3.loadCargo(c3);
        t1.display();
        t2.display();
        t3.display();
        cout << endl;
    }

    {
        printHeader("T5: Load Cargo onto a Train");
        t1.loadCargo(c1);
        t2.loadCargo(c2);
        t3.loadCargo(c3);
        t1.display();
        t2.display();
        t3.display();
        cout << endl;
    }

    {
        printHeader("T6: Unload Cargo onto a Train");
        t1.unloadCargo();
        t2.unloadCargo();
        t3.unloadCargo();
        t1.display();
        t2.display();
        t3.display();
        cout << endl;
    }

	return 0;
}
