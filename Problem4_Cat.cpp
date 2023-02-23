#include "TestHarness.h"
#include <iostream>
#include <iostream>

// ## Problem 4: Cat (as in "concatenate") :
// Write the function `cat()` that takes two C - style strings(i.e., `char*`) arguments
// and returns a `std::unique_ptr<char[]>` that contains the concatenation of the arguments.
// Use `std::make_unique` to use heap memory for the result.
// 
// Write CppUnitLite tests to verify correct behavior.
//
// Write a second function `cat()` that takes two `const std::string&` arguments
// and returns a `std::string` that contains the concatenation of the arguments.
// The `std::string` version does not require `new`. 
// 
// Write CppUnitLite tests to verify correct behavior.
//
// Which is the better approach? Explain, in a code-comment block, your rationale for which is the better approach.

std::unique_ptr<char[]> cat(char* c1, char* c2)
{
    auto pvalues{ std::make_unique<char[]>(2) };
    pvalues[0] = *c1;
    pvalues[1] = *c2;

    return pvalues;
}

TEST(concatenate, charType)
{
    char a{'a'};
    char b{'b'};
    auto catValue = cat(&a, &b);
    //std::cout << "\n" << catValue[0] << "\n";
    CHECK_EQUAL('a', catValue[0]);
    CHECK_EQUAL('b', catValue[1]);

}

std::string cat2(const std::string c1, const std::string c2)
{
    std::string values;
    values = c1 + c2;

    return values;
}

TEST(concatenate2, stringType)
{
    std::string a{ "a"};
    std::string b{ "b" };
    auto catValue = cat2(a, b);
    //std::cout << "\n" << catValue << "\n";
    CHECK_EQUAL("ab", catValue);
}

/*Ihe smart pointer is the better approach. Although I think the string is 
simpler to write, the unique pointer is safer in terms of deallocation and 
the variables are also unique so there's no concerns with naming.*/