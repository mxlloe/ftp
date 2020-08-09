// Sean Ramolete
// 155074198
// I've done all the coding myself with some youtube tutorials and obviously the professors original source code.

#include "Car.h"
#include "iostream"

using namespace std;

namespace sdds {
Car::Car() {
    m_carWash = false;
}
Car::Car(const char* license, const char* makeModel) : Vehicle(license, makeModel) {
    m_carWash = false;
}
istream& Car::read(istream& is) {
    if (isCsv()) {
        Vehicle::read(is);
        is >> m_carWash;
        is.ignore(2000, '\n');
    } else {
        cout << endl
             << "Car information entry" << endl;
        Vehicle::read(is);
        cout << "Carwash while parked? (Y)es/(N)o: ";
        string yesno;
        getline(is, yesno, '\n');
        if (is.fail()) {
            is.clear();
            is.ignore(1000, '\n');
            yesno = "a";
        }
        while (yesno != "Y" && yesno != "y" && yesno != "N" && yesno != "n") {
            cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
            getline(is, yesno, '\n');
            if (is.fail()) {
                is.clear();
                is.ignore(1000, '\n');
                yesno = "a";
            }
        }
        m_carWash = (yesno == "Y" || yesno == "y");
    }
    return is;
}
ostream& Car::write(ostream& os) const {
    if (isEmpty()) {
        os << "Invalid Car Object" << endl;
    } else {
        if (isCsv()) {
            os << "C,";
            Vehicle::write(os);
            os << m_carWash << endl;
        } else {
            os << "Vehicle type: Car" << endl;
            Vehicle::write(os);
            if (m_carWash) {
                os << "With Carwash" << endl;
            } else {
                os << "Without Carwash" << endl;
            }
        }
    }
    return os;
}
}