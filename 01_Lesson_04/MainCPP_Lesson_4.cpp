#include <iostream>

int main()
{
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
}

{
	//Написать программу, выводящую на экран строку “true”, если
	//две целочисленные константы, объявленные в её начале либо
	//обе равны десяти сами по себе, либо их сумма равна десяти.
	//Иначе "false"

	
	const int iFirstValue1 = 10;
	const int iSecondValue1 = 10;
		
	int iSumm1 = iFirstValue1 + iSecondValue1;
	
	if(iSumm1 == 10 || iFirstValue1 == 10 && iSecondValue1 == 10)
	{
		std::cout << "true" << std::endl;
	}
	else
	{
		std::cout << "false" << std::endl;
	}
}

{
	//Написать программу которая выводит на экран список всех
	//нечетных чисел от 1 до 50. Например: "Your numbers: 1 3 5 7 9
	//11 13 ...". Для решения используйте любой С++ цикл.
	
	std::cout << "Your numbers: ";
	
	for(size_t i = 0; i <= 50; i++)
	{
		if(i & 1)
		{
			std::cout << i << " ";
		}
	}
	std::cout << std::endl;
	

}

	return 0;
}
