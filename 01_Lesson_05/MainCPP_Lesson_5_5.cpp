#include <iostream>

//Написать функцию, которой передается не пустой
//одномерный целочисленный массив, она должна вернуть
//истину если в массиве есть место, в котором сумма левой и
//правой части массива равны. Примеры: checkBalance([1, 1,
//1, || 2, 1]) → true, checkBalance ([2, 1, 1, 2, 1]) → false,
//checkBalance ([10, || 1, 2, 3, 4]) → true. Абстрактная граница
//показана символами ||, эти символы в массив не входят.


void PrintArray(int* arr, int arrSize)
{
    for (size_t i = 0; i < arrSize; i++)
    {
        std::cout << arr[i] << " ";
    
    }
    std::cout << std::endl;
}
 
void CheckBalance(int *iArray, const size_t arrSize)
{
    bool bFlag = false;
    int iSum1 = 0;
    int iSum2 = 0;
    for(size_t j = 0; j < arrSize - 1; j++)
    {
        iSum1 += iArray[j];
        iSum2 = 0;
        
        for(size_t i = j + 1; i < arrSize; i++)
        {
            iSum2 += iArray[i];
        }
        if(iSum1 == iSum2)
        {
            bFlag = true;
            break;
        }
    } 
    if(bFlag)
    {
        std::cout << "Balance is true!" << std::endl;
    }
    else
    {    
    std::cout << "The balance is false" << std::endl;
    }
}

  
int main()
{
    
    int iArray[5] = {22, -4, 4, 3, -1};
    
    const size_t arrSize = sizeof(iArray) / sizeof(*iArray);
    
    PrintArray(iArray, arrSize);
    
    CheckBalance(iArray, arrSize);
 
    return 0;
}
