// Sean Ramolete
// 155074198
// I've done all the coding myself with some youtube tutorials and obviously the professors original source code.

#pragma once
#ifndef SDDS_READWRITABLE_H__
#define SDDS_READWRITABLE_H__

#include <iostream>
#include <fstream>

namespace sdds {
class ReadWritable {
    bool m_csvFlag; //comma seperate value flag

public:
    ReadWritable();
    bool isCsv() const;
    void setCsv(bool csvFlag);
    virtual std::ostream& write(std::ostream& os) const = 0;
    virtual std::istream& read(std::istream& is) = 0;
    virtual ~ReadWritable() {}
};
std::ostream& operator<<(std::ostream& os, const ReadWritable& rw);
std::istream& operator>>(std::istream& is, ReadWritable& rw);
}

#endif