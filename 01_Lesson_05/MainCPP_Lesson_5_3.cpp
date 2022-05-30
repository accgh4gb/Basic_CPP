#include <iostream>

//Задать пустой целочисленный массив размером 8.
//Написать функцию, которая с помощью цикла заполнит его
//значениями 1 4 7 10 13 16 19 22. Вывести массив на экр

void PrintArray(const int* arr, const int arrSize)
{
    for (size_t i = 0; i < arrSize; i++)
    {
        std::cout << arr[i] << " ";
    
    }
    std::cout << std::endl;

}
 
void FillUpArray(int * iArray, const size_t arrSize)
{
    iArray[0] = 1;
    for(size_t i = 1; i < arrSize; i++)
    {
        iArray[i] = iArray [i - 1] + 3;    
    }
}
  
int main()
{
    int iArray[8] = {};
 
    const size_t arrSize = sizeof(iArray) / sizeof(*iArray);
 
    PrintArray(iArray, arrSize);
 
    FillUpArray(iArray, arrSize);
    
    PrintArray(iArray, arrSize);
 
    return 0;
}
