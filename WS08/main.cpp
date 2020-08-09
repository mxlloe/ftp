// Workshop 8: Virtual Functions
// Date: 05.07.2020
// Author: Cornel
// Description:
// Tests the Employee and its derived classes via virtual functions
/////////////////////////////////////////////
#include <iostream>
#include "Doctor.h"
#include "Doctor.h"
#include "Engineer.h"
#include "Engineer.h"
#include "Employee.h"

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
    Employee* employees[]{
        new Doctor("Family doctor", 90, 30),
        new Doctor("Internal medicine", 150, 25, false),
        new Doctor("Neuro-surgeon", 325, 12, true),
        new Engineer(75, 12),
        new Engineer(60, 25)
    };

    {
        printHeader("T1: Checking display()");
        for (auto i = 0; i < 5; ++i)
            employees[i]->display();
        cout << endl;
    }

    {
        printHeader("T2: Doctor's weekly income");
        for (auto i = 0; i < 3; ++i)
        {
            cout << "Employee " << i + 1 << endl;
            cout << "  Under-time: " << employees[i]->getSalary(10) << endl;
            cout << "   Over-time: " << employees[i]->getSalary(40) << endl;
        }
        cout << endl;
    }

    {
        printHeader("T2: Engineer's weekly income");
        for (auto i = 3; i < 5; ++i)
        {
            cout << "Employee " << i + 1 << endl;
            cout << "     Under-time: " << employees[i]->getSalary(10) << endl;
            cout << "  Overtime-time: " << employees[i]->getSalary(40) << endl;
        }
        cout << endl;
    }

   // Cleaning up the memory
   for (auto i = 0; i < 5; ++i)
      delete employees[i];
   return 0;
}

