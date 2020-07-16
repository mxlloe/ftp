/* ------------------------------------------------------
Final Project Milestone 1
Module: Menu
Filename: ms1_MenuTester.cpp
Version 1.0
Author	Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date      Reason
2020/6/27  Preliminary release
-----------------------------------------------------------*/

#include <iostream>
#include "Utils.h"
#include "Menu.h"
using namespace std;
using namespace sdds;
int showSelection(int n);
void prompt(const char* message);
void pause();
void testMenus(Menu m, Menu sub1, const Menu& sub2);
void TT(const char* title);
int main() {
   TT("M1T1: constructors");
   Menu mainMenu("** Main Menu **");
   Menu subMenu1("** Sub Menu One **", 1);
   Menu subMenu2("** Sub Menu **", 2);
   Menu tempMenu("** Temp **");
   Menu invMenu("** To test Invalid Menu **");

   TT("M1T2: operator<< adding MenuItems");
   tempMenu << "One" << "Two" << "three";


   TT("M1T3: Menu::run()");
   prompt("Do the following: \nabc <ENTER>\n0 <ENTER>\n4 <ENTER>\n3 <ENTER>");
   cout << tempMenu.run() << " selected!" << endl;
   pause();

   TT("M1T4: Menu deep assignment with no items");
   tempMenu = subMenu2;

   TT("M1T5: Reseting Menu title and running an empty menu with no Items");
   tempMenu = "** New Title **"; //<<---- Assignment
   cout << tempMenu.run() << " returned by the Menu with no Items." << endl;
   pause();

   TT("M1T6: Menu::add() and operator<<");
   mainMenu.add("Option one");
   mainMenu.add("Option Two");
   mainMenu.add("Sub Options");
   mainMenu.add("Option four");
   mainMenu.add("Exit");
   subMenu1 << "Selection one" << "Sub Selections two" << "Selection three" << "Selection four";
   subMenu2 << "The first" << "The second" << "The third";

   TT("M1T7: Deep assignment");
   prompt("Do the following: \n1 <ENTER>");
   tempMenu = subMenu2;
   cout << tempMenu.run() << " selected!" << endl;
   pause();


   TT("M1T7: Deep copying, passing const refrence and indentation display");
   testMenus(mainMenu, subMenu1, subMenu2);

   TT("M1T8: operator bool()");
   if (mainMenu) {
      cout << "The mainMenu is valid and usable." << endl;
   }

   TT("M1T9: Invalid Menu and its usage");
   mainMenu.add(nullptr);
   if (!mainMenu) {
      cout << "The mainMenu is invalid(empty) and not usable." << endl;
   }
   mainMenu.run();
   mainMenu.display();
   TT("M1T10: Assigning Menu to an empty Menu");
   subMenu1 = mainMenu;
   subMenu1.run();
   subMenu1.display();
   TT("M1T11: Adding invalid string to render Menu invalid");
   invMenu << nullptr << "This should not be added" << "This shouldn't be added either";
   invMenu.run();
   invMenu.display();
   return 0;
}
int showSelection(int n) {
   cout << "You selected " << n << "." << endl;
   return n;
}

void prompt(const char* message) {
   cout << message << endl;
}
void pause() {
   cout << "Press enter to continue..." << endl;
   cin.ignore(1000, '\n');
}
void testMenus(Menu m, Menu sub1, const Menu& sub2) {
   int selection;
   prompt("Do the following:\n2 <ENTER>\n3 <ENTER>");
   while ((selection = m.run()) != 5) {
      showSelection(selection);
      if (selection == 3) {
         prompt("Do the following:\n2 <ENTER>");
         if (showSelection(sub1) == 2) {
            prompt("Do the following:\n3 <ENTER>\n5 <ENTER>");
            showSelection(sub2);
         }
      }
   }
}
void TT(const char* title) {
   cout << "******************************************************************" << endl;
   cout << title << endl;
   cout << "==================>" << endl;
}

/* Execution Sample:
******************************************************************
M1T1: constructors
==================>
******************************************************************
M1T2: operator<< adding MenuItems
==================>
******************************************************************
M1T3: Menu::run()
==================>
Do the following:
abc <ENTER>
0 <ENTER>
4 <ENTER>
3 <ENTER>
** Temp **
1- One
2- Two
3- three
> abc
Invalid Integer, try again: 0
Invalid selection, try again: 4
Invalid selection, try again: 3
3 selected!
Press enter to continue...

******************************************************************
M1T4: Menu deep assignment with no items
==================>
******************************************************************
M1T5: Reseting Menu title and running an empty menu with no Items
==================>
        ** New Title **
No Items to display!
0 returned by the Menu with no Items.
Press enter to continue...

******************************************************************
M1T6: Menu::add() and operator<<
==================>
******************************************************************
M1T7: Deep assignment
==================>
Do the following:
1 <ENTER>
        ** Sub Menu **
        1- The first
        2- The second
        3- The third
        > 1
1 selected!
Press enter to continue...

******************************************************************
M1T7: Deep copying, passing const refrence and indentation display
==================>
Do the following:
2 <ENTER>
3 <ENTER>
** Main Menu **
1- Option one
2- Option Two
3- Sub Options
4- Option four
5- Exit
> 2
You selected 2.
** Main Menu **
1- Option one
2- Option Two
3- Sub Options
4- Option four
5- Exit
> 3
You selected 3.
Do the following:
2 <ENTER>
    ** Sub Menu One **
    1- Selection one
    2- Sub Selections two
    3- Selection three
    4- Selection four
    > 2
You selected 2.
Do the following:
3 <ENTER>
5 <ENTER>
        ** Sub Menu **
        1- The first
        2- The second
        3- The third
        > 3
You selected 3.
** Main Menu **
1- Option one
2- Option Two
3- Sub Options
4- Option four
5- Exit
> 5
******************************************************************
M1T8: operator bool()
==================>
The mainMenu is valid and usable.
******************************************************************
M1T9: Invalid Menu and its usage
==================>
The mainMenu is invalid(empty) and not usable.
Invalid Menu!
Invalid Menu!
******************************************************************
M1T10: Assigning Menu to an empty Menu
==================>
Invalid Menu!
Invalid Menu!
******************************************************************
M1T11: Adding invalid string to render Menu invalid
==================>
Invalid Menu!
Invalid Menu!




*/