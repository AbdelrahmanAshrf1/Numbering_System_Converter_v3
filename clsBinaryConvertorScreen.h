#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsConvertor.h"

using namespace std;

class clsBinaryConvertorScreen :protected clsScreen, protected clsConvertor
{
private:

	static void PerformMenuOptions(enConversionType ConversionType)
	{
		switch (ConversionType)
		{
		case enConversionType::Decimal:

			_Result = to_string(BinaryToDecimal(_Input));
			PrintResult(_Result);
			break;

		case enConversionType::Binary:

			PrintResult(_Input);
			break;

		case enConversionType::Octal:

			_Result = BinaryToOctal(_Input);
			PrintResult(_Result);
			break;

		case enConversionType::Hexadecimal:

			_Result = BinaryToHexadecimal(_Input);
			PrintResult(_Result);
			break;

		case enConversionType::MainMenu:
			break;
		}
	}

public:

	static void ShowBinaryConvertorScreen()
	{
		DrawHeaderScreen("\t Binary Convertor");

		_Input = GetUserInput(enConversionType::Binary);

		DrawMenuOptions();

		enConversionType option = _ReadMainMenuOption();
		PerformMenuOptions(option);
	}
};
