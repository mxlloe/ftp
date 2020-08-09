// Sean Ramolete
// 155074198
// I've done all the coding myself with some youtube tutorials and obviously the professors original source code.

#include "Parking.h"
#include "Car.h"
#include "Menu.h"
#include "Motorcycle.h"
#include "string"
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

namespace sdds {
Parking::Parking() {
    setEmpty();
}
Parking::Parking(const char* fileName, int noOfSpots) {
    setEmpty();
    if (fileName && strlen(fileName) > 0 && noOfSpots >= 10 && noOfSpots <= MAX_PARKING_SPOTS) {
        m_fileName = new char[strlen(fileName) + 1];
        strcpy(m_fileName, fileName);
        m_noOfSpots = noOfSpots;
        for (int i = 0; i < m_noOfSpots; i++) {
            m_parkingSpots[i] = nullptr;
        }
        m_noParked = 0;
    }
    if (loadData()) {
        m_parkMenu = Menu("Parking Menu, select an action:");
        m_parkMenu << "Park Vehicle"
                   << "Return Vehicle"
                   << "List Parked Vehicles"
                   << "Close Parking (End of day)"
                   << "Exit Program";
        m_vehicleMenu = Menu("Select type of the vehicle:", 1);
        m_vehicleMenu << "Car"
                      << "Motorcycle"
                      << "Cancel";
    } else {
        cerr << "Error in data file" << endl;
    }
}
Parking::~Parking() {
    saveData();
    clearMemory();
}
int Parking::run() {
    int error = 1;
    bool done = false;
    if (!isEmpty()) {
        error = 0;
        do {
            parkingStatus();
            int parkChoice = m_parkMenu;
            if (parkChoice == 1) { //Park vehicle
                parkVehicle();
            } else if (parkChoice == 2) { //Return Vehicle
                returnVehicle();
            } else if (parkChoice == 3) { //List Parked Vehicles
                listVehicles();
            } else if (parkChoice == 4) { //Close Parking
                done = closeParking();
            } else if (parkChoice == 5) { //Exit
                done = exitParking();
                if (done) {
                    cout << "Exiting program!" << endl;
                }
            } else { //error
                cerr << "Parking menu error - unrecognizable option selected" << endl;
                done = true;
            }
        } while (!done);
    }
    return error;
}
void Parking::setEmpty() {
    m_fileName = nullptr;
    m_noOfSpots = 0;
    m_noParked = -1;
}
void Parking::clearMemory() {
    delete[] m_fileName;
    m_fileName = nullptr;
    for (int i = 0; i < m_noOfSpots; i++) {
        delete m_parkingSpots[i];
        m_parkingSpots[i] = nullptr;
    }
}
bool Parking::isEmpty() {
    return (m_noOfSpots == 0 && m_noParked == -1);
}
void Parking::parkingStatus() {
    cout << "****** Seneca Valet Parking ******" << endl;
    cout << "*****  Available spots: ";
    cout.width(4);
    cout.setf(ios::left);
    cout << (m_noOfSpots - m_noParked) << " *****" << endl;
    cout.unsetf(ios::left);
}
void Parking::parkVehicle() {
    if (isFull()) {
        cout << "Parking is full" << endl;
    } else {
        int choice = m_vehicleMenu;
        if (choice == 1) { //car
            int i = nextSpot();
            m_parkingSpots[i] = new Car;
            cin >> *m_parkingSpots[i];
            //if license not in system
            if (!isInSystem(*m_parkingSpots[i], i)) {
                m_parkingSpots[i]->setParkingSpot(i + 1);
                m_noParked++;
                cout << endl;
                cout << "Parking Ticket" << endl;
                m_parkingSpots[i]->setCsv(false);
                cout << *m_parkingSpots[i] << endl;
            } else {
                cout << "Can not park; license plate already in the system!" << endl;
                m_parkingSpots[i]->setCsv(false);
                cout << *m_parkingSpots[i] << endl;
                delete m_parkingSpots[i];
                m_parkingSpots[i] = nullptr;
            }
        } else if (choice == 2) { //motorcycle
            int i = nextSpot();
            m_parkingSpots[i] = new Motorcycle;
            cin >> *m_parkingSpots[i];
            //if license not in system
            if (!isInSystem(*m_parkingSpots[i], i)) {
                m_parkingSpots[i]->setParkingSpot(i + 1);
                m_noParked++;
                cout << endl;
                cout << "Parking Ticket" << endl;
                m_parkingSpots[i]->setCsv(false);
                cout << *m_parkingSpots[i] << endl;
            } else {
                cout << "Can not park; license plate already in the system!" << endl;
                m_parkingSpots[i]->setCsv(false);
                cout << *m_parkingSpots[i] << endl;
                delete m_parkingSpots[i];
                m_parkingSpots[i] = nullptr;
            }
        } else if (choice == 3) { //cancel
            cout << "Parking cancelled" << endl;
        } else { //error
            cerr << "Vehicle menu error - unrecognizable option selected" << endl;
        }
    }
}
int Parking::nextSpot() {
    bool found = false;
    int nextSpot = 0;
    if (isFull()) {
        cerr << "Critical error in nextSpot: function being called when full" << endl;
    }
    for (int i = 0; i < m_noOfSpots && !found; i++) {
        if (!m_parkingSpots[i]) {
            nextSpot = i;
            found = true;
        }
    }
    if (!found) {
        cerr << "Critical error in nextSpot: nextSpot not found" << endl;
    }
    return nextSpot;
}
void Parking::returnVehicle() {
    cout << "Return Vehicle" << endl;
    char temp_license[9];
    cout << "Enter Licence Plate Number: ";
    //extra spot to check for valid size
    cin.get(temp_license, 10);
    if (cin.fail()) {
        cin.clear();
    }
    cin.ignore(2000, '\n');
    while (strlen(temp_license) > 8 || strlen(temp_license) < 1) {
        cout << "Invalid Licence Plate, try again: ";
        cin.get(temp_license, 10);
        if (cin.fail()) {
            cin.clear();
        }
        cin.ignore(2000, '\n');
    }
    for (int i = 0; temp_license[i]; i++) {
        temp_license[i] = toupper(temp_license[i]);
    }
    cout << endl;
    bool found = false;
    int j = 0;
    for (j = 0; j < m_noOfSpots && !found; j++) {
        if (m_parkingSpots[j]) {
            if (*m_parkingSpots[j] == temp_license) {
                cout << "Returning: " << endl;
                m_parkingSpots[j]->setCsv(false);
                cout << *m_parkingSpots[j] << endl;
                delete m_parkingSpots[j];
                m_parkingSpots[j] = nullptr;
                m_noParked--;
                found = true;
            }
        }
    }
    if (!found) {
        cout << "License plate " << temp_license << " Not found" << endl
             << endl;
    }
}
void Parking::listVehicles() {
    cout << "*** List of parked vehicles ***" << endl;
    if (!isEmpty()) {
        for (int i = 0; i < m_noOfSpots; i++) {
            if (m_parkingSpots[i] != nullptr) {
                m_parkingSpots[i]->setCsv(false);
                cout << *m_parkingSpots[i];
                cout << "-------------------------------" << endl;
            }
        }
    }
}
bool Parking::closeParking() {
    bool closing = false;
    if (m_noParked == 0) {
        cout << "Closing Parking" << endl;
        closing = true;
    } else {
        cout << "This will Remove and tow all remaining vehicles from the parking!" << endl;
        cout << "Are you sure? (Y)es/(N)o: ";
        string answer;
        getline(cin, answer, '\n');
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            answer = "a";
        }
        while (answer != "Y" && answer != "y" && answer != "N" && answer != "n") {
            cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
            getline(cin, answer, '\n');
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                answer = "a";
            }
        }
        closing = (answer == "Y" || answer == "y");
        if (closing == true) {
            cout << "Closing Parking" << endl;
            for (int i = 0; i < m_noOfSpots; i++) {
                if (m_parkingSpots[i]) {
                    cout << endl;
                    cout << "Towing request" << endl;
                    cout << "*********************" << endl;
                    m_parkingSpots[i]->setCsv(false);
                    cout << *m_parkingSpots[i];
                    delete m_parkingSpots[i];
                    m_parkingSpots[i] = nullptr;
                }
            }
        } else {
            cout << "Aborted!" << endl;
        }
    }
    return closing;
}
bool Parking::exitParking() {
    string answer;
    cout << "This will terminate the program!" << endl;
    cout << "Are you sure? (Y)es/(N)o: ";
    getline(cin, answer, '\n');
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        answer = "a";
    }
    while (answer != "Y" && answer != "y" && answer != "N" && answer != "n") {
        cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
        getline(cin, answer, '\n');
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            answer = "a";
        }
    }
    return (answer == "Y" || answer == "y");
}
bool Parking::loadData() {
    bool loaded = false;
    if (!isEmpty()) {
        ifstream dataFile(m_fileName, ios::in);
        bool done = false;
        Vehicle* t_vehicle = nullptr;
        for (int i = 0; i < m_noOfSpots && !done; i++) {
            char type[2];
            dataFile.get(type, 2, ',');
            dataFile.ignore();
            if (dataFile.eof()) {
                done = true;
                loaded = true;
            } else {
                int j = 0;
                if (type[0] == 'C') {
                    t_vehicle = new Car;
                    t_vehicle->setCsv(true);
                    dataFile >> *t_vehicle;
                    j = t_vehicle->getParkingSpot() - 1;
                    m_parkingSpots[j] = t_vehicle;
                } else if (type[0] == 'M') {
                    t_vehicle = new Motorcycle;
                    t_vehicle->setCsv(true);
                    dataFile >> *t_vehicle;
                    j = t_vehicle->getParkingSpot() - 1;
                    m_parkingSpots[j] = t_vehicle;
                } else {
                    cerr << "Error in loadData: unrecognizable vehicle type" << endl;
                    done = true;
                }

                if (dataFile.fail()) {
                    delete m_parkingSpots[j];
                    m_parkingSpots[j] = nullptr;
                    done = true;
                    loaded = false;
                } else {
                    m_noParked++;
                    loaded = true;
                }
            }
            t_vehicle = nullptr;
        }
        dataFile.clear();
        dataFile.close();
    }
    return loaded;
}
void Parking::saveData() {
    if (!isEmpty()) {
        ofstream dataFile(m_fileName, ios::out);
        for (int i = 0; i < m_noOfSpots; i++) {
            if (m_parkingSpots[i]) {
                m_parkingSpots[i]->setCsv(true);
                dataFile << *m_parkingSpots[i];
            }
        }
    }
}
bool Parking::isInSystem(const Vehicle& src, int currentPlace) {
    bool inSystem = false;
    for (int i = 0; i < m_noOfSpots && !inSystem; i++) {
        if (m_parkingSpots[i] && i != currentPlace) {
            inSystem = (src == *m_parkingSpots[i]);
        }
    }
    return inSystem;
}
bool Parking::isFull() {
    return (m_noOfSpots == m_noParked);
}
}