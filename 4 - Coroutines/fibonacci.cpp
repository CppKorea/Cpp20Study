// Run with in cl
/*
cl fibonacci.cpp /std:c++latest /await /EHsc
*/

// References: https://github.com/roger-dv/cpp20-coro-generator

#include "generator.hpp"

#include <experimental/coroutine>
#include <iostream>

using coro_exp::generator;

static const double demo_ceiling = 10E44;

generator<double> fibonacci(const double ceiling)
{
    double j = 0;
    double i = 1;
    co_yield j;

    if (ceiling > j)
    {
        do
        {
            co_yield i;
            double tmp = i;
            i += j;
            j = tmp;
        } while (i <= ceiling);
    }
}

int main()
{
    std::cout << "Example program using C++20 coroutine to implement a "
                 "Fibonacci Sequence generator"
              << '\n';

    auto iter = fibonacci(demo_ceiling);
    while (iter.next())
    {
        const auto value = iter.getValue();
        std::cout << value << '\n';
    }

    return 0;
}