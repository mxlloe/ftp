/**********************************************/
/*  Student:    Yathavan Parameshwaran        */
/*  Student #:  070 692 140                   */
/*  Assignment: Final Project: MS1: Menu.cpp  */
/*  Course:     OOP244 (retake)               */
/*  Professor:  Andrei Sajeniouk              */
/*  Date:       July 11, 2020                 */
/**********************************************/

#include "Menu.h"

namespace sdds
{
    /* MenuItem class */

    /* default constructor: sets object to safe empty state */
    MenuItem::MenuItem()
    {
        this->menu_name = nullptr;
    }

    /* 1-arg constructor: sets menu_name to incoming string */
    MenuItem::MenuItem(const char *incoming_str)
    {
        if (incoming_str == nullptr)
        {
            this->menu_name = nullptr;
        }
        else
        {
            int str_size = std::strlen(incoming_str);
            this->menu_name = new char[str_size + 1];
            std::strncpy(this->menu_name, incoming_str, str_size);
            this->menu_name[str_size] = '\0';
        }
    }

    /* destructor: deallocates (frees) any previously allocated memory */
    MenuItem::~MenuItem()
    {
        if (this->menu_name != nullptr)
        {
            delete[] this->menu_name;
            this->menu_name = nullptr;
        }
    }

    /* output stream operator overload: prints the incoming object to the console */
    std::ostream &operator<<(std::ostream &os, const MenuItem &obj)
    {
        os << obj.menu_name << std::endl;
        return os;
    }

    /* Menu class */

    /* default constructor: sets the object to a safe empty state */
    Menu::Menu()
    {
        this->menu_title = nullptr;
        this->items[0].menu_name = nullptr;
        this->num_of_menu_items = 0;
        this->indentation_val = 0;
    }

    /* default destructor: deallocates (frees) and previously allocated memory */
    Menu::~Menu()
    {
        if (this->menu_title != nullptr)
        {
            delete[] this->menu_title;
            this->menu_title = nullptr;
        }
    }

    /* 2-arg constructor: creates menu with incoming_str as title */
    Menu::Menu(const char *incoming_str, int incoming_size)
    {
        if (incoming_size > 0)
        {
            this->indentation_val = incoming_size;
        }

        this->menu_title = new char[std::strlen(incoming_str) + 1];
        std::strncpy(this->menu_title, incoming_str, std::strlen(incoming_str));
        this->menu_title[std::strlen(incoming_str)] = '\0';
    }

    /* copy constructor */
    Menu::Menu(const Menu &incoming_obj)
    {
        this->menu_title = nullptr;
        *this = incoming_obj;
    }

    /* copy assignment operator */
    Menu &Menu::operator=(const Menu &incoming_obj)
    {
        if (this != &incoming_obj)
        {
            if (this->menu_title != nullptr)
            {
                delete[] this->menu_title;
                this->menu_title = nullptr;
            }

            if (incoming_obj.isEmpty()) // if incoming object is empty, delete the current object
            {
                this->num_of_menu_items = 0;
                this->indentation_val = 0;

                for (int index = 0; index < MAX_NO_OF_ITEMS; index++)
                {
                    if (this->items[index].menu_name != nullptr)
                    {
                        delete[] this->items[index].menu_name;
                        this->items[index].menu_name = nullptr;
                    }
                }
            }
            else
            {
                this->indentation_val = incoming_obj.indentation_val;

                if (incoming_obj.menu_title != nullptr)
                {
                    if (this->menu_title != nullptr)
                    {
                        delete[] this->menu_title;
                        this->menu_title = nullptr;
                    }

                    this->menu_title = new char[std::strlen(incoming_obj.menu_title) + 1];
                    std::strncpy(this->menu_title, incoming_obj.menu_title, std::strlen(incoming_obj.menu_title));
                    this->menu_title[std::strlen(incoming_obj.menu_title)] = '\0';
                }

                if (incoming_obj.num_of_menu_items > 0)
                {
                    for (int index = 0; index < incoming_obj.num_of_menu_items; index++)
                    {
                        if (this->items[index].menu_name != nullptr)
                        {
                            delete[] this->items[index].menu_name;
                            this->items[index].menu_name = nullptr;
                        }

                        this->items[index].menu_name = new char[std::strlen(incoming_obj.items[index].menu_name) + 1];
                        std::strncpy(this->items[index].menu_name, incoming_obj.items[index].menu_name, std::strlen(incoming_obj.items[index].menu_name));
                        this->items[index].menu_name[std::strlen(incoming_obj.items[index].menu_name)] = '\0';
                    }
                }
                else // if no menu items in incoming obj, then clear current object's array
                {
                    for (int index = 0; index < MAX_NO_OF_ITEMS; index++)
                    {
                        if (this->items[index].menu_name != nullptr)
                        {
                            delete[] this->items[index].menu_name;
                            this->items[index].menu_name = nullptr;
                        }
                    }
                }
                this->num_of_menu_items = incoming_obj.num_of_menu_items;
            }
        }

        return *this;
    }

