#ifndef VALIDATE_H
#define VALIDATE_H

template <typename T>
bool validate(const T &&minimum, const T testValue[], int num_of_elements, bool results[])
{
    /* 

    - accepts 4 arguments: 
        1) a minimum (type T)
        2) array of test values (type T)
        3) number of elements in the array
        4) array of bools for results
    - returns a bool 
        - true only if ALL test value elements are greater than the minimum, false otherwise
    - save each result of the validation in the boolean array
    - design function in a way that all type T objects are not copied or modified in the function

    */

    bool all_good = true;

    for (int index = 0; index < num_of_elements; index++)
    {
        if (testValue[index] <= minimum)
        {
            all_good = false;
        }
        results[index] = (testValue[index] >= minimum);
    }

    return all_good;
}

#endif // VALIDATE_H