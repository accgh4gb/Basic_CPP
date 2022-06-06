#include <iostream>
#include <fstream>
#include <string>

//Написать функцию, «склеивающую» файлы, полученные
//предыдущем уроке в третий текстовый файл
//(имя файлов спросить у пользователя).

void CopyFile(std::ifstream& ReadFile, std::ofstream& WriteFile)
{
    std::string text;

    while(!ReadFile.eof())
    {
        getline(ReadFile, text);
        WriteFile << text << std::endl;
    }
}
 
int main()
{
    std::cout << "Hello, dear user!" << std::endl;
    std::cout << "Please, enter the name of the first file for input" << std::endl;
    std::string sFileName1;
    std::cin >> sFileName1;
    std::ifstream ReadFile1(sFileName1 + ".txt");
    
    
    std::cout << "Please, enter the name of the second file for input" << std::endl;
    std::string sFileName2 = "";
    std::cin >> sFileName2;
    std::ifstream ReadFile2(sFileName2 + ".txt");

    std::cout << "Please, enter the name for source file" << std::endl;
    std::string sFileNameSource = "";
    std::cin >> sFileNameSource;
    std::ofstream WriteFile(sFileNameSource + ".txt");

    if (ReadFile1.is_open() && ReadFile2.is_open() && WriteFile.is_open())
    {
        CopyFile(ReadFile1, WriteFile);
        ReadFile1.close();

        CopyFile(ReadFile2, WriteFile);
        ReadFile2.close();

        WriteFile.close();         
    }
    else
    {
        std::cout << "Could not open the file " << std::endl;
    }
 
    system("pause");
 
    return 0;
}
