#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsConvertor.h"

using namespace std;

class clsDecimalConvertorScreen :protected clsScreen ,protected clsConvertor
{
private:

	static void PerformMenuOptions(enConversionType ConversionType)
	{
		switch (ConversionType)
		{
		case clsConvertor::enConversionType::Decimal:

			PrintResult(_Input);
			break;

		case clsConvertor::enConversionType::Binary:

			_Result = DecimalToBinary(stod(_Input));
			PrintResult(_Result);
			break;

		case clsConvertor::enConversionType::Octal:

			_Result = DecimalToOctal(stod(_Input));
			PrintResult(_Result);
			break;

		case clsConvertor::enConversionType::Hexadecimal:

			_Result = DecimalToHexadecimal(stod(_Input));
			PrintResult(_Result);
			break;

		case clsConvertor::enConversionType::MainMenu:
			break;
		}
	}

public:

	static void ShowDecimalConvertorScreen()
	{
		DrawHeaderScreen("\t Decimal Convertor");

		_Input = GetUserInput(enConversionType::Decimal);

		DrawMenuOptions();

		enConversionType option = _ReadMainMenuOption();
		PerformMenuOptions(option);
	}

};

