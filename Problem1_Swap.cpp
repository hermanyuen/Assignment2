#include "TestHarness.h"

//## Problem 1: Swap
// Write a `swap` function that _swaps_(exchanges the values of) two integers.Use `int*` as the argument types.
//
// Write a second `swap` function using a reference(i.e., `int&`) as the argument types. 
// (Note: The C++ library has a std::swap.In most situations just use the library version.But, for this homework, write your own swap).
//
// Write CppUnitLite tests to verify correct behavior of both functions.

#include <iostream>

void swap(int* n1, int* n2)
{
    //no peeking! your code goes here
    if (n1 == nullptr && n2 != nullptr) {
        *n1 = *n2;
        n2 = nullptr;
        return;
    }
    else if (n1 != nullptr && n2 == nullptr) {
        *n2 = *n1;
        n1 = nullptr;
        return;
    }
    else {}
        
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}
void swap2(int& n1, int& n2)
{
    //no peeking! your code goes here
    if (n1 == NULL && n2 != NULL) {
        n1 = n2;
        n2 = NULL;
        return;
    }
    else if (n1 != NULL && n2 == NULL) {
        n2 = n1;
        n1 = NULL;
        return;
    }
    else {}
    int temp = n1;
    n1 = n2;
    n2 = temp;
}

TEST(ByPointer, Swap)
{
    //your test code goes here
    //add more test cases as needed
    int n1{ 5 };
    int n2{ 6 };
 
    swap(&n1, &n2);
    CHECK_EQUAL(6, n1);

    int k1{ NULL };
    int k2{ NULL };

    swap(&k1, &k2);
    CHECK_EQUAL(NULL, k1);
}

TEST(ByReference, Swap)
{
    //your test code goes here
    //add more test cases as needed
    int m1{ 7 };
    int m2{ 8 };
    swap2(m1, m2);
    CHECK_EQUAL(8, m1);

    int k1{ NULL };
    int k2{ NULL };
    swap2(k1, k2);
    CHECK_EQUAL(NULL, k1);

}