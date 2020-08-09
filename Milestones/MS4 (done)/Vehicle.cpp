/* 

Name: Sean Ramolete
ID: 155074198

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments. 

-----------------------------------------------------------*/

#include "Vehicle.h"
#include <cctype>
#include <cstring>
#include <iostream>

using namespace std;

namespace sdds {
void Vehicle::setEmpty() {
    // safe empty values
    m_license = nullptr;
    m_makeModel = nullptr;
    m_parkSpot = -1;
}
void Vehicle::clearMakeModel() {
    delete[] m_makeModel;
    m_makeModel = nullptr;
}
void Vehicle::clearLicense() {
    delete[] m_license;
    m_license = nullptr;
}
bool Vehicle::isEmpty() const {
    return (m_parkSpot < 0);
}
void Vehicle::setLicensePlate(const char* license) {
    clearLicense();
    m_license = new char[strlen(license) + 1];
    strcpy(m_license,  license);
    for (int i = 0; license[i]; i++) {
        m_license[i] = toupper(license[i]);
    }
}
const char* Vehicle::getLicensePlate() const {
    return m_license;
}
const char* Vehicle::getMakeModel() const {
    return m_makeModel;
}
void Vehicle::setMakeModel(const char* makeModel) {
    //clear previous makeModel - either way the makeModel changes here
    clearMakeModel();
    //check if new makemodel is valid
    if (makeModel && strlen(makeModel) >= 2) {
        m_makeModel = new char[strlen(makeModel) + 1];
        strcpy(m_makeModel, makeModel);
    } else {
        setEmpty();
    }
}
Vehicle::Vehicle() : ReadWritable() {
    setEmpty();
}
Vehicle::Vehicle(const char* license, const char* makeModel) : ReadWritable() {
    setEmpty();
    //validity check
    if (license && makeModel && strlen(makeModel) >= 2 && strlen(license) > 0 && strlen(license) <= 8 && strlen(makeModel) > 0) {
        setLicensePlate(license);
        m_makeModel = new char[strlen(makeModel) + 1];
        strcpy(m_makeModel, makeModel);
        setParkingSpot(0);
    }
}
Vehicle::~Vehicle(){
    clearLicense();
    clearMakeModel();
}
int Vehicle::getParkingSpot() const {
    return m_parkSpot;
}
void Vehicle::setParkingSpot(int parkSpot) {
    if (parkSpot >= 0) {
        m_parkSpot = parkSpot;
    } else {
        //clear old makemodel before setting empty
        clearLicense();
        clearMakeModel();
        setEmpty();
    }
}
bool Vehicle::operator==(const char* license) const {
    bool equal = true;
    if (m_license && license && (strlen(m_license) == strlen(license))) {
        for (int i = 0; m_license[i] && equal; i++) {
            if (toupper(m_license[i]) != toupper(license[i])) {
                equal = false;
            }
        }
    } else {
        equal = false;
    }
    return equal;
}
bool Vehicle::operator==(const Vehicle& other) const {
    return other == m_license;
}
istream& Vehicle::read(istream& is) {
    int parkSpot = 0;
    //these have extra length to see if too many characters were entered
    char temp_license[10];
    char temp_makeModel[62];
    if (isCsv()) {
        is >> parkSpot;
        is.ignore(); //ignore comma after parkSpot
        is.get(temp_license, 9, ',');
        is.ignore(2000, ',');
        is.get(temp_makeModel, 61, ',');
        is.ignore(2000, ',');
    } else {
        cout << "Enter Licence Plate Number: ";
        //extra spot to check for valid size
        is.get(temp_license, 10);
        is.ignore(2000, '\n');
        while (strlen(temp_license) > 8) {
            cout << "Invalid Licence Plate, try again: ";
            is.get(temp_license, 10);
            is.ignore(2000, '\n');
        }
        cout << "Enter Make and Model: ";
        //extra spot to check for valid size
        is.get(temp_makeModel, 62);
        is.ignore(2000, '\n');
        while (strlen(temp_makeModel) > 60 || strlen(temp_makeModel) < 2) {
            cout << "Invalid Make and model, try again: ";
            is.get(temp_makeModel, 62);
            is.ignore(2000, '\n');
        }
    }
    if (is.fail()) {
        //empty states this vehicle if is fails
        clearLicense();
        clearMakeModel();
        setEmpty();
        is.clear();
    } else {
        setMakeModel(temp_makeModel);
        setParkingSpot(parkSpot);
        setLicensePlate(temp_license);
    }
    return is;
}
ostream& Vehicle::write(ostream& os) const {
    if (isEmpty()) {
        os << "Invalid Vehicle Object" << endl;
    } else if (isCsv()) {
        if (m_parkSpot == 0) {
            os << "N/A," << m_license << "," << m_makeModel << ",";
        } else {
            os << m_parkSpot << "," << m_license << "," << m_makeModel << ",";
        }
    } else {
        os << "Parking Spot Number: ";
        if (m_parkSpot == 0) {
            os << "N/A" << endl;
        } else {
            os << m_parkSpot << endl;
        }
        os << "Licence Plate: " << m_license << endl;
        os << "Make and Model: " << m_makeModel << endl;
    }
    return os;
}
}