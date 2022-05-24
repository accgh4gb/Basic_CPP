#include <iostream>

int main()
{
	//Написать программу, проверяющую что сумма двух
	//(введенных с клавиатуры) чисел лежит в пределах от 10 до 20
	//(включительно), если да – вывести строку "true", в противном
	//случае – "false";
	
	int iFirstValue = 0;
	int iSecondValue = 0;
	std::cout << "Hello, dear user!" << std::endl;
	std::cout << "Please, enter the first value: " << std::endl;
	std::cin >> iFirstValue;
	std::cout << "Please, enter the second value: " << std::endl;
	std::cin >> iSecondValue;
	
	int iSumm = iFirstValue + iSecondValue;
	if(iSumm >= 10 && iSumm <= 20)
	{
		std::cout << "true" << std::endl;
	}
	else
	{
		std::cout << "false" << std::endl;
	}

	return 0;
}
