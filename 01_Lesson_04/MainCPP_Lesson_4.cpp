#include <iostream>

	enum class TicTacSymbols
	{
		EMPTY,
		CROSS,
		ZERO
	};

//-------------------------------------------------------

	union MyData
	{
		int n;
		float f;
		char c;	
	};

	struct MyVariant
	{
		MyData data;
		unsigned short isInt : 1;
		unsigned short isFloat : 1;
		unsigned short isChar : 1;
	};

//------------------------------------------------------

	struct Player
	{
		char cName [32] = {};
		int iScore = 0;
	};

//-----------------------------------------------------

	struct TicTacGameField
	{
		bool bPlayersTurn = true;
		bool bIsGameOver = true;
		Player aPlayers[2];
		TicTacSymbols ar[3][3] = {};
	};


int main()
{

	short int iNum1 = 12345; // 2bytes
	std::cout << sizeof(iNum1) << '\n';
	int iNum2 = 2; // 4bytes (default data type. Dependent on the machine or the compiler)
	std::cout << sizeof(iNum2) << '\n';
	long long lNum3 = 100000000000LL; // 8bytes
	std::cout << sizeof(lNum3) << '\n';
	char cSymb4 = 'A'; // 1byte
	std::cout << sizeof(cSymb4) << '\n';
	bool bIsTrue5 = 1; // 1byte
	std::cout << sizeof(bIsTrue5) << '\n';
	float fNum6 = 3.1415f; // 4bytes
	std::cout << sizeof(fNum6) << '\n';
	double dNum7 = 2.758460234; // 8bytes
	std::cout << sizeof(dNum7) <<'\n';
	

	TicTacSymbols ar[3][3] = {
	       	{TicTacSymbols::EMPTY, TicTacSymbols::EMPTY, TicTacSymbols::EMPTY},
	       	{TicTacSymbols::EMPTY, TicTacSymbols::EMPTY, TicTacSymbols::EMPTY},
	       	{TicTacSymbols::EMPTY, TicTacSymbols::EMPTY, TicTacSymbols::EMPTY}
       		};



	for(size_t i = 0; i < 3; i++)
	{
		for(size_t j = 0; j < 3; j++)
		{
			std::cout << "ar[ " << i << " ][ " << j << "] = " << static_cast<int>(ar[i][j]) << " ";
		}
		std::cout << '\n';
	}
	std::cout << '\n';

	MyVariant variant;
	variant.data.c = 'A';
        variant.isChar = 1;
	variant.isInt = 0;
	variant.isFloat = 0;
	std::cout << "Char: " << variant.data.c << ";\tflag isChar: "<< variant.isChar << "; flag isInt: " << variant.isInt << "; flag isFloat: " << variant.isFloat <<  std::endl;

	variant.data.n = 35;
	variant.isChar = 0;
	variant.isInt = 1;
	variant.isFloat = 0;
	std::cout << "Int: " << variant.data.n << ";\tflag isChar: "<< variant.isChar << "; flag isInt: " << variant.isInt << "; flag isFloat: " << variant.isFloat <<  std::endl;

	variant.data.f = 0.49685;
	variant.isChar = 0;
	variant.isInt = 0;
	variant.isFloat = 1;
	std::cout << "Float: " << variant.data.f << ";\tflag isChar: "<< variant.isChar << "; flag isInt: " << variant.isInt << "; flag isFloat: " << variant.isFloat <<  std::endl;


	return 0;
}
