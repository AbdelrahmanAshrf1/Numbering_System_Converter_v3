#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsConvertor.h"

using namespace std;

class clsHexadecimalConvertorScreen :protected clsScreen, protected clsConvertor
{
private:

	static void PerformMenuOptions(enConversionType ConversionType)
	{
		switch (ConversionType)
		{
		case clsConvertor::enConversionType::Decimal:

			_Result = to_string(HexadecimalToDecimal(_Input));
			PrintResult(_Result);
			break;

		case clsConvertor::enConversionType::Binary:

			_Result = HexadecimalToBinary(_Input);
			PrintResult(_Result);
			break;

		case clsConvertor::enConversionType::Octal:

			_Result = HexadecimalToOctal(_Input);
			PrintResult(_Result);
			break;

		case clsConvertor::enConversionType::Hexadecimal:

			PrintResult(_Input);
			break;

		case clsConvertor::enConversionType::MainMenu:
			break;
		}
	}

public:

	static void ShowBinaryConvertorScreen()
	{
		DrawHeaderScreen("\t Hexadecimal Convertor");

		_Input = GetUserInput(enConversionType::Hexadecimal);

		DrawMenuOptions();

		enConversionType option = _ReadMainMenuOption();
		PerformMenuOptions(option);
	}
};
