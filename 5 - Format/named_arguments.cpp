// Run with in cl
/*
cl.exe named_arguments.cpp /I fmt/include /std:c++latest /EHsc /MD /link fmt.lib
*/

#include <fmt/format.h>

#include <iostream>

using namespace fmt::literals;

int main()
{
    // Named arguments
    fmt::print("Hello, {name}! The answer is {number}. Goodbye, {name}.\n",
               fmt::arg("name", "World"), fmt::arg("number", 42));

    // C++11 user-defined literals (_a: alternative)
    fmt::print("Hello, {name}! The answer is {number}. Goodbye, {name}.\n",
               "name"_a = "World", "number"_a = 42);

    return 0;
}