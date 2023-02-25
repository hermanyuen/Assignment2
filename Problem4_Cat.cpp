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

std::unique_ptr<char[]> cat(const char* c1, const char* c2)
{
    
    if (c1 == nullptr || c2 == nullptr) {
        auto pvalues{ std::make_unique<char[]>(1) };
        if (c1 == nullptr && c2 != nullptr) {
            pvalues[0] = *c2;
        }
        else if (c1 != nullptr && c2 == nullptr) {
            pvalues[0] = *c1;
        }
        else {
            pvalues = nullptr;
        }
        return pvalues;
    }
    auto pvalues{ std::make_unique<char[]>(std::strlen(c1) + std::strlen(c2) + 1) };
    /*pvalues[0] = *c1;
    pvalues[std::strlen(c1)] = *c2;*/
    for (size_t i{}; i < std::strlen(c1); i++) {
        pvalues[i] = *(c1 + i);
    }
    for (size_t i{ std::strlen(c1) }; i < (std::strlen(c1) + std::strlen(c2)); i++) {
        pvalues[i] = *(c2 + i- std::strlen(c1));
    }
    //pvalues[1] = *c2;

    return pvalues;
}

TEST(concatenate, charType)
{
    const char* a = "Hello";
    const char* b = "World";
    auto catValue = cat(a, b);
    //std::string helloW(catValue.get());
    //std::cout << "\n" << helloW << "\n";
    CHECK_EQUAL("HelloWorld", catValue.get());

    const char* c = NULL;
    const char* d = NULL;
    auto catValue2 = cat(c, d);
    CHECK(!catValue2.get());

}

std::string cat2(const std::string& c1, const std::string& c2)
{
    return c1 + c2;
}

TEST(concatenate2, stringType)
{
    std::string a{ "Hello"};
    std::string b{ "World" };
    auto catValue = cat2(a, b);
    //std::cout << "\n" << catValue << "\n";
    CHECK_EQUAL("HelloWorld", catValue);
}

/*Ihe smart pointer is the better approach. Although I think the string is 
simpler to write, the unique pointer is safer in terms of deallocation and 
the variables are also unique so there's no concerns with aliasing. If other
variables are trying to use the same address, it won't be able to.*/