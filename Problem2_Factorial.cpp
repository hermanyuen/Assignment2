#include "TestHarness.h"
#include <iostream>

//## Problem 2: Factorial
//Factorial : Write a function that returns the factorial of its single `int` argument. Declare the function `constexpr`.
//
//Add comments in your unit test to specify an example where the factorial result is determined at compile-time, and another where the factorial result is determined at run time.
//
//Write unit tests that verify both the compile - time and run - time usage.

constexpr int factorial(int n)
{
    int ntotal{ n };
    for (int i{n-1}; i > 0; i--) {
        ntotal *= i;
    }
    return ntotal;
}

TEST(factorial, integralType)
{
    constexpr int total = factorial(3); //Factorial results deteremined at compile time
    //std::cout << total  << "\n";
    CHECK_EQUAL(6, total);

    int total2 = factorial(4);    //Factorial results deteremined at runtime
   // std::cout << total2 << "\n";
    CHECK_EQUAL(24, total2);
}