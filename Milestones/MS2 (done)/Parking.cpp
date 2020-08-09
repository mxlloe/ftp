/*************************************************/
/*  Student:    Yathavan Parameshwaran           */
/*  Student #:  070 692 140                      */
/*  Assignment: Final Project: MS2: Parking.cpp  */
/*  Course:     OOP244 (retake)                  */
/*  Professor:  Andrei Sajeniouk                 */
/*  Date:       July 17, 2020                    */
/*************************************************/

#include <iostream>
#include <cstring>

#include "Parking.h"

namespace sdds
{
    /* default constructor: sets object to safe empty state */
    Parking::Parking()
    {
        this->file_name = nullptr;
        this->indentation = 0;
        this->parking_menu = Menu();
        this->vehicle_selection_menu = Menu();
    }

    /* 1-arg constructor: create Parking object with name of data file */
    Parking::Parking(const char *incoming_str)
    {
        if (incoming_str == nullptr || incoming_str[0] == '\0')
        {
            this->set_invalid();
        }
        else
        {
            int size = std::strlen(incoming_str);
            this->file_name = new char[size + 1];
            std::strncpy(this->file_name, incoming_str, size);
            this->file_name[size] = '\0';
        }

        if (this->load_data_file())
        {
            this->parking_menu = Menu("Parking Menu, select an action:", 0);

            this->parking_menu.add("Park Vehicle");
            this->parking_menu.add("Return Vehicle");
            this->parking_menu.add("List Parked Vehicles");
            this->parking_menu.add("Close Parking (End of day)");
            this->parking_menu.add("Exit Program");

            this->vehicle_selection_menu = Menu("Select type of the vehicle:", 1);

            this->vehicle_selection_menu.add("Car");
            this->vehicle_selection_menu.add("Motorcycle");
            this->vehicle_selection_menu.add("Cancel");
        }
        else
        {
            std::cout << "Error in data file" << std::endl;
            this->set_invalid();
        }
    }

    /* destructor: deallocates (frees) any previously allocated memory */
    Parking::~Parking()
    {
        this->save_data_file();

        if (this->file_name != nullptr)
        {
            delete[] this->file_name;
            this->file_name = nullptr;
        }
    }

    /* (deleted) copy constructor: copies existing object into new object */
    // Parking::Parking(const Parking &incoming_obj)
    // {
    // this->file_name = nullptr;
    // this->indentation = 0;
    // this->parking_menu = Menu();
    // this->vehicle_selection_menu = Menu();

    // *this = incoming_obj;
    // }

    /* (deleted) copy assignment operator: copies existing object into another already existing object */
    // Parking &Parking::operator=(const Parking &incoming_obj)
    // {
    // if (this != &incoming_obj)
    // {
    //     this->indentation = incoming_obj.indentation;
    //     this->parking_menu = incoming_obj.parking_menu;                     // should call Menu copy-assignment operator
    //     this->vehicle_selection_menu = incoming_obj.vehicle_selection_menu; // same deal

    //     if (this->file_name != nullptr)
    //     {
    //         delete[] this->file_name;
    //         this->file_name = nullptr;
    //     }

    //     this->file_name = new char[std::strlen(incoming_obj.file_name) + 1];
    //     std::strncpy(this->file_name, incoming_obj.file_name, std::strlen(incoming_obj.file_name));
    //     this->file_name[std::strlen(incoming_obj.file_name)] = '\0';
    // }

    // return *this;
    // }

    /* run function: runs Parking module */
    int Parking::run()
    {
        if (!this->isEmpty()) // if Parking is not in an invalid empty state...
        {
            bool exit_val = false;

            while (exit_val == false)
            {
                this->status();

                switch (this->parking_menu.run())
                {
                case 1:
                    this->park_vehicle();
                    continue;
                case 2:
                    this->return_vehicle();
                    continue;
                case 3:
                    this->list_parked_vehicles();
                    continue;
                case 4:
                    if (this->close_parking())
                    {
                        exit_val = true;
                        break;
                    }
                case 5:
                    if (!this->exit_parking_app())
                    {
                        continue;
                    }
                    else
                    {
                        exit_val = true;
                        break;
                    }
                default:
                    continue;
                }
            }

            return this->isEmpty() == true ? 1 : 0;
        }
        else
        {
            return 1;
        }
    }

    /* isEmpty query: returns true if the object is in an invalid empty state, false is valid and usable */
    bool Parking::isEmpty() const
    {
        if (this->indentation == -1)
        {
            return true;
        }
        else if (this->file_name != nullptr && this->indentation >= 0)
        {
            return false;
        }
        else if (this->file_name == nullptr && this->indentation == 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    /* status function */
    void Parking::status() const
    {
        std::cout << "****** Seneca Valet Parking ******" << std::endl;
    }

    /* park vehicle */
    void Parking::park_vehicle() const
    {
        switch (this->vehicle_selection_menu.run())
        {
        case 1:
            std::cout << "Parking Car" << std::endl;
            break;
        case 2:
            std::cout << "Parking Motorcycle" << std::endl;
            break;
        case 3:
            std::cout << "Cancelled parking" << std::endl;
            break;
        default:
            break;
        }
    }

    /* return vehicle */
    void Parking::return_vehicle() const
    {
        std::cout << "Returning Vehicle" << std::endl;
    }

    /* list parked vehicles */
    void Parking::list_parked_vehicles() const
    {
        std::cout << "Listing Parked Vehicles" << std::endl;
    }

    /* close parking */
    bool Parking::close_parking() const
    {
        std::cout << "Closing Parking" << std::endl;
        return true;
    }

    /* exit the Parking application */
    bool Parking::exit_parking_app() const
    {
        char response[16];

        std::cout << "This will terminate the program!" << std::endl;
        std::cout << "Are you sure? (Y)es/(N)o: ";

        while (std::cin.getline(response, 15, '\n'))
        {
            try
            {
                if (std::strlen(response) == 1)
                {
                    if (std::strncmp(response, "Y", 1) == 0 ||
                        std::strncmp(response, "y", 1) == 0 ||
                        std::strncmp(response, "N", 1) == 0 ||
                        std::strncmp(response, "n", 1) == 0)
                    {
                        throw true;
                    }
                    else
                    {
                        throw false;
                    }
                }
                else
                {
                    throw false;
                }
                
            }
            catch(bool glove)
            {
                if (glove)
                {
                    break;
                }
                else
                {
                    std::cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                    continue;
                }
            }
            catch (const std::exception& e)
            {
                std::cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                continue;
            }
        }

        if (std::strncmp(response, "y", 1) == 0)
        {
            std::cout << "Exiting program!" << std::endl;
            return true;
        }
        else
        {
            return false;
        }
        
    }

    /* loads the data file */
    bool Parking::load_data_file()
    {
        if (!this->isEmpty())
        {
            std::cout << "loading data from " << this->file_name << std::endl;
            return true;
        }
        else
        {
            return false;
        }
    }

    /* saves the data into the data file */
    void Parking::save_data_file() const
    {
        if (!this->isEmpty())
        {
            std::cout << "Saving data into " << this->file_name << std::endl;
        }
    }

    void Parking::set_invalid()
    {
        this->indentation = -1;
        this->parking_menu = Menu();
        this->parking_menu = Menu();
        this->file_name = nullptr;
    }

} // namespace sdds