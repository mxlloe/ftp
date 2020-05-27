#pragma once
#include "Word.h"
#include "Utils.h"
#include <iostream>
#include <iomanip>

using namespace sdds;
using namespace std;

namespace sdds
{
    void programTitle() {
        cout <<
            "This program reads a text file from the standard input and analyzes and reports" << endl <<
            "the number of words and their occurrences in the text file." << endl;
    }

    void title(const char* value, int len) { // uses iomanip header file
        cout << value << endl;
        cout << setw(len) << left << "Word";
        cout << "No of  occurrence." << endl << "------------------------------------------------" << endl;
    }

    void endList() {
        cout << "------------------------------------------------" << endl;
    }
}