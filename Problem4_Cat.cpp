#include "TestHarness.h"

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
