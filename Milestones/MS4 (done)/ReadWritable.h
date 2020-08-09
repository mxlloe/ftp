/* 

Name: Sean Ramolete
ID: 155074198

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments. 

-----------------------------------------------------------*/

#pragma once
#ifndef SDDS_READWRITABLE_H__
#define SDDS_READWRITABLE_H__

#include <iostream>
using namespace std;

namespace sdds {
class ReadWritable {
    bool m_csvFlag; //Separate comma value flag

public:
    ReadWritable();
    bool isCsv() const;
    void setCsv(bool csvFlag);
    virtual ostream& write(ostream& os) const = 0;
    virtual istream& read(istream& is) = 0;
    virtual ~ReadWritable() {}
};
ostream& operator<<(ostream& os, const ReadWritable& rw);
istream& operator>>(istream& is, ReadWritable& rw);
}

#endif