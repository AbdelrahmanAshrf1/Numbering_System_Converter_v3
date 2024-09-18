#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsConvertor.h"
#include "clsInputValidate.h"
#include "clsDecimalConvertorScreen.h"
#include "clsBinaryConvertorScreen.h"
#include "clsOctalConvertorScreen.h"
#include "clsHexadecimalConvertorScreen.h"

using namespace std;

class clsMainMenue :protected clsScreen , private clsConvertor
{
private:

	static void _GoBackToMainMenu()
	{
		cout << setw(37) << left << "" << "\n" << clsString::Tabs(5) << "Press any key to go back to Main Menue...\n";

		system("pause>0");
		ShowMainMenueScreen();
	}

	void static _ShowDecimalConvertorScreen()
	{
		clsDecimalConvertorScreen::ShowDecimalConvertorScreen();
	}

	void static _ShowBinaryConvertorScreen()
	{
		clsBinaryConvertorScreen::ShowBinaryConvertorScreen();
	}

	void static _ShowOctalConvertorScreen()
	{
		clsOctalConvertorScreen::ShowOctalConvertorScreen();
	}

	void static _ShoHexaDecimalConvertorScreen()
	{
		clsHexadecimalConvertorScreen::ShowBinaryConvertorScreen();
	}

	static void _PerformMainMenueOption(clsConvertor::enConversionType ConversionType)
	{
		switch (ConversionType)
		{
		case enConversionType::Decimal:

			system("cls");
			_ShowDecimalConvertorScreen();
			_GoBackToMainMenu();
			break;

		case enConversionType::Binary:

			system("cls");
			_ShowBinaryConvertorScreen();
			_GoBackToMainMenu();
			break;

		case enConversionType::Octal:

			system("cls");
			_ShowOctalConvertorScreen();
			_GoBackToMainMenu();
			break;

		case enConversionType::Hexadecimal:

			system("cls");
			_ShoHexaDecimalConvertorScreen();
			_GoBackToMainMenu();
			break;
		}
	}

public:

	static void ShowMainMenueScreen()
	{
		system("cls");
		DrawHeaderScreen("\t\tMain Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Decimal Convertor.\n";
		cout << setw(37) << left << "" << "\t[2] Binary Convertor.\n";
		cout << setw(37) << left << "" << "\t[3] Octal Convertor.\n";
		cout << setw(37) << left << "" << "\t[4] HexaDecimal Convertor.\n";
		cout << setw(37) << left << "" << "===========================================\n";


		enConversionType option = _ReadMainMenuOption();
		_PerformMainMenueOption(option);
	}
};

