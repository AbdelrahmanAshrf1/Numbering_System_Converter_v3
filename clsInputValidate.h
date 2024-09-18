#pragma once
#include <iostream>
#include <string>
#include <limits>
#include "clsString.h"
#include "clsDate.h"

template <class T>
class clsInputValidate
{
public:
    static bool IsNumberBetween(T Number, T From, T To)
    {
        return Number >= From && Number <= To;
    }

    static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
    {
        // Date >= From && Date <= To
        if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From)) &&
            (clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To)))
        {
            return true;
        }

        // Date >= To && Date <= From
        if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To)) &&
            (clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From)))
        {
            return true;
        }

        return false;
    }

    static T ReadNumber(const std::string& ErrorMessage = "Invalid Number, Enter again\n")
    {
        T Number{};
        while (!(std::cin >> Number))
        {
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard invalid input
            std::cout << ErrorMessage;
        }
        return Number;
    }

    static T ReadNumberBetween(T From, T To, const std::string& ErrorMessage = "Number is not within range, Enter again:\n")
    {
        T Number = ReadNumber();

        while (!IsNumberBetween(Number, From, To))
        {
            std::cout << ErrorMessage;
            Number = ReadNumber();
        }
        return Number;
    }

    static bool IsValidDate(clsDate Date)
    {
        return clsDate::IsValidDate(Date);
    }

};
