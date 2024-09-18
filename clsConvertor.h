#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <cmath>
#include <stdexcept>
#include <algorithm>
#include "clsString.h"
#include "clsInputValidate.h"

using namespace std;

class clsConvertor
{
protected:

    static string _Input;
    static string _Result;

    enum class enConversionType { Decimal = 1, Binary, Octal, Hexadecimal, MainMenu };

    static enConversionType _ReadMainMenuOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 4]? ";
        short Choice = clsInputValidate<short>::ReadNumberBetween(1, 4, clsString::Tabs(5) + "   Enter Number between 1 to 4 ?");
        return (enConversionType)Choice;
    }

    static string GetUserInput(enConversionType type)
    {
        string str;
        while (true)
        {
            switch (type)
            {
            case enConversionType::Decimal:

                cout << "\n" << clsString::Tabs(5) << "Enter Decimal Number: ";
                getline(cin >> ws, str);
                if (IsValidDecimal(str)) return str;
                break;

            case enConversionType::Binary:

                cout << "\n" << clsString::Tabs(5) << "Enter Binary Number: ";
                getline(cin >> ws, str);
                if (IsValidBinary(str)) return str;
                break;

            case enConversionType::Octal:

                cout << "\n" << clsString::Tabs(5) << "Enter Octal Number: ";
                getline(cin >> ws, str);
                if (IsValidOctal(str)) return str;
                break;

            case enConversionType::Hexadecimal:

                cout << "\n" << clsString::Tabs(5) << "Enter Hexadecimal Number: ";
                getline(cin >> ws, str);
                if (IsValidHexadecimal(str)) return str;
                break;

            default:

                cout << "Invalid conversion type. Please select a valid option.\n";
                type = static_cast<enConversionType>(
                    clsInputValidate<int>::ReadNumberBetween(1, 4 ,"Enter a number between 1 and 4"));
                continue;
            }
            cout << clsString::Tabs(5) << "Invalid input. Please try again.\n";
        }
    }

    static bool IsValidDecimal(string Number)
    {
        if (Number.empty())
            return false;

        for (short i = 0; i < Number.length(); i++)
        {
            if (!(isdigit(Number[i]) || Number[i] == '-' || Number[i] == '.'))
                return false;
        }
        return true;
    }

    static bool IsValidBinary(const string& str)
    {
        return all_of(str.begin(), str.end(), [](char c) { return c == '0' || c == '1' || c == '.' || c == '-'; });
    }

    static bool IsValidOctal(const string& str)
    {
        return all_of(str.begin(), str.end(), [](char c) { return (c >= '0' && c <= '7') || c == '.' || c == '-'; });
    }

    static bool IsValidHexadecimal(const string& str)
    {
        return all_of(str.begin(), str.end(), [](char c) { return (isdigit(c) || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f') || c == '.' || c == '-'); });
    }

    static std::string DecimalToBinary(double decimal) 
    {
        bool isNegative = decimal < 0;
        decimal = std::fabs(decimal);
        int integerPart = static_cast<int>(decimal);
        double fractionPart = decimal - integerPart;
        std::ostringstream result;

        // Convert the integer part to binary
        if (integerPart == 0) 
        {
            result << '0';
        }
        else 
        {
            result << std::bitset<32>(integerPart).to_string().substr(std::bitset<32>(integerPart).to_string().find('1'));
        }

        // Convert the fractional part to binary
        if (fractionPart > 0) 
        {
            result << '.';
            const int maxPrecision = 20;
            int precisionCount = 0;

            while (fractionPart > 0 && precisionCount < maxPrecision) 
            {
                fractionPart *= 2;
                int binaryDigit = static_cast<int>(fractionPart);
                result << binaryDigit;
                fractionPart -= binaryDigit;
                precisionCount++;
            }
        }

        return isNegative ? "-" + result.str() : result.str();
    }

    static double BinaryToDecimal(const string& binary)
    {
        bool isNegative = binary[0] == '-';
        string binaryStr = isNegative ? binary.substr(1) : binary;

        size_t pointPos = binaryStr.find('.');
        string integerPart = binaryStr.substr(0, pointPos);
        string fractionPart = (pointPos == string::npos) ? "" : binaryStr.substr(pointPos + 1);

        double decimalValue = 0.0;
        int power = integerPart.empty() ? 0 : integerPart.length() - 1;

        for (char c : integerPart)
        {
            if (c == '1') decimalValue += std::pow(2, power);
            power--;
        }

        power = -1;
        for (char c : fractionPart)
        {
            if (c == '1') decimalValue += std::pow(2, power);
            power--;
        }

        return isNegative ? -decimalValue : decimalValue;
    }

    static string DecimalToHexadecimal(double decimal)
    {
        if (decimal == 0) return "0";

        bool isNegative = decimal < 0;
        decimal = fabs(decimal);
        int integerPart = static_cast<int>(decimal);
        double fractionPart = decimal - integerPart;
        ostringstream result;

        const string hexCharacters = "0123456789ABCDEF";

        while (integerPart > 0)
        {
            result << hexCharacters[integerPart % 16];
            integerPart /= 16;
        }
       
        string reversedString = result.str();
        reverse(reversedString.begin(), reversedString.end());
        result.str("");  // Clear the stream
        result << reversedString;

        if (fractionPart > 0)
        {
            result << '.';
            const int maxPrecision = 8;
            int precisionCount = 0;

            while (fractionPart > 0 && precisionCount < maxPrecision)
            {
                fractionPart *= 16;
                int digit = static_cast<int>(fractionPart);
                result << hexCharacters[digit];
                fractionPart -= digit;
                precisionCount++;
            }
        }

        return isNegative ? "-" + result.str() : result.str();
    }

    static double HexadecimalToDecimal(const string& hex)
    {
        bool isNegative = hex[0] == '-';
        string hexStr = isNegative ? hex.substr(1) : hex;

        size_t pointPos = hexStr.find('.');
        string integerPart = hexStr.substr(0, pointPos);
        string fractionPart = (pointPos == string::npos) ? "" : hexStr.substr(pointPos + 1);

        double decimalValue = 0.0;
        int power = integerPart.empty() ? 0 : integerPart.length() - 1;

        auto hexCharToDecimal = [](char c) -> int {
            if (c >= '0' && c <= '9') return c - '0';
            if (c >= 'A' && c <= 'F') return c - 'A' + 10;
            if (c >= 'a' && c <= 'f') return c - 'a' + 10;
            throw invalid_argument("Invalid hexadecimal digit");
            };

        for (char c : integerPart)
        {
            decimalValue += hexCharToDecimal(c) * std::pow(16, power);
            power--;
        }

        power = -1;
        for (char c : fractionPart)
        {
            decimalValue += hexCharToDecimal(c) * std::pow(16, power);
            power--;
        }

        return isNegative ? -decimalValue : decimalValue;
    }

    static string DecimalToOctal(double decimal) 
    {
        if (decimal == 0) return "0";

        bool isNegative = decimal < 0;
        decimal = std::fabs(decimal);
        int integerPart = static_cast<int>(decimal);
        double fractionPart = decimal - integerPart;
        std::ostringstream result;

        // Process the integer part
        if (integerPart == 0) 
        {
            result << "0";
        }
        else 
        {
            while (integerPart > 0) 
            {
                result << (integerPart % 8);
                integerPart /= 8;
            }

            string reversedString = result.str();
            reverse(reversedString.begin(), reversedString.end());
            result.str("");  // Clear the stream
            result << reversedString;  
        }

        // Process the fractional part
        if (fractionPart > 0) 
        {
            result << '.';
            const int maxPrecision = 8;
            int precisionCount = 0;

            while (fractionPart > 0 && precisionCount < maxPrecision) 
            {
                fractionPart *= 8;
                int digit = static_cast<int>(fractionPart);
                result << digit;
                fractionPart -= digit;
                precisionCount++;
            }
        }

        return isNegative ? "-" + result.str() : result.str();
    }

    static double OctalToDecimal(const string& octal)
    {
        bool isNegative = octal[0] == '-';
        string octalStr = isNegative ? octal.substr(1) : octal;

        size_t pointPos = octalStr.find('.');
        string integerPart = octalStr.substr(0, pointPos);
        string fractionPart = (pointPos == string::npos) ? "" : octalStr.substr(pointPos + 1);

        double decimalValue = 0.0;
        int power = integerPart.empty() ? 0 : integerPart.length() - 1;

        for (char c : integerPart)
        {
            decimalValue += (c - '0') * std::pow(8, power);
            power--;
        }

        power = -1;
        for (char c : fractionPart)
        {
            decimalValue += (c - '0') * std::pow(8, power);
            power--;
        }

        return isNegative ? -decimalValue : decimalValue;
    }

    static string BinaryToOctal(const string& binary)
    {
        double decimal = BinaryToDecimal(binary);
        return DecimalToOctal(decimal);
    }

    static string BinaryToHexadecimal(const string& binary)
    {
        double decimal = BinaryToDecimal(binary);
        return DecimalToHexadecimal(decimal);
    }

    static string HexadecimalToBinary(const string& hex)
    {
        double decimal = HexadecimalToDecimal(hex);
        return DecimalToBinary(decimal);
    }

    static string HexadecimalToOctal(const string& hex)
    {
        double decimal = HexadecimalToDecimal(hex);
        return DecimalToOctal(decimal);
    }

    static string OctalToBinary(const string& octal)
    {
        double decimal = OctalToDecimal(octal);
        return DecimalToBinary(decimal);
    }

    static string OctalToHexadecimal(const string& octal)
    {
        double decimal = OctalToDecimal(octal);
        return DecimalToHexadecimal(decimal);
    }
};

// Static members initialization
string clsConvertor::_Input = "";
string clsConvertor::_Result = "";
