/*************************************************/
/*  Student:    Yathavan Parameshwaran           */
/*  Student #:  070 692 140                      */
/*  Assignment: Final Project: MS2: Parking.h    */
/*  Course:     OOP244 (retake)                  */
/*  Professor:  Andrei Sajeniouk                 */
/*  Date:       July 17, 2020                    */
/*************************************************/

#ifndef SDDS_PARKING_H
#define SDDS_PARKING_H

#include "Menu.h"

namespace sdds
{
    class Parking
    {
    private:
        char *file_name{nullptr};
        int indentation{0};
        Menu parking_menu{Menu()};
        Menu vehicle_selection_menu{Menu()};

        bool isEmpty() const;
        void status() const;
        void park_vehicle() const;
        void return_vehicle() const;
        void list_parked_vehicles() const;
        bool close_parking() const;
        bool exit_parking_app() const;
        bool load_data_file();
        void save_data_file() const;

        void set_invalid();

    public:
        Parking();
        Parking(const char *);
        ~Parking();

        Parking(const Parking &) = delete;
        Parking &operator=(const Parking &) = delete;

        int run();
    };
} // namespace sdds

#endif // SDDS_PARKING_H