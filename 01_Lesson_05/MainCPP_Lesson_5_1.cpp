#include <iostream>

void PrintArray(double *dArray, unsigned int N)
{
    for(size_t i = 0; i < N; i++)
    {
        std::cout << dArray[i] << " ";
    }
    
    std::cout << std::endl;
}


int main()
{
    const unsigned int N = 5;
    double dArray[N] = {3.4, 5.0, 2.75745345, 5.323, 745674.2342342};
    PrintArray(dArray, N);
    
    return 0;
}
