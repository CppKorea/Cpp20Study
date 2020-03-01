// Run with in cl
/*
cl.exe hello_world.cpp /I fmt/include /std:c++latest /EHsc /MD /link fmt.lib
*/

#include <fmt/format.h>

#include <iostream>

int main()
{
    // Part 1
    // Standard C++ syntax using std::cout
    std::cout << "Hello, " << "world!\n";

    // Python-like format string syntax using fmt
    fmt::print("Hello, {}!\n", "world");

    // Part 2
    // Standard C++ syntax using std::cout
    std::cout << "I'd rather be " << "happy" << " than " << "right.\n";

    // Python-like format string syntax using fmt
    fmt::print("I'd rather be {1} than {0}.\n", "right", "happy");

    // Part 3
    int a = 1, b = 2;

    // Standard C++ syntax using std::cout
    std::cout << a << " + " << b << " = " << a + b << '\n';

    // Python-like format string syntax using fmt
    fmt::print("{} + {} = {}", a, b, a + b);

    return 0;
}