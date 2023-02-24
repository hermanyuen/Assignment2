#include "TestHarness.h"
#include <array>
#include <iostream>
// ## Problem 3: MonthTable
// MonthTable : Define a table of the names of months of the year and the number of days in each month.
// Write out that table to a `std: : stringstream`. Do this two ways, in unit tests :
// ### 3.1
// Once using a `std::array` of `std::string` for the names, and another `std::array` for the number of days.
// ### 3.2
// A second time using a `std::array` of `struct`s, with each structure holding the name of a month(as a `std::string`)and the number of days in it.

//void monthTable(int* n1, int* n2)
//{
//    //no peeking! your code goes here
//
//}

TEST(MonthTable, builtInArray)
{
	std::array<std::string, 12> months {"January", "February", "March", "April", "May",
		"June", "July", "August", "September", "October", "November", "December"};

    std::array<int, 12> days{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    std::stringstream sCalander;

	for (int day = 0; day < days.size(); ++day)
	{
            sCalander << months[day] << days[day];
	}
    //std::cout << "\n" << sCalander.str() << "\n";
    std::string calanderString{ "January31February28March31April30May31June30July31August31September30October31November30December31"};
    CHECK_EQUAL(calanderString, sCalander.str());
}

struct Month {
    std::string months;
    int days;
};

TEST(MonthTable2, objectArray)
{
    std::array<Month, 12> calandar{};
    std::stringstream sCalander;
    std::array<std::string, 12> monthString{ "January", "February", "March", "April", "May",
        "June", "July", "August", "September", "October", "November", "December" };
    std::array<int, 12> days{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    for (int day = 0; day <days.size(); ++day)
    {
        struct Month monthObj { monthString[day], days[day] };
        sCalander << monthObj.months << monthObj.days;
    }

    //std::cout << "\n" << sCalander.str() << "\n";
    std::string calanderString{ "January31February28March31April30May31June30July31August31September30October31November30December31" };
    CHECK_EQUAL(calanderString, sCalander.str());
}