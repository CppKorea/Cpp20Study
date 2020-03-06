#include <bit>
#include <iostream>

constexpr double f64v = 19880124.0;
constexpr auto u64v = std::bit_cast<std::uint64_t>(f64v);
constexpr std::uint64_t u64v2 = 0x3fe9000000000000ull;
constexpr auto f64v2 = std::bit_cast<double>(u64v2);

int main()
{
    std::cout << std::fixed << f64v << "f64.to_bits() == 0x" << std::hex << u64v
              << "u64\n";
    std::cout << "f64::from_bits(0x" << std::hex << u64v2
              << "u64) == " << std::fixed << f64v2 << "f64\n";

    return 0;
}