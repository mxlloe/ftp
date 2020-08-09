#include <fstream>
#include <iostream>
#include <ctype.h>
#include "Parking.h"
using namespace std;
using namespace sdds;
void runParking() {
   Parking P("ParkingData.csv", 11);
   P.run();
}
void pause() {
   cout << "<------------------------" << endl << "Press Enter to continue...";
   cin.ignore(1000, '\n');
}
void ShowDatafile() {
   char ch;
   ifstream file("ParkingData.csv");
   cout << endl << "Content of ParkingData.csv after the program exits" << endl;
   cout << "-----------------------------------------------------------" << endl;
   while (file.get(ch)) {
      cout <<char(tolower(ch));
   }
   cout <<  "-----------------------------------------------------------" << endl;
}
int main() {
   cout << "Pass 1: ------->" << endl;
   runParking();
   ShowDatafile();
   pause();
   cout << "Pass 2: ------->" << endl;
   runParking();
   ShowDatafile();
   pause();
   cout << "Pass 3: ------->" << endl;
   runParking();
   ShowDatafile();
   return 0;
}

/* 
Simple data entry:
Pass 1: --->
3<ENTER>
1<ENTER>
1<ENTER>
aaa<ENTER>
bbb bbb<ENTER>
y<ENTER>
1<ENTER>
2<ENTER>
ccc<ENTER>
ddd ddd<ENTER>
n<ENTER>
1<ENTER>
2<ENTER>
qwe<ENTER>
5<ENTER>
y<ENTER>
<ENTER>
Pass 2: --->
3<ENTER>
4<ENTER>
y<ENTER>
<ENTER>
Pass 3: --->
3<ENTER>
5<ENTER>
y<ENTER>
--------------------------------
Complete data entry:
-------------------------------->
Pass 1: ---------------->
3<ENTER>
1<ENTER>
1<ENTER>
<ENTER>
123456789<ENTER>
aaaa1234<ENTER>
a<ENTER>
ab<ENTER>
yes<ENTER>
n<ENTER>
1<ENTER>
2<ENTER>
aaa<ENTER>
bbb bbb<ENTER>
NO<ENTER>
n<ENTER>
1<ENTER>
3<ENTER>
5<ENTER>
Y<ENTER> (UPPER CASE Y)
<ENTER>
pass 2: -------------->
1<ENTER>
4<ENTER>
n<ENTER>
2<ENTER>
aaa<ENTER>
2<ENTER>
asd123<ENTER>
3<ENTER>
1<ENTER>
3<ENTER>
1<ENTER>
1<ENTER>
asd<ENTER>
Ford<ENTER>
n<ENTER>
4<ENTER>
y<ENTER>
<ENTER>
pass 3: ------------------>
1<ENTER>
2<ENTER>
aaa<ENTER>
bbb bbb<ENTER>
y<ENTER>
3<ENTER>
5<ENTER>
y<ENTER>


*/