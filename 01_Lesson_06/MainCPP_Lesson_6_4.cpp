#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

//Написать функцию, «склеивающую» файлы, полученные
//предыдущем уроке в третий текстовый файл
//(имя файлов спросить у пользователя).


 
int main()
{
    std::ifstream ReadFile1;
    ReadFile1.open("first.txt");
    std::ifstream ReadFile2;
    ReadFile2.open("second.txt");
    std::ofstream WriteFile;
    std::cout << "Hello, dear user!" << std::endl;
    std::cout << "Please, enter the name of the first file" << std::endl;
    std::string sFileName = "";
    std::cin >> sFileName;
    sFileName = sFileName + ".txt";
    WriteFile.open(sFileName);
    std::string sBuffer;
    if (ReadFile1.is_open())
    {
        while (!ReadFile1.eof())
        {
            getline(ReadFile1, sBuffer);
            WriteFile.write(&sBuffer[0], strlen(&sBuffer[0]));
            WriteFile.put(' ');
        
        }
        ReadFile1.close();
    
    }
    else
    {
        std::cout << "Could not open the file " << std::endl;
    
    }
 
    if (ReadFile2.is_open())
    {
        while (!ReadFile2.eof())
        {
            getline(ReadFile2, sBuffer);
            WriteFile.write(&sBuffer[0], strlen(&sBuffer[0]));
        
        }
        ReadFile2.close();
    
    }
    else
    {
        std::cout << "Could not open the file " << std::endl;
    
    }
 
    WriteFile.close();
 
    system("pause");
 
    
    return 0;
}
