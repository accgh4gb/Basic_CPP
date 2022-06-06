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
    std::ifstream ReadFile;
    std::cout << "Hello, dear user!" << std::endl;
    std::cout << "Please, enter the name of the file in which the word will be searched" << std::endl;
    std::string sFileName;
    std::cin >> sFileName;
    ReadFile.open(sFileName + ".txt");
    std::cout << "Please, enter a word for searching" << std::endl;
    std::string sKeyWord = "";
    std::cin >> sKeyWord;
    std::string sBuffer;
    
    if (ReadFile.is_open())
    {
        bool IsFind = false;
        
        while (!ReadFile.eof())
        {
            getline(ReadFile, sBuffer);
            
            if (sBuffer.find(sKeyWord) != std::string::npos)
            {
                IsFind = true;
                break;
                ReadFile.close();
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
 
 
    system("pause");
    
    return 0;
}
