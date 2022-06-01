#include <iostream>
#include <fstream>
#include <string>


//Написать программу, которая создаст два текстовых
//файла (*.txt), примерно по 50-100 символов в каждом
//(особого значения не имеет с каким именно содержимым).
//Имена файлов запросить у польлзователя.



int main()
{
    std::string sFileName; // Имя файлов
    std::cout << "Enter the name of the first file: ";
    std::cin >> sFileName;
    std::cout << std::endl;
    std::ofstream fout1;
    fout1.open(sFileName);
    
    if (fout1.is_open())
    {
        fout1 << "Выделить в памяти динамический одномерный массив типа int. Размер массива запросить у пользователя. Инициализировать его числами степенями двойки: 1, 2, 4, 8, 16, 32, 64, 128 ... Вывести массив на экран. Не забыть освободить память. =) Разбить программу на функции." << std::endl;
    fout1.close();
    }

    std::cout << "Enter the name of the second file: ";
    std::cin >> sFileName;
    std::cout << std::endl;
    std::ofstream fout2;
    fout2.open(sFileName);
    
    if (fout2.is_open())
    {
        fout2 << "Динамически выделить матрицу 4х4 типа int." <<
 "Инициализировать ее псевдослучайными числами через" << "функцию rand. Вывести на экран. Разбейте вашу" <<
"программу на функции которые вызываются из main" << std::endl;
    fout2.close();
    }
            
    return 0;
}
