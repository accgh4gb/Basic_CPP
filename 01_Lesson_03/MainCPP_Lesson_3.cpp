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

	return 0;
}
