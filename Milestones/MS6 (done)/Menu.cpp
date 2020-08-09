// Sean Ramolete
// 155074198
// I've done all the coding myself with some youtube tutorials and obviously the professors original source code.

#include "Menu.h"
#include <cstring>
#include <iostream>

using namespace std;

namespace sdds {
MenuItem::MenuItem() {
    m_itemTitle = nullptr;
}
MenuItem::MenuItem(const char* itemTitle) {
    m_itemTitle = nullptr;
    if (itemTitle && strlen(itemTitle) > 0) {
        setItemTitle(itemTitle);
    }
}
MenuItem::~MenuItem() {
    clearItemMemory();
}
void MenuItem::clearItemMemory() {
    delete[] m_itemTitle;
    m_itemTitle = nullptr;
}
void MenuItem::setItemTitle(const char* n_itemTitle) {
    m_itemTitle = new char[strlen(n_itemTitle) + 1];
    strcpy(m_itemTitle, n_itemTitle);
}
Menu::Menu() {
    setEmpty();
}
Menu::Menu(const char* title, int indentLevel) {
    setEmpty();
    // check for validity of values
    if (title && strlen(title) > 0 && indentLevel >= 0) {
        m_title = new char[strlen(title) + 1];
        strcpy(m_title, title);
        m_indentLevel = indentLevel;
        m_numOfItems = 0;
    }
}
Menu::Menu(const Menu& src) {
    setEmpty();
    if (src.m_title) {
        m_title = new char[strlen(src.m_title) + 1];
        strcpy(m_title, src.m_title);
    } else {
        m_title = nullptr;
    }
    m_indentLevel = src.m_indentLevel;
    m_numOfItems = src.m_numOfItems;
    for (int i = 0; i < src.m_numOfItems; i++) {
        m_MenuItems[i] = new MenuItem;
        m_MenuItems[i]->setItemTitle(src.m_MenuItems[i]->m_itemTitle);
    }
}
Menu& Menu::operator=(const Menu& src) {
    clearTitleMemory();
    clearMenuItemsMemory();
    // checks that the two classes aren't already equal
    if (this != &src) {
        if (src.m_title) {
            m_title = new char[strlen(src.m_title) + 1];
            strcpy(m_title, src.m_title);
        } else {
            m_title = nullptr;
        }
        m_indentLevel = src.m_indentLevel;
        m_numOfItems = src.m_numOfItems;
        for (int i = 0; i < src.m_numOfItems; i++) {
            // previous menuitems array cleared already
            m_MenuItems[i] = new MenuItem;
            m_MenuItems[i]->setItemTitle(src.m_MenuItems[i]->m_itemTitle);
        }
    }
    return *this;
}
Menu::~Menu() {
    clearTitleMemory();
    clearMenuItemsMemory();
}
void Menu::clearTitleMemory() {
    delete[] m_title;
    m_title = nullptr;
}
void Menu::clearMenuItemsMemory() {
    for (int i = 0; i < m_numOfItems; i++) {
        m_MenuItems[i]->clearItemMemory();
        delete m_MenuItems[i];
        m_MenuItems[i] = nullptr;
    }
    m_numOfItems = 0;
}
void Menu::setEmpty() {
    // safe empty values
    m_title = nullptr;
    m_indentLevel = -1;
    m_numOfItems = -1;
    for (int i = 0; i < MAX_NO_OF_ITEMS; i++) {
        m_MenuItems[i] = nullptr;
    }
}
Menu::operator bool() const {
    /* numOfItems is not checked because display() differentiates
       between empty and no list items*/
    return (m_title != nullptr && m_indentLevel >= 0);
}
bool Menu::isEmpty() const {
    /* numOfItems is not checked because display() differentiates
       between empty and no list items*/
    return !(m_title && m_indentLevel >= 0);
}
void Menu::display() const {
    if (isEmpty()) {
        cout << "Invalid Menu!" << endl;
    } else {
        indent(m_indentLevel);
        cout << m_title << endl;
        if (m_numOfItems <= 0) {
            cout << "No Items to display!" << endl;
        } else {
            for (int i = 0; i < m_numOfItems; i++) {
                indent(m_indentLevel);
                cout << i + 1 << "- " << m_MenuItems[i]->m_itemTitle << endl;
            }
        }
    }
}
Menu& Menu::operator=(const char* n_title) {
    if (n_title && strlen(n_title) > 0) {
        clearTitleMemory();
        m_title = new char[strlen(n_title) + 1];
        strcpy(m_title, n_title);
    } else {
        if (m_numOfItems > 0) {
            for (int i = 0; i < m_numOfItems; i++) {
                m_MenuItems[i]->clearItemMemory();
            }
        }
        clearTitleMemory();
        clearMenuItemsMemory();
        setEmpty();
    }
    return *this;
}
void Menu::add(const char* n_menuItem) {
    if (!isEmpty() && m_numOfItems < 10) {
        if (n_menuItem != nullptr) {
            m_MenuItems[m_numOfItems] = new MenuItem;
            m_MenuItems[m_numOfItems]->m_itemTitle = nullptr;
            m_MenuItems[m_numOfItems]->setItemTitle(n_menuItem);
            m_numOfItems++;
        } else {
            for (int i = 0; i < m_numOfItems; i++) {
                m_MenuItems[i]->clearItemMemory();
            }
            clearTitleMemory();
            clearMenuItemsMemory();
            setEmpty();
        }
    }
}
Menu& Menu::operator<<(const char* n_menuItem) {
    add(n_menuItem);
    return *this;
}
int Menu::run() const {
    bool valid = false;
    int choice = 0;
    display();
    if (!isEmpty() && m_numOfItems > 0) {
        indent(m_indentLevel);
        cout << "> ";
        while (!valid) {
            cin >> choice;
            if (cin.fail()) {
                cin.clear();
                cout << "Invalid Integer, try again: ";
            } else {
                if (choice < 1 || choice > m_numOfItems) {
                    cout << "Invalid selection, try again: ";
                } else {
                    valid = true;
                }
            }
            cin.ignore(1000, '\n');
        }
    }
    return choice;
}
Menu::operator int() const {
    return run();
}
void indent(int numOfIndents) {
    for (int i = 0; i < numOfIndents; i++) {
        cout << "    ";
    }
}
}