#include <iostream>
#include <fstream>
#include <cstring>

//Объявить структуру Сотрудник с различными полями.
//Сделайте для нее побайтовое выравнивание с помощью
//директивы pragma pack. Выделите динамически переменную
//этого типа. Инициализируйте ее. Выведите ее на экран и ее
//размер с помощью sizeof. Сохраните эту структуру в текстовый
//файл.

#pragma pack(push, 1)
struct Employee
{
    const char* FirstName = nullptr;
    const char* SecondName = nullptr;
    unsigned short age = 0;
    double salary = 0;
};
#pragma pack(pop)


int main(int argc, char* argv[])
{
    Employee* pEmployee = new Employee;
    std::cout << "Hello, dear user!" << std::endl;

    std::cout << "Please, enter the first name of the new employee: ";
    std::string sFName = "";
    std::cin >> sFName;
    pEmployee->FirstName = new char [sizeof(sFName)];
    strcpy(const_cast<char*>(pEmployee->FirstName), &sFName[0]);

    std::cout << "Please, enter the second name of the new employee: ";
    std::string sSName = "";
    std::cin >> sSName;
    pEmployee->SecondName = new char [sizeof(sSName)];
    strcpy(const_cast<char*>(pEmployee->SecondName), &sSName[0]);

    std::cout << "Please, enter the age of the new employee: ";
    std::cin >> pEmployee->age;

    std::cout << "Please, enter the salary of the new employee: ";
    std::cin >> pEmployee->salary;
    std::cout << std::endl;
    
    std::cout << "The new employee" << std::endl;
    std::cout << "The Name of the new employee is: " << pEmployee->FirstName << " " << pEmployee->SecondName << "." << std::endl;
    
    std::cout << "The age of the new employee is: " << pEmployee->age << "." << std::endl;
    
    std::cout << "The salary of the new employee is: " << pEmployee->salary << "." << std::endl;
    
    std::cout << "Size of structure Employee is: " << sizeof(*pEmployee) << " bytes" << std::endl;

//=====================OUT_FILE==========================

    std::ofstream fout("Employee_data.txt");

    fout << "The new employee" << std::endl;
    fout << "The Name of the new employee is: " << pEmployee->FirstName << " " << pEmployee->SecondName << "." << std::endl;
    fout << "The age of the new employee is: " << pEmployee->age << "." << std::endl;
    fout << "The salary of the new employee is: " << pEmployee->salary << "." << std::endl;
    fout << "Size of structure Employee is: " << sizeof(*pEmployee) << " bytes" << std::endl;

    fout.close();

//=====================BINARY_OUT_FILE====================    

    const std::string sFileName = "Employee_struct.bin";
    std::ofstream foutbin(sFileName, std::ios_base::binary);
        
    if (foutbin.is_open())
    {
        foutbin.write(reinterpret_cast<char*>(pEmployee), sizeof(Employee));
        foutbin.write(reinterpret_cast<char*>(const_cast<char*>(pEmployee->FirstName)), sizeof(*(pEmployee->FirstName)));
        foutbin.write(reinterpret_cast<char*>(const_cast<char*>(pEmployee->SecondName)), sizeof(*(pEmployee->SecondName)));
        foutbin.write(reinterpret_cast<char*>(&pEmployee->age), sizeof(pEmployee->age));
        foutbin.write(reinterpret_cast<char*>(&pEmployee->salary), sizeof(pEmployee->salary));
        foutbin.close();
    }
    
//====================READING_CHECK========================
    Employee NewEmployee = {};
    std::ifstream fin(sFileName, std::ios_base::binary);
    
    if(fin.is_open())
    {
        fin.read(reinterpret_cast<char*>(&NewEmployee), sizeof(Employee));
        fin.read(reinterpret_cast<char*>(const_cast<char*>(NewEmployee.FirstName)), sizeof(*(NewEmployee.FirstName)));
        fin.read(reinterpret_cast<char*>(const_cast<char*>(NewEmployee.FirstName)), sizeof(*(NewEmployee.SecondName)));
        fin.read(reinterpret_cast<char*>(&NewEmployee.age), sizeof(NewEmployee.age));
        fin.read(reinterpret_cast<char*>(&NewEmployee.salary), sizeof(NewEmployee.salary));
        fin.close();
    }
    
    std::cout << NewEmployee.SecondName << " " << NewEmployee.FirstName << std::endl;
                        
    delete[] pEmployee->FirstName;
    pEmployee->FirstName = nullptr;
                              
    delete[] pEmployee->SecondName;
    pEmployee->SecondName = nullptr;
                                        
    delete pEmployee; // освобождаем захваченную структурой память
    pEmployee = nullptr; // обнуляем указатель)

    return 0;

}
