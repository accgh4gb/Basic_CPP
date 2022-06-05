#include <iostream>

#define MAX_VALUE 10
#define PRINT_TRUE std::cout << "true" << std::endl
#define PRINT_FALSE std::cout << "false" << std::endl;
#define CHECK(a)(0 < a && a < MAX_VALUE) ? PRINT_TRUE : PRINT_FALSE

//Описать макрокоманду (через директиву define),
//проверяющую, входит ли переданное ей число (введенное с
//клавиатуры) в диапазон от нуля (включительно) до переданного
//ей второго аргумента (исключительно) и возвращает true или
//false, вывести на экран «true» или «false»



int main()
{
    std::cout << "Hello, dear user!" << std::endl;
    std::cout << "Please, enter a value" << std::endl;
    int value = 0;
    std::cin >> value;
    CHECK(value);
    return 0;
}
