// Run with in cl
/*
cl.exe alignment.cpp /I fmt/include /std:c++latest /EHsc /MD /link fmt.lib
*/

#include <fmt/format.h>

int main()
{
    // Result: "left aligned                  "
    fmt::print("{:<30}\n", "left aligned");
    // Result: "                 right aligned"
    fmt::print("{:>30}\n", "right aligned");
    // Result: "           centered           "
    fmt::print("{:^30}\n", "centered");
    // Result: "***********centered***********"
    fmt::print("{:*^30}\n", "centered");

    // Result: "3.1"
    fmt::print("{:.{}f}\n", 3.14, 1);
    // Result: "3.2"
    fmt::print("{:.{}f}\n", 3.16, 1);

    // Result: "+3.140000; -3.140000"
    fmt::print("{:+f}; {:+f}\n", 3.14, -3.14);
    // Result: " 3.140000; -3.140000"
    fmt::print("{: f}; {: f}\n", 3.14, -3.14);
    // Result: "3.140000; -3.140000"
    fmt::print("{:-f}; {:-f}\n", 3.14, -3.14);

    return 0;
}