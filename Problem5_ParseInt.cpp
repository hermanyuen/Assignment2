#include "TestHarness.h"
#include <optional>

// ## Problem 5: ParseInt
// ParseInt : Implement the function : `std::optional<int> ParseInt(const std::string & s);`
// 
// Verify your function implementation passes the two provided unit tests (below).
//
// Add an additional unit test that verifies use of `std::optional::value_or()`.

std::optional<int> ParseInt(const std::string& /* s (commenting out to avoid 'unreferenced formal parameter' warning) */)
{
	return std::nullopt; //your impl goes here
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