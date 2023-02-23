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

    std::array<int, 12> days;
    std::stringstream sCalander;

	for (int day = 0; day < days.size(); ++day)
	{
        switch (day+1) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            days[day] = 31;
            sCalander << months[day] << days[day];
            break;
        case 2:
            days[day] = 28;
            sCalander << months[day] << days[day];
            break;
        default:
            days[day] = 30;
            sCalander << months[day] << days[day];
        }
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

    for (int month = 0; month <calandar.size(); ++month)
    {
        switch (month + 1) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            calandar[month].days = 31;
            calandar[month].months = monthString[month];
            sCalander << calandar[month].months << calandar[month].days;
            break;
        case 2:
            calandar[month].days = 28;
            calandar[month].months = monthString[month];
            sCalander << calandar[month].months << calandar[month].days;
            break;
        default:
            calandar[month].days = 30;
            calandar[month].months = monthString[month];
            sCalander << calandar[month].months << calandar[month].days;
        }
    }

    //std::cout << "\n" << sCalander.str() << "\n";
    std::string calanderString{ "January31February28March31April30May31June30July31August31September30October31November30December31" };
    CHECK_EQUAL(calanderString, sCalander.str());
}