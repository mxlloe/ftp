// Sean Ramolete
// 155074198

#include <iostream>
#include "Basket.h"

#include <iostream>
#include <iomanip>
#include <cstring>

namespace sdds
{
    /* default constructor: sets object to empty state */
    Basket::Basket()
    {
        this->m_fruits = nullptr;
        this->m_cnt = 0;
        this->m_price = 0.0;
    }

    /* destructor: deallocates any previously allocated memory */
    Basket::~Basket()
    {
        if (this->m_fruits != nullptr)
        {
            delete[] this->m_fruits;
            this->m_fruits = nullptr;
        }
    }

    /* 3-arg constructor: used to initialize current object with values at creation time */
    Basket::Basket(Fruit incoming_fruits_array[], int incoming_count, double incoming_price)
    {
        if (incoming_fruits_array[0].m_name[0] != '\0' && incoming_count != 0 && incoming_price != 0.0)
        {
            this->m_fruits = new Fruit[incoming_count];

            for (int index = 0; index < incoming_count; index++)
            {
                std::strncpy(this->m_fruits[index].m_name, incoming_fruits_array[index].m_name, NAME_SIZE);
                this->m_fruits[index].m_name[NAME_SIZE + 1] = '\0';

                this->m_fruits[index].m_qty = incoming_fruits_array[index].m_qty;
            }

            this->m_cnt = incoming_count;

            this->setPrice(incoming_price);
        }
    }

    /* copy constructor */
    Basket::Basket(const Basket &incoming_obj)
    {
        this->m_fruits = nullptr;
        *this = incoming_obj;
    }

    /* copy assignment operator */
    Basket &Basket::operator=(const Basket &incoming_obj)
    {
        if (this != &incoming_obj)
        {
            this->m_cnt = incoming_obj.m_cnt;
            this->m_price = incoming_obj.m_price;

            if (this->m_fruits != nullptr)
            {
                delete[] this->m_fruits;
                this->m_fruits = nullptr;
            }

            this->m_fruits = new Fruit[incoming_obj.m_cnt];

            for (int index = 0; index < incoming_obj.m_cnt; index++)
            {
                std::strncpy(this->m_fruits[index].m_name, incoming_obj.m_fruits[index].m_name, NAME_SIZE);
                this->m_fruits[index].m_name[NAME_SIZE + 1] = '\0';

                this->m_fruits[index].m_qty = incoming_obj.m_fruits[index].m_qty;
            }
        }

        return *this;
    }

    /* setPrice function: sets the price of the basket to the incoming value */
    void Basket::setPrice(double incoming_price)
    {
        this->m_price = incoming_price;
    }

    /* boolean conversion operator: returns true if basket contains any Fruit */
    Basket::operator bool() const
    {
        return this->m_cnt >= 1;
    }

    /* += operator overload: adds an incoming fruit to the basket */
    Basket &Basket::operator+=(Fruit incoming_obj)
    {
        // create temporary array
        Fruit temp_arr[this->m_cnt];

        // copy over existing data into temp arr
        for (int index = 0; index < this->m_cnt; index++)
        {
            std::strncpy(temp_arr[index].m_name, this->m_fruits[index].m_name, NAME_SIZE);
            temp_arr[index].m_name[NAME_SIZE + 1] = '\0';

            temp_arr[index].m_qty = this->m_fruits[index].m_qty;
        }

        // increment fruit count
        this->m_cnt++;

        // deallocate previously allocated memory for fruits
        delete[] this->m_fruits;
        this->m_fruits = nullptr;

        // reallocate new memory with incremented fruit count
        this->m_fruits = new Fruit[this->m_cnt];

        // copy over previously copied over fruits back into newly allocated fruits pointer
        for (int index = 0; index < (this->m_cnt - 1); index++)
        {
            std::strncpy(this->m_fruits[index].m_name, temp_arr[index].m_name, NAME_SIZE);
            this->m_fruits[index].m_name[NAME_SIZE + 1] = '\0';

            this->m_fruits[index].m_qty = temp_arr[index].m_qty;
        }

        // append the new fruit object to the array
        std::strncpy(this->m_fruits[m_cnt - 1].m_name, incoming_obj.m_name, NAME_SIZE);
        this->m_fruits[m_cnt - 1].m_name[NAME_SIZE + 1] = '\0';

        this->m_fruits[m_cnt - 1].m_qty = incoming_obj.m_qty;

        // fin
        return *this;
    }

    /* output stream operator overload: prints incoming Basket object to console */
    std::ostream &operator<<(std::ostream &incoming_ostream_obj, Basket &incoming_basket_obj)
    {
        if (incoming_basket_obj.m_cnt > 0)
        {
            incoming_ostream_obj << "Basket Content:" << std::endl;

            for (int index = 0; index < incoming_basket_obj.m_cnt; index++)
            {
                incoming_ostream_obj << std::setw(10) << std::right << incoming_basket_obj.m_fruits[index].m_name;
                incoming_ostream_obj << ": ";
                incoming_ostream_obj << std::fixed << std::setprecision(2) << incoming_basket_obj.m_fruits[index].m_qty << "kg" << std::endl;
            }

            incoming_ostream_obj << "Price: " << std::fixed << std::setprecision(2) << incoming_basket_obj.m_price << std::endl;
        }
        else
        {
            incoming_ostream_obj << "The basket is empty!" << std::endl;
        }

        return incoming_ostream_obj;
    }
} // namespace sdds