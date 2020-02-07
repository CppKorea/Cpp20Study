// Run with in cl
/*
cl.exe range_comprehension2.cpp /I ../../range-v3/include /std:c++latest /permissive- /experimental:preprocessor
*/

#include <range/v3/all.hpp>

#include <iostream>

using namespace ranges;

int main()
{
    std::cout << std::endl;

    // triples =[(x, y, z)|z <-[1..], x <-[1..z],y <-[x..z] ,x^2 + y^2 == z^2]

    auto triples = view::for_each(view::ints(1), [](int z) {
        return view::for_each(view::ints(1, z), [=](int x) {
            return view::for_each(view::ints(x, z), [=](int y) {
                return yield_if(x * x + y * y == z * z,
                                std::make_tuple(x, y, z));
            });
        });
    });

    ranges::for_each(
        triples | view::take_while([](std::tuple<int, int, int> nums) {
            return std::get<0>(nums) < 100;
        }),
        [](std::tuple<int, int, int> nums) {
            std::cout << "(" << std::get<0>(nums) << ", " << std::get<1>(nums)
                      << ", " << std::get<2>(nums) << ")\n";
        });

    std::cout << "\n\n";

    return 0;
}