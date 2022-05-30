#include <iostream>


//Написать функцию, которой на вход подаётся
//одномерный массив и число n (может быть положительным,
//или отрицательным), при этом метод должен циклически
//сместить все элементы массива на n позиций.

void PrintArray(const int* arr, const int arrSize)
{
    for (size_t i = 0; i < arrSize; i++)
    {
        std::cout << arr[i] << " ";
    
    }
    std::cout << std::endl;
}
 
void MoveValues(int *iArray, const size_t arrSize, int iValue)
{
 
    if(iValue < 0)
    {
        iValue = -iValue;
        iValue = iValue % arrSize;
    }
    else
    {
        iValue = iValue % arrSize;
        iValue = arrSize - iValue;
    }

    int TmpArray[arrSize] = {};

    for(size_t i = iValue, j = 0; i < arrSize, j < arrSize; i++, j++)
    {
        if(i < arrSize)
        {
            TmpArray[j] = iArray[i];
        }
        else
        {
            i = 0;
            TmpArray[j] = iArray[i];
        }
    } 
 
    PrintArray(TmpArray, arrSize);
}
  
int main()
{
    
    int iArray[8] = {2, 43, 114, -63, 0, 6, -78, 10};
    
    const size_t arrSize = sizeof(iArray) / sizeof(*iArray);
    
    PrintArray(iArray, arrSize);
    
    int N = 0;
    std::cout << "Hello, dear user!" << std::endl;
    std::cout << "Please, enter the value: " << std::endl;
    std::cin >> N;
    
    if(arrSize == 0)
    {
        std::cout << "The array is empty!" << std::endl;
    }
    else
    {
        MoveValues(iArray, arrSize, N);
    }
    
    return 0;
}
