#include <iostream>

//Задайте массив типа int. Пусть его размер задается через
//директиву препроцессора #define. Инициализируйте его через
//ввод с клавиатуры. Напишите для него свою функцию
//сортировки (например Пузырьком). Реализуйте перестановку
//элементов как макрокоманду SwapINT(a, b). Вызывайте ее из
//цикла сортировки

#define ARRAY_SIZE 10 

#define SwapINT(a, b, c) \
c = a;\
a = b;\
b = c;

void PrintArray(const int* iArray, const size_t size)
{
    for (size_t i = 0; i < ARRAY_SIZE; ++i)
    {
        std::cout << iArray[i] << " ";
    }
    std::cout << std::endl;
}

void iArrayInitialize(int* iArray, const size_t size)
{
    if (size <= 0) 
    {
        std::cout << "Wrong size of array" << std::endl;
    }
    else
    {
        for (size_t i = 0; i < ARRAY_SIZE; ++i)
        {
            int value = 0;
            std::cout << "Please, enter the value of iArray[" << i << "] ";
            std::cin >> value;
            iArray[i] = value;
        }
    }
}

void iArrayBubbleSort(int* iArray, const size_t size) // Функция сортировки "пузырьком"
{
    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        for (int j = 0; j < ARRAY_SIZE - 1; ++j)
        {
            if (iArray[j] > iArray[j + 1])
            {
                int tmp_value = 0; // создаем дополнительную переменную
                SwapINT(iArray[j], iArray[j + 1], tmp_value); // меняем местами с помощьюмакроса SwapINT
            }
        }
    }
}

int main()
{
    int iArray[ARRAY_SIZE] = {};

    PrintArray(iArray, ARRAY_SIZE);
    
    iArrayInitialize(iArray, ARRAY_SIZE);
   
    PrintArray(iArray, ARRAY_SIZE);
   
    iArrayBubbleSort(iArray, ARRAY_SIZE);

    PrintArray(iArray, ARRAY_SIZE);

    return 0;
}
