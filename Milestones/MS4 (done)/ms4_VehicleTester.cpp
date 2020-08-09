/* ------------------------------------------------------
Final Project Milestone 4
Module: ReadWritable
Filename: ms4_VehicleTester.cpp
Version 1.0
Author	Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date      Reason
2020/7/4  Preliminary release
-----------------------------------------------------------*/


#include <iostream>
#include "Vehicle.h"
using namespace std;
using namespace sdds;
void TestValidations();
void TestOperatorEqualEqual(const Vehicle& A, const Vehicle& B);
void TestIO(Vehicle& V);
int main() {
   Vehicle V;
   Vehicle C("abcd", "C car");
   // you can comment each test to develop your Vehicle step by step: 
   TestIO(V);
   TestOperatorEqualEqual(C, V);
   TestValidations();
   return 0;
}
void TestIO(Vehicle& V) {
   cout << "Invalid Vehicle Printing:" << endl;
   cout << V << endl;
   cout << "Reading vehicle from console: " << endl;
   cout << "Enter:" << endl << "abc<ENTER>" << endl << "abc<ENTER>" << endl;
   V.setCsv(false);
   cin >> V;
   cout << "Printing a Vehicle that is not parked:" << endl;
   cout << V << endl;
   V.setParkingSpot(12);
   cout << "Printing a Vehicle that is parked in the spot number 12:" << endl;
   cout << V << endl;
   cout << "Reading and Writing Comma Separated values: " << endl;
   cout << "Enter: " << endl;
   cout << "123,abcd,abcd,<ENTER>" << endl;
   V.setCsv(true);
   cin >> V;
   cin.ignore(1000, '\n');
   cout << V << endl;
}

void TestValidations() {
   Vehicle* V;
   cout << "Construction validations:" << endl;
   V = new Vehicle(nullptr, "abc");
   cout << *V;
   delete V;
   V = new Vehicle("123456789", "abc");
   cout << *V;
   delete V;
   V = new Vehicle("", "abc");
   cout << *V;
   delete V;
   V = new Vehicle("ABC", nullptr);
   cout << *V;
   delete V;
   V = new Vehicle("ABC", "");
   cout << *V;
   delete V;
   V = new Vehicle("ABC", "A");
   cout << *V;
   cout << "Input validations: " << endl;
   cout << "Enter: " << endl << "123456789<ENTER>" << endl << "abc<ENTER>" << endl << "abc<ENTER>" << endl;
   cin >> *V;
   cout << *V << endl;
   cout << "Enter: " << endl << "abc<ENTER>" << endl << "a<ENTER>" << endl << "ab<ENTER>" << endl;
   cin >> *V;
   cout << *V << endl;
   cout << "Testing setParkingSpot validation: " << endl <<  "Valid setting: " <<endl;
   V->setParkingSpot(20);
   cout << *V << endl;
   cout << "invalid setting: " << endl;
   V->setParkingSpot(-1);
   cout << *V << endl;
   delete V;
}
void TestOperatorEqualEqual(const Vehicle& A, const Vehicle& B) {
   cout << "opeator== (cstring):" << endl;
   if (A == "Abcd") {
      cout << "operator== with cstring works" << endl;
   }
   else {
      cout << "Bad Opertor==, fix your code" << endl;
   }
   cout << "opeator== (Vehicle):" << endl;
   if (A == B) {
      cout << "operator== with Vehicle works" << endl;
   }
   else {
      cout << "Bad Opertor==, fix your code" << endl;
   }
}

/*
Ouput:
Invalid Vehicle Printing:
Invalid Vehicle Object

Reading vehicle from console:
Enter:
abc<ENTER>
abc<ENTER>
Enter Licence Plate Number: abc
Enter Make and Model: abc
Printing a Vehicle that is not parked:
Parking Spot Number: N/A
Licence Plate: ABC
Make and Model: abc

Printing a Vehicle that is parked in the spot number 12:
Parking Spot Number: 12
Licence Plate: ABC
Make and Model: abc

Reading and Writing Comma Separated values:
Enter:
123,abcd,abcd,<ENTER>
123,abcd,abcd,
123,ABCD,abcd,
opeator== (cstring):
operator== with cstring works
opeator== (Vehicle):
operator== with Vehicle works
Construction validations:
Invalid Vehicle Object
Invalid Vehicle Object
Invalid Vehicle Object
Invalid Vehicle Object
Invalid Vehicle Object
Invalid Vehicle Object
Input validations:
Enter:
123456789<ENTER>
abc<ENTER>
abc<ENTER>
Enter Licence Plate Number: 123456789
Invalid Licence Plate, try again: abc
Enter Make and Model: abc
Parking Spot Number: N/A
Licence Plate: ABC
Make and Model: abc

Enter:
abc<ENTER>
a<ENTER>
ab<ENTER>
Enter Licence Plate Number: abc
Enter Make and Model: a
Invalid Make and model, try again: ab
Parking Spot Number: N/A
Licence Plate: ABC
Make and Model: ab

Testing setParkingSpot validation:
Valid setting:
Parking Spot Number: 20
Licence Plate: ABC
Make and Model: ab

invalid setting:
Invalid Vehicle Object



*/