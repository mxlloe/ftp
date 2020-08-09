// Sean Ramolete
// 155074198
// I've done all the coding myself with some youtube tutorials and obviously the professors original source code.


#ifndef SDDS_PARKING_H__
#define SDDS_PARKING_H__

#include "Menu.h"
#include "Vehicle.h"

namespace sdds {
    const int MAX_PARKING_SPOTS = 100;
class Parking {
    char* m_fileName;
    int m_noOfSpots;
    int m_noParked;
    Vehicle* m_parkingSpots[MAX_PARKING_SPOTS];
    Menu m_parkMenu;
    Menu m_vehicleMenu;
    Parking(const Parking& src) = delete;
    Parking& operator=(const Parking& src) = delete;
    void setEmpty();
    void clearMemory();
    bool isEmpty();
    void parkingStatus();
    void parkVehicle();
    void returnVehicle();
    void listVehicles();
    bool closeParking();
    bool exitParking();
    bool loadData();
    void saveData();
    int nextSpot(); //checks for next available spot in array
    bool isInSystem(const Vehicle& src, int currentPlace); //returns true if vehicle is already in system
    bool isFull(); //returns true if parking is full
    
public:
    Parking();
    Parking(const char* dataFile, int noOfSpots);
    ~Parking();
    int run();
};
}

#endif