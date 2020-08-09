// Sean Ramolete
// 155074198
// I've done all the coding myself with some youtube tutorials and obviously the professors original source code.

#pragma once
#ifndef SDDS_VEHICLE_H__
#define SDDS_VEHICLE_H__

#include "ReadWritable.h"
#include <iostream>

namespace sdds {
const int MAX_LICENSE = 8; // Character limit for license plates
class Vehicle : public ReadWritable {
private:
    char* m_license;
    char* m_makeModel;
    int m_parkSpot;

protected:
    void setEmpty();
    void clearMakeModel();
    void clearLicense();
    bool isEmpty() const;
    void setLicensePlate(const char* license);
    const char* getLicensePlate() const;
    const char* getMakeModel() const;
    void setMakeModel(const char* makeModel);

public:
    Vehicle();
    Vehicle(const char* license, const char* makeModel);
    ~Vehicle();
    Vehicle(const Vehicle&) = delete;
    Vehicle& operator=(const Vehicle&) = delete;
    int getParkingSpot() const;
    void setParkingSpot(int parkSpot);
    bool operator==(const char* license) const;
    bool operator==(const Vehicle& other) const;
    std::istream& read(std::istream& is);
    std::ostream& write(std::ostream& os) const;
};
}

#endif