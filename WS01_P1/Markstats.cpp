/* ------------------------------------------------------
Workshop 1 part 2
Module: Markstats
Filename: Markstats.cpp
Version 0.9
Author	Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date       Reason
2020/5/18  Preliminary release
2020/5/19  Added comment to markstat() funciton call
-----------------------------------------------------------*/
#include "Marks.h"
int main() {
   markstat(); // Runs the whole application
   return 0;
}

/*
output:
Mark Stats Program.

Please enter the assessment name: Midterm Test
Please enter the number of marks: 3
Invalid value (5<=value<=50), try again: three
Invalid Number, try again: 3marks
Invalid trailing characters, try again: 9
Please enter 9 marks (0<=Mark<=100):
1> 200
Invalid value (0<=value<=100), try again: 34
2> 89
3> 55
4> 23
5> 50
6> 79
7> 100
8> 60
9> 72
Thank you...
Assessment Name: Midterm Test
----------------
100, 89, 79, 72, 60, 55, 50, 34, 23
Average: 62.4
Number of Passing Marks: 7

*/