#include <iostream>
#include "mylib.h"


//Создайте проект из 2х cpp файлов и заголовочного (main.cpp,
//mylib.cpp, mylib.h) во втором модуле mylib объявить 3 функции:
//для инициализации массива (типа float), печати его на экран и
//подсчета количества отрицательных и положительных
//элементов. Вызывайте эти 3-и функции из main для работы с
//массивом.
//Сделайте это задание добавив свой неймспейс во втором
//модуле.

int main()
{
    std::cout << "Hello, dear user!" << std::endl;
    float fArray[uiArraySize] = {};

    MyNS::PrintArray(fArray, uiArraySize);
    MyNS::InitializeArray(fArray, uiArraySize);
    MyNS::PrintArray(fArray, uiArraySize);
    MyNS::ArrayValuesCount(fArray, uiArraySize);

    return 0;
}