#include <iostream>

//Задать целочисленный массив, состоящий из элементов 0
//и 1. Например: [ 1, 1, 0, 0, 1, 0, 1, 1, 0, 0  ]. Написать функцию,
//заменяющую в принятом массиве 0 на 1, 1 на 0. Выводить
//на экран массив до изменений и после.

void PrintArray(int* arr, int arrSize)
{
    for (size_t i = 0; i < arrSize; i++)
    {
        std::cout << arr[i] << " ";
    
    }
    std::cout << std::endl;

}
 
void ChangeArray(int* arr, int arrSize)
{
    for (size_t i = 0; i < arrSize; i++)
    {
        arr[i] ^= 1;
    
    }
    std::cout << std::endl;

}


int main()
{
   int arr1[] = {1, 0 , 0, 0, 1, 0, 1, 1, 0, 1, 1, 1};
 
    const size_t arrSize = sizeof(arr1) / sizeof(*arr1);
 
    PrintArray(arr1, arrSize);
 
    ChangeArray(arr1, arrSize);    
 
    PrintArray(arr1, arrSize);
 
    return 0;
}
