# CPROGR 510, Assignment 2
## Logistics
In case of discrepancies between README.md and the assignment in Canvas, please alert the instructors!

After cloning this repo, create a branch off of main:

`git checkout -b Assignment2`

Do your work (modifications and additions of files) on the Assignment2 branch. 
Do include your code .cpp and .h files and your unit test .cpp files
Do not include exe, obj, or other results of compilation and linking. These would bloat the repository, and should not be under version control.
You may optionally turn in Visual Studio .vcproj and .sln files, or Makefiles (your-environment dependent).
`Commit` those changes to the Assignment2 branch. 

Push your changes up to `origin` (that is, to github).

When done, go to github.com and create a pull request to merge `Assignment2` branch to `main`.

## General Guidance
For each numbered item, please structure your files like this (using Problem 1 as an example):

Problem1_Swap.cpp: contains functions you wrote to satisfy the assigment item, and unit test cases which verify correct behavior 
```
#include "TestHarness.h"

void swap(int* n1, int* n2)
{
    //no peeking! your code goes here
}

TEST(ByPointerReference, Swap)
{
    //your test code goes here

    //add more test cases as needed
}
```

## Problem 1: Swap
Write a function that _swaps_ (exchanges the values of) two integers. Use `int*` as the argument types. 

Write a second swap function using a reference (i.e., `int&`) as the argument types. (Note: The C++ library has a std::swap. In most situations just use the library version. But, for this homework, write your own swap).  

Write CppUnitLite tests to verify correct behavior of both functions.

## Problem 2: Factorial
Factorial: Write a function that returns the factorial of its single `int` argument. Declare the function `constexpr`. 

Add comments in your unit test to specify an example where the factorial result is determined at compile-time, and another where the factorial result is determined at run time. 

Write unit tests that verify both the compile-time and run-time usage.

## Problem 3: MonthTable
MonthTable: Define a table of the names of months of the year and the number of days in each month. Write out that table to a `std::stringstream`. Do this two ways, in unit tests:
### 3.1
Once using a `std::array` of `std::string` for the names, and another `std::array` for the number of days.
### 3.2
a second time using a `std::array` of `struct`s, with each structure holding the name of a month (as a `std::string`) and the number of days in it.

## Problem 4: Cat
Cat (as in "concatenate"):

Write the function `cat()` that takes two C-style strings (i.e., `char*`) arguments and returns a `std::unique_ptr<char[]>` that contains the concatenation of the arguments. Use `std::make_unique` to use heap memory for the result. Write CppUnitLite tests to verify correct behavior.

Write a second function `cat()` that takes two `const std::string&` arguments and returns a `std::string` that is a concatenation of the arguments. The `std::string` version does not require `new`. Write CppUnitLite tests to verify correct behavior.

Which is the better approach? Explain your rationale for which is the better approach.

## Problem 5: ParseInt
ParseInt: Implement the function: `std::optional<int> ParseInt(const std::string& s);` Verify your function implementation passes these two unit tests (below). 
```
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
```
Add an additional unit test that verifies use of `std::optional::value_or()`.
