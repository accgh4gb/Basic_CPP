#include "mylib.h"
#include <ctime>

void InitializeArray(float* fArray, const size_t size)
{
    srand(time(0)); // автоматическая рандомизация
    for (size_t i = 0; i < size; ++i)
    {
        fArray[i] = -100 + rand() % ((100 + 1) - (-100));
    }
}


void ArrayValuesCount(const float* fArray, const size_t size)
{
    size_t NegValue = 0; // автоматическая рандомизация

    for (size_t i = 0; i < size; ++i)
    {
        if (fArray[i] <= 0)
        {
            NegValue++;
        }
    }

    std::cout << "The array has " << size - NegValue << " positive values and " << NegValue << " negative values" << std::endl;
}

void PrintArray(const float* fArray, const size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        std::cout << fArray[i] << " "; 
    }
    std::cout << std::endl;
}
