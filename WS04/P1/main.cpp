// Workshop 4: Constructors 
// File: SaiyanMain.cpp
// Version: 1.1
// Date: 1/24/2020
// Author: Mohammad Shamas
// Description:
// This file tests lab section of your workshp
/////////////////////////////////////////////

#include <iostream>
#include "Saiyan.h"
#include "Saiyan.h"  // this is on purpose

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
        printHeader("T1: Checking default constructor");

        Saiyan theSayan;
        theSayan.display();
        cout << endl;
    }

    {
        printHeader("T2: Checking custom constructor");

        Saiyan army[] = {
          Saiyan("Nappa", 2025, 1),
          Saiyan("Vegeta", 2018, -1),
          Saiyan("Goku", 1990, 200),
          Saiyan(nullptr, 2015, 1),
          Saiyan("", 2018, 5)
        };

        cout << "Only #2 should be valid:" << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << "  Sayan #" << i << ": " << (army[i].isValid() ? "valid" : "invalid") << endl;
        }
        for (int i = 0; i < 5; i++)
        {
            army[i].display();
        }
        cout << endl;
    }

    // valid saiyans
    Saiyan s1("Goku", 1990, 2000);
    Saiyan s2;
    s2.set("Vegeta", 1989, 2200);

    {
        printHeader("T3: Checking the fight");
        s1.display();
        s2.display();

        cout << "S1 attacking S2, Battle " << (s1.fight(s2) ? "Won" : "Lost") << endl;
        cout << "S2 attacking S1, Battle " << (s2.fight(s1) ? "Won" : "Lost") << endl;
        cout << endl;
    }
 
    return 0;
}
