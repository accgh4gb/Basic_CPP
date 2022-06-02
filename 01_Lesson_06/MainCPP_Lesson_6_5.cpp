#include <iostream>
#include <fstream>
#include <string>

//Написать программу, которая проверяет присутствует
//ли указанное пользователем при запуске программы слово
//в указанном пользователем файле (для простоты
//работаем только с латиницей). Используем функцию find
//которая есть в строках std::string.

 
int main()
{
    std::ifstream ReadFile1;
    std::cout << "Hello, dear user!" << std::endl;
    std::cout << "Please, enter the name of the file in which the word will be searched" << std::endl;
    std::string sFileName;
    std::cin >> sFileName;
    ReadFile1.open(sFileName + ".txt");
    std::cout << "Please, enter a word for searching" << std::endl;
    std::string sKeyWord = "";
    std::cin >> sKeyWord;
    std::string sBuffer;
    
    if (ReadFile1.is_open())
    {
        bool IsFind = false;
        
        while (!ReadFile1.eof())
        {
            getline(ReadFile1, sBuffer);
            
            if (sBuffer.find(sKeyWord) != std::string::npos)
            {
                IsFind = true;
                break;
            }
        }
        
        if (IsFind)
        {
            std::cout << "The word has been found" << std::endl;
        }
        else
        {
            std::cout << "The word " << sKeyWord << " does not exist in this sentence." << std::endl;
        }
    
    }
    else
    {
        std::cout << "Could not open the file " << std::endl;
    
    }
 
    ReadFile1.close();
 
    system("pause");
    
    return 0;
}