    /* const char* assignment operator */
    Menu Menu::operator=(const char *incoming_str)
    {
        if (this->menu_title != nullptr)
        {
            delete[] this->menu_title;
            this->menu_title = nullptr;
        }

        this->menu_title = new char[std::strlen(incoming_str) + 1];
        std::strncpy(this->menu_title, incoming_str, std::strlen(incoming_str));
        this->menu_title[std::strlen(incoming_str)] = '\0';

        return *this;
    }

    /* boolean cast overload: returns status of Menu */
    Menu::operator bool() const
    {
        if (this->menu_title != nullptr && (this->num_of_menu_items > 0 && this->items[0].menu_name != nullptr))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    /* isEmpty query: returns status of Menu empty status */
    bool Menu::isEmpty() const
    {
        return (this->menu_title == nullptr && this->num_of_menu_items <= 0);
    }

    /* display query: prints the current Menu to the standard output stream */
    void Menu::display() const
    {
        int indent = this->indentation_val * 4;
        if (this->isEmpty())
        {
            std::cout << "Invalid Menu!" << std::endl;
        }
        else
        {
            std::cout << std::setw(indent) << "";
            std::cout << this->menu_title << std::endl;

            if (this->num_of_menu_items == 0)
            {
                std::cout << "No Items to display!" << std::endl;
            }
            else
            {
                indent = indent == 0 ? 0 : indent + 1;

                for (int index = 0; index < num_of_menu_items; index++)
                {
                    std::cout << std::setw(indent) << index + 1 << "- ";
                    std::cout << this->items[index];
                }

                indent = indent == 0 ? 0 : indent + 1;
                std::cout << std::setw(indent) << "> "; // user selection prompt
            }
        }
    }

    /* add method: add a menu item to the current menu */
    void Menu::add(const char *incoming_str)
    {
        if (!this->isEmpty())
        {
            if (incoming_str == nullptr)
            {
                delete[] this->menu_title;
                this->menu_title = nullptr;

                this->num_of_menu_items = 0;
                this->indentation_val = 0;

                for (int index = 0; index < MAX_NO_OF_ITEMS; index++)
                {
                    if (this->items[index].menu_name != nullptr)
                    {
                        delete[] this->items[index].menu_name;
                        this->items[index].menu_name = nullptr;
                    }
                }
            }
            else if (this->num_of_menu_items < MAX_NO_OF_ITEMS)
            {
                new (&this->items[this->num_of_menu_items++]) MenuItem(incoming_str);
            }
        }        
    }

    /* run function: displays menu and accepts user choice */
    int Menu::run() const
    {
        this->display();

        if (this->num_of_menu_items > 0)
        {
            int choice = 0;

            while (choice <= 0 || choice > this->num_of_menu_items)
            {
                std::cin >> choice;

                if (!std::cin)
                {
                    std::cout << "Invalid Integer, try again: ";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                else if (choice <= 0 || choice > this->num_of_menu_items)
                {
                    std::cout << "Invalid selection, try again: ";

                    if (!std::cin) // if bad cin
                    {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                }
            }

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return choice;
        }
        else
        {
            return 0;
        }
    }

    /* integer cast overload: returns user's choice */
    Menu::operator int() const
    {
        return this->run();
    }

    /* insertion operator overload: add new menu items to current menu */
    Menu &operator<<(Menu &obj, const char *str)
    {
        obj.add(str);
        return obj;
    }

} // namespace sdds
