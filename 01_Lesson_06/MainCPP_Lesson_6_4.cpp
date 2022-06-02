#include <iostream>
#include <fstream>
#include <string>

//Написать функцию, «склеивающую» файлы, полученные
//предыдущем уроке в третий текстовый файл
//(имя файлов спросить у пользователя).


 
int main()
{
    std::ifstream ReadFile1;
    std::cout << "Hello, dear user!" << std::endl;
    std::cout << "Please, enter the name of the first file" << std::endl;
    std::string sFileName1 = "";
    std::cin >> sFileName1;
    
    ReadFile1.open(sFileName1 + ".txt");
    
    std::ifstream ReadFile2;
    std::cout << "Please, enter the name of the second file" << std::endl;
    std::string sFileName2 = "";
    std::cin >> sFileName2;
    ReadFile2.open(sFileName2 + ".txt");

    std::ofstream WriteFile;
    std::cout << "Please, enter the name for source file" << std::endl;
    std::string sFileNameSource = "";
    std::cin >> sFileNameSource;
    WriteFile.open(sFileNameSource + ".txt");
    std::string sBuffer;
    if (ReadFile1.is_open())
    {
        while (!ReadFile1.eof())
        {
            getline(ReadFile1, sBuffer);
            //WriteFile.write(&sBuffer[0], strlen(&sBuffer[0]));
            //WriteFile.put(' ');
             WriteFile << sBuffer << std::endl;
        
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
            //WriteFile.write(&sBuffer[0], strlen(&sBuffer[0]));
             WriteFile << sBuffer << std::endl;
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
