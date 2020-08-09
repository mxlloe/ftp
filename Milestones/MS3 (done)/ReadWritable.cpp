/* 

Name: Sean Ramolete
ID: 155074198

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments. 

-----------------------------------------------------------*/

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