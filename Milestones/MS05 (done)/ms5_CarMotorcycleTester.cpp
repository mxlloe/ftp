/* ------------------------------------------------------
Final Project Milestone 5
Module: Car and Motorcycle
Filename: ms5_CarMotorcycleTester.cpp
Version 1.0
Author	Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date      Reason
2020/7/4  Preliminary release
-----------------------------------------------------------
comment out car or motorcycle include and functions to test
individually.

*/
#include <iostream>
#include "Car.h"
#include "Motorcycle.h"
using namespace std;
using namespace sdds;
void  MotorcycleTest(Vehicle*);
void  CarTest(Vehicle*);
int main() {
   cout << "Milestone 5, Car and Motorcycle: " << endl;
   CarTest(new Car);
   MotorcycleTest(new Motorcycle);
   return 0;
}
void  MotorcycleTest(Vehicle* V) {
   cout << "Motorcycle Test:" << endl << endl << "Invalid object printout: " <<endl;
   cout << *V << endl;
   cout << "Testing Console Entry, Enter the following: " << endl
      << "ab12<ENTER>" << endl
      << "Harley Davidson<ENTER>" << endl
      << "yes<ENTER>" << endl
      << "y<ENTER>" << endl;
   cin >> *V;
   V->setCsv(true);
   cout << endl << "Comma Separated Values: " << endl << *V << endl;
   V->setCsv(false);
   cout << "Console Printout: " << endl << *V << endl;
   cout << "Testing CSV Entry, Enter the following: " << endl
      << "12,AA22,Honda CD80,0<ENTER>" << endl;
   V->setCsv(true);
   cin >> *V;
   cout << endl << "Comma Separated Values: " << endl << *V << endl;
   V->setCsv(false);
   cout << endl << "Console Printout: " << endl << *V << endl;
   delete V;
}
void  CarTest(Vehicle* V) {
   cout << "Car Test:" << endl << endl << "Invalid object printout: " << endl;
   cout << *V << endl; 
   cout << "Testing Console Entry, Enter the following: " << endl
      << "abc123<ENTER>" << endl
      << "Chevy Volt<ENTER>" << endl
      << "yes<ENTER>" << endl
      << "y<ENTER>" << endl;
   cin >> *V;
   V->setCsv(true);
   cout << endl << "Comma Separated Values: " << endl << *V << endl;
   V->setCsv(false);
   cout << "Console Printout: " << endl << *V << endl;
   cout << "Testing CSV Entry, Enter the following: " << endl
      << "12,GVAA123,Nissan Leaf,0<ENTER>" << endl;
   V->setCsv(true);
   cin >> *V;
   cout << endl << "Comma Separated Values: " << endl << *V << endl;
   V->setCsv(false);
   cout << endl << "Console Printout: " << endl << *V << endl;
   delete V;
}
/*
Milestone 5, Car and Motorcycle:
Car Test:

Invalid object printout:
Invalid Car Object

Testing Console Entry, Enter the following:
abc123<ENTER>
Chevy Volt<ENTER>
yes<ENTER>
y<ENTER>

Car information entry
Enter Licence Plate Number: abc123
Enter Make and Model: Chevy Volt
Carwash while parked? (Y)es/(N)o: yes
Invalid response, only (Y)es or (N)o are acceptable, retry: y

Comma Separated Values:
C,0,ABC123,Chevy Volt,1

Console Printout:
Vehicle type: Car
Parking Spot Number: N/A
Licence Plate: ABC123
Make and Model: Chevy Volt
With Carwash

Testing CSV Entry, Enter the following:
12,GVAA123,Nissan Leaf,0<ENTER>
12,GVAA123,Nissan Leaf,0

Comma Separated Values:
C,12,GVAA123,Nissan Leaf,0


Console Printout:
Vehicle type: Car
Parking Spot Number: 12
Licence Plate: GVAA123
Make and Model: Nissan Leaf
Without Carwash

Motorcycle Test:

Invalid object printout:
Invalid Motorcycle Object

Testing Console Entry, Enter the following:
ab12<ENTER>
Harley Davidson<ENTER>
yes<ENTER>
y<ENTER>

Motorcycle information entry
Enter Licence Plate Number: ab12
Enter Make and Model: Harley Davidson
Does the Motorcycle have a side car? (Y)es/(N)o: yes
Invalid response, only (Y)es or (N)o are acceptable, retry: y

Comma Separated Values:
M,0,AB12,Harley Davidson,1

Console Printout:
Vehicle type: Motorcycle
Parking Spot Number: N/A
Licence Plate: AB12
Make and Model: Harley Davidson
With Sidecar

Testing CSV Entry, Enter the following:
12,AA22,Honda CD80,0<ENTER>
12,AA22,Honda CD80,0

Comma Separated Values:
M,12,AA22,Honda CD80,0


Console Printout:
Vehicle type: Motorcycle
Parking Spot Number: 12
Licence Plate: AA22
Make and Model: Honda CD80


*/