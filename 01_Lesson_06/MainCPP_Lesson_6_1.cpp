#include <iostream>

//Выделить в памяти динамический одномерный массив
//типа int. Размер массива запросить у пользователя.
//Инициализировать его числами степенями двойки: 1, 2, 4,
//8, 16, 32, 64, 128 ... Вывести массив на экран. Не забыть
//освободить память. =) Разбить программу на функции.

void vInvite(size_t &iArraySize)
{
    std::cout << "Hello, dear user!" << std::endl;
    std::cout << "Please, enter the value of array size: ";
    std::cin >> iArraySize;
}

void vCreateDynamicArray(int *pArray, size_t &iArraySize)
{
    vInvite(iArraySize);

    if(iArraySize <= 0)
    {
        throw "Wrong value";
    }
    else
    {
        pArray = new int [iArraySize];
    }
}


int main()
{
    int * pArray;
    size_t iArraySize = 0;
    
    vCreateDynamicArray(pArray, iArraySize);   
    
    for (size_t i = 0; i < iArraySize; ++i)
    {
        pArray[i] = 1 << i;
    }

    for (size_t i = 0; i < iArraySize; ++i)
    {
        std::cout << pArray[i] << " ";
    } 
    std::cout << std::endl; 
    
    delete[] pArray;
    pArray = nullptr; 
    return 0;
}
