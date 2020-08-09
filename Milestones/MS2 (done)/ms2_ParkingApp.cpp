/* ------------------------------------------------------
Final Project Milestone 2
Module: Parking
Filename: ms2_ParkingApp.cpp
Version 1.0
Author	Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date      Reason
2020/7/04  Preliminary release
-----------------------------------------------------------*/
#include "Parking.h"
#include <iostream>
using namespace sdds;
int main() {
   Parking P("ParkingData.csv"), bad1(nullptr),bad2("");
   bad1.run();
   bad2.run();
   P.run();
   std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;
   P.run();
   return 0;
}

/*
Output sample:
loading data from ParkingData.csv
Error in data file
Error in data file
****** Seneca Valet Parking ******
Parking Menu, select an action:
1- Park Vehicle
2- Return Vehicle
3- List Parked Vehicles
4- Close Parking (End of day)
5- Exit Program
> 1
    Select type of the vehicle:
    1- Car
    2- Motorcycle
    3- Cancel
    > 1
Parking Car
****** Seneca Valet Parking ******
Parking Menu, select an action:
1- Park Vehicle
2- Return Vehicle
3- List Parked Vehicles
4- Close Parking (End of day)
5- Exit Program
> 1
    Select type of the vehicle:
    1- Car
    2- Motorcycle
    3- Cancel
    > 2
Parking Motorcycle
****** Seneca Valet Parking ******
Parking Menu, select an action:
1- Park Vehicle
2- Return Vehicle
3- List Parked Vehicles
4- Close Parking (End of day)
5- Exit Program
> 1
    Select type of the vehicle:
    1- Car
    2- Motorcycle
    3- Cancel
    > 3
Cancelled parking
****** Seneca Valet Parking ******
Parking Menu, select an action:
1- Park Vehicle
2- Return Vehicle
3- List Parked Vehicles
4- Close Parking (End of day)
5- Exit Program
> 2
Returning Vehicle
****** Seneca Valet Parking ******
Parking Menu, select an action:
1- Park Vehicle
2- Return Vehicle
3- List Parked Vehicles
4- Close Parking (End of day)
5- Exit Program
> 3
Listing Parked Vehicles
****** Seneca Valet Parking ******
Parking Menu, select an action:
1- Park Vehicle
2- Return Vehicle
3- List Parked Vehicles
4- Close Parking (End of day)
5- Exit Program
> 4
Closing Parking
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
****** Seneca Valet Parking ******
Parking Menu, select an action:
1- Park Vehicle
2- Return Vehicle
3- List Parked Vehicles
4- Close Parking (End of day)
5- Exit Program
> 5
This will terminate the program!
Are you sure? (Y)es/(N)o: abc
Invalid response, only (Y)es or (N)o are acceptable, retry: Yes
Invalid response, only (Y)es or (N)o are acceptable, retry: No
Invalid response, only (Y)es or (N)o are acceptable, retry: y
Exiting program!
Saving data into ParkingData.csv


*/