#include <iostream>

extern const int a;
extern const int b;
extern const int c;
extern const int d;

int main()
{

	// Написать программу, вычисляющую выражение a * (b + (c / d))
	// и выводящую результат с плавающей точкой, где a, b, c, d
	// – целочисленные константы, объявленные и
	// инициализированные в другом cpp файле. Используйте static_cast или
	// С-Style cast к float чтобы выполнить точное деление. Используйте extern
	double dResult = (a * (b + (static_cast<double>(c) / d))); 
	std::cout << dResult << std::endl;

	//Дано целое число. Если оно меньше или равно 21, то
	//выведите на экран разницу между этим числом и числом 21.
	//Если же заданное число больше, чем 21, необходимо вывести
	//удвоенную разницу между этим числом и 21. При выполнении
	//задания следует использовать тернарный оператор (?:)
	
	double dNumber;
	std::cout << "Please, enter the number: ";
	std::cin >> dNumber;
	dNumber = (dNumber <= 21) ? (dNumber - 21) : (dNumber - 21) * 2;
	std::cout << dNumber << std::endl;	

	//Описать трёхмерный целочисленный массив, размером
	//3х3х3 и указатель на значения внутри массива и при помощи
	//операции разыменования вывести на экран значение
	//центральной ячейки получившегося куба [1][1][1]

	int ar[3][3][3] = {};
	int*ptr = &ar[1][1][1];
	std::cout << "The value of ar[1][1][1] is " << *ptr << std::endl;
	std::cout << "Please, enter the new value of ar[1][1][1]: ";
	int iValue = 0;
	std::cin >> iValue;
	*ptr = iValue;
	std::cout << "The new value of ar[1][1][1] is " << *ptr << std::endl;

	return 0;
}
