// Run with in g++
/*
g++ consteval.cpp -Wall -Wextra -std=gnu++2a
*/

#include <iostream>

consteval int sqr(int n)
{
    return n * n;
}

constexpr int r = sqr(100);  // OK

consteval int sqrsqr(int n)
{
    return sqr(sqr(n));  // OK
}

// constexpr int dblsqr(int n)
// {
//     return 2 * sqr(n);  // Error
// }

int main()
{
    std::cout << sqrsqr(10) << '\n';

    return 0;
}