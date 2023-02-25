#include "TestHarness.h"
#include <optional>
#include <iostream>

// ## Problem 5: ParseInt
// ParseInt : Implement the function : `std::optional<int> ParseInt(const std::string & s);`
// 
// Verify your function implementation passes the two provided unit tests (below).
//
// Add an additional unit test that verifies use of `std::optional::value_or()`.

std::optional<int> ParseInt(const std::string& s)
{
    
	try {
		std::optional<int> sInt = std::stoi(s);
		return sInt;
	}
	catch (std::invalid_argument) {
		return {};
	}
	//return std::nullopt; //your impl goes here
}

TEST(ParseIntSuccess, Parse)
{
	auto result = ParseInt("99");

	CHECK(result.has_value());
	CHECK_EQUAL(99, *result);
}

TEST(ParseIntFailure, Parse)
{
	auto result = ParseInt("Hello");

	CHECK(!result.has_value());
}

TEST(ParseIntValueOr, Parse)
{
    int result = ParseInt("Hello").value_or(100);
    //std::cout << "\nresult has value? " << result.has_value() <<", result=" << result.value() << "\n";
	CHECK_EQUAL(100, result);
    //CHECK(result.has_value());

	int result2 = ParseInt("10").value_or(100);
	CHECK_EQUAL(10, result2);
}