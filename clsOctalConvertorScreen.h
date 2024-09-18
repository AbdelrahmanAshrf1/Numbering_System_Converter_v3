#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsConvertor.h"

using namespace std;

class clsOctalConvertorScreen :protected clsScreen, protected clsConvertor
{
private:

	static void PerformMenuOptions(enConversionType ConversionType)
	{
		switch (ConversionType)
		{
		case clsConvertor::enConversionType::Decimal:

			_Result = to_string(OctalToDecimal(_Input));
			PrintResult(_Result);
			break;

		case clsConvertor::enConversionType::Binary:

			_Result = OctalToBinary(_Input);
			PrintResult(_Result);
			break;

		case clsConvertor::enConversionType::Octal:

			PrintResult(_Input);
			break;

		case clsConvertor::enConversionType::Hexadecimal:

			_Result = OctalToHexadecimal(_Input);
			PrintResult(_Result);
			break;

		case clsConvertor::enConversionType::MainMenu:
			break;
		}
	}

public:

	static void ShowOctalConvertorScreen()
	{
		DrawHeaderScreen("\t Octal Convertor");

		_Input = GetUserInput(enConversionType::Octal);

		DrawMenuOptions();

		enConversionType option = _ReadMainMenuOption();
		PerformMenuOptions(option);
	}
};

