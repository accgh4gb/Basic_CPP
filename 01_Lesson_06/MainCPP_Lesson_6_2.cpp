#include <iostream>
#include <cstdlib>
#include <ctime>

//Динамически выделить матрицу 4х4 типа int.
//Инициализировать ее псевдослучайными числами через
//функцию rand. Вывести на экран. Разбейте вашу
//программу на функции которые вызываются из main.


int** CteateArray(int** ptrArray, const size_t M, const size_t N)
{
    ptrArray = new int *[M]; // Выделение памяти под одномерный массив указателей
    
    for (size_t i = 0; i < M; ++i)
    {
        ptrArray[i] = new int [N]; // Выделяем массив под одномерный int массив  
    }
    return ptrArray;
}

void ArrayInitialize(int** ptrArray, const size_t M, const size_t N)// Функция заполнения
{
    srand(time(0));
    for(size_t i = 0; i < M; ++i)
    {
        for(int j = 0;  j < N;  ++j)
        {
            ptrArray[i][j] = rand();
        }
    }
}

void PrintArray(int** ptrArray, const size_t M, const size_t N)
{
    for (size_t i = 0; i < M; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            std::cout << ptrArray[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}



int main()
{
    const size_t M = 4; // Количество элементов M x N
    const size_t N = 4;
    int** ptrArray;    

    ptrArray = CteateArray(ptrArray, M, N);
    ArrayInitialize(ptrArray, M, N);
    PrintArray(ptrArray, M, N);

    for (size_t i = 0; i < M; ++i)
    {
        delete [] ptrArray[i]; // Освобождаем i-тый одномерный int массив
    }
    delete [] ptrArray; // Удаляем массив указателей
    ptrArray = nullptr; // Обнуляем указатель
    
    return 0;
}
