#include <iostream>
#include <fstream>
#include <cstring>


//Написать программу, которая создаст два текстовых
//файла (*.txt), примерно по 50-100 символов в каждом
//(особого значения не имеет с каким именно содержимым).
//Имена файлов запросить у польлзователя.

 
int main()
{
    std::cout << "Hello, dear user!" << std::endl;
    std::cout << "Please, enter the name of the first file" << std::endl;
    std::string sFileName = "";
    std::cin >> sFileName;
    sFileName = sFileName + ".txt";
 
    const char* sText1 = "Given an array of integers fnums "
        "and an integer target, return indices of the two numbers "
        "such that they add up to target. You may assume that each "
        "input would have exactly one solution, and you may not use "
        "the same element twice. You can return the answer in any order.";
 
 
 
    std::ofstream File1;
    File1.open(sFileName);
    if (File1.is_open())
    {
        File1.write(sText1, strlen(sText1));
    
    }
    else
    {
        std::cout << "Could not open the file " << sFileName << "." << std::endl;
    
    }
 
    File1.close();
 
    std::cout << "Please, enter the name of the first file" << std::endl;
    sFileName = "";
    std::cin >> sFileName;
    sFileName = sFileName + ".txt";
 
    const char* sText2 = "You are given two non - empty linked lists "
        "representing two non - negative integers.The "
        "digits are stored in reverse order, and each of "
        "their nodes contains a single digit.Add the two "
        "numbersand return the sum as a linked list.";
 
    std::ofstream File2;
    File2.open(sFileName);
    if (File2.is_open())
    {
        File2.write(sText2, strlen(sText2));
    
    }
    else
    {
        std::cout << "Could not open the file " << sFileName << "." << std::endl;
    
    }
 
    File2.close();
 
    return 0;

}
