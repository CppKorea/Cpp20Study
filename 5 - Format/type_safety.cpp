// Run with in cl
/*
cl.exe type_safety.cpp /I fmt/include /std:c++latest /EHsc /MD /link fmt.lib
*/

#include <fmt/format.h>

#include <iostream>

int main()
{
    // Part 1
    // Throw format_error exception: "unknown format code 'd' for string".
    fmt::format("The answer is {:d}\n", "forty-two");

    // Report a compile-time error for the same reason
    //fmt::format(FMT_STRING("The answer is {:d}\n"), "forty-two");

    // Part 2
    // Report a compile-time error because wide character L'\x42e' cannot be formatted into a narrow string
    fmt::format("Cyrillic letter {}\n", L'\x42e');

    // fmt::format(L"Cyrillic letter {}\n", L'\x42e');

    return 0;
}