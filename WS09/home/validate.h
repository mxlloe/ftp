// Sean Ramolete
// 155074198

#ifndef VALIDATE_H
#define VALIDATE_H

template <typename T>
bool validate(const T &&minimum, const T testValue[], int num_of_elements, bool results[])
{

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