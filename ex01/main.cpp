#include <iostream>
#include <string>
#include "Iter.hpp"

// --- Functions for testing ---

// This one modifies ints → matches non-const version (T&)
void increment(int &x) {
    ++x;
}

// This one only reads → matches const version (const T&)
void printInt(const int &x) {
    std::cout << x << std::endl;
}

// Works with const array of strings
void printString(const std::string &s) {
    std::cout << s << std::endl;
}

int main()
{
    // ---------------- Non-const array ----------------
    int nums[] = {1, 2, 3, 4};
    const std::size_t n = sizeof(nums) / sizeof(nums[0]);

    // uses void iter(T*, size_t, void(*)(T&))
    iter(nums, n, increment);   // modify elements
    iter(nums, n, printInt);    // print them

    std::cout << "----" << std::endl;

    // ---------------- Const array ----------------
    const std::string words[] = {"hello", "world"};
    const std::size_t m = sizeof(words) / sizeof(words[0]);

    // uses void iter(const T*, size_t, void(*)(const T&))
    iter(words, m, printString);  // works only with const version

    std::cout << "----" << std::endl;

    // Another const array of ints
    const int vals[] = {10, 20, 30};
    iter(vals, 3, printInt); // works with const ints

    return 0;
}