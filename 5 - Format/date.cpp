// Run with in cl
/*
cl.exe date.cpp /I fmt/include /std:c++latest /EHsc /MD /link fmt.lib
*/

#include <fmt/format.h>

#include <string>

struct date
{
    int year, month, day;
};

template <>
struct fmt::formatter<date>
{
    constexpr auto parse(format_parse_context& ctx)
    {
        return ctx.begin();
    }

    template <typename FormatContext>
    auto format(const date& d, FormatContext& ctx)
    {
        return format_to(ctx.out(), "{}-{}-{}", d.year, d.month, d.day);
    }
};

int main()
{
    std::string s = fmt::format("The date is {}", date{2012, 12, 9});

    // Python-like format string syntax using fmt
    fmt::print("{}\n", s);

    return 0;
}