#pragma once
#include <iostream>
#include <iomanip>
#include "clsString.h"

using namespace std;

class clsScreen
{
protected:

	static void DrawHeaderScreen(string Title,string SubTitle = "")
	{
        cout << clsString::Tabs(5) << "______________________________________";
        cout << "\n\n" << clsString::Tabs(5) << Title;

        if (SubTitle != "")
        {
            cout << "\n" << clsString::Tabs(5) << SubTitle;
        }

        cout << "\n" << clsString::Tabs(5) << "______________________________________\n\n";
	}

    static void DrawMenuOptions()
    {
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t   Convert to :\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t[1] Decimal.\n";
        cout << setw(37) << left << "" << "\t\t[2] Binary .\n";
        cout << setw(37) << left << "" << "\t\t[3] Octal .\n";
        cout << setw(37) << left << "" << "\t\t[4] HexaDecimal .\n";
        cout << setw(37) << left << "" << "===========================================\n";
    }

    static void PrintResult(string Result)
    {
        cout << clsString::Tabs(5) << "______________________________________";
        cout << "\n\n" << clsString::Tabs(5) << "Result :  " << Result;
        cout << "\n" << clsString::Tabs(5) << "______________________________________\n\n";
    }
};

