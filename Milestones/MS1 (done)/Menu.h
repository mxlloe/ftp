/*FULLNAME: SEAN RAMOLETE
STUDENT ID: 155074198
*/

/*I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_MENU_H
#define SDDS_MENU_H

namespace sdds
{
    const int MAX_NO_OF_ITEMS{10};

    class MenuItem
    {
        friend class Menu;

        char *menu_name{nullptr};

        MenuItem();             // default constructor
        MenuItem(const char *); // 1-arg constructor

        ~MenuItem(); // destructor

        MenuItem(const MenuItem &) = delete;            // disabled copy constructor
        MenuItem &operator=(const MenuItem &) = delete; // disabled copy assignment operator

        friend std::ostream &operator<<(std::ostream &, const MenuItem &); // output stream overload... is it needed?
    };

    class Menu
    {
    private:
        char *menu_title{nullptr};
        MenuItem items[MAX_NO_OF_ITEMS];
        int num_of_menu_items{0}; // number of items in MenuItem array
        int indentation_val{0};

    public:
        Menu();                      // default constructor
        ~Menu();                     // default destructor
        Menu(const char *, int = 0); // 3 arg constructor

        Menu(const Menu &);            // copy constructor
        Menu &operator=(const Menu &); // copy assignment operator

        Menu operator=(const char *); // string assignment operator

        explicit operator bool() const; // boolean cast overload
        bool isEmpty() const;           // isEmpty function
        void display() const;           // display function
        void add(const char *);         // add function
        int run() const;                      // run function
        operator int() const;        // integer cast overload
    };
    Menu &operator<<(Menu&, const char*); // input stream overload
} // namespace sdds

#endif // SDDS_MENU_H