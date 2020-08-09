// Sean Ramolete
// 155074198
// I've done all the coding myself with some youtube tutorials and obviously the professors original source code.

#include "ReadWritable.h"
#include <iostream>

using namespace std;

namespace sdds {
ReadWritable::ReadWritable() {
    m_csvFlag = false;
}
bool ReadWritable::isCsv() const {
    return m_csvFlag;
}
void ReadWritable::setCsv(bool csvFlag) {
    m_csvFlag = csvFlag;
}
ostream& operator<<(ostream& os, const ReadWritable& rw) {
    return rw.write(os);
}
istream& operator>>(istream& is, ReadWritable& rw) {
    return rw.read(is);
}
}