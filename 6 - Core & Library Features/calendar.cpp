// Run with in cl
/*
cl.exe calendar.cpp /I date/include /std:c++latest /EHsc
*/

#include <date/date.h>
#include <date/iso_week.h>

#include <chrono>

using namespace date;

inline int number_of_days(const sys_days& first, const sys_days& last)
{
    return (last - first).count();
}

int main()
{
    auto d1 = 2018_y / mar / 27;
    auto d2 = 27_d / mar / 2018;
    auto d3 = mar / 27 / 2018;
    year_month_day today = floor<days>(std::chrono::system_clock::now());

    assert(d1 == d2);
    assert(d2 == d3);
    // assert(d3 == today);

    auto ymdl = year_month_day_last(today.year(), month_day_last{month{2}});
    auto last_day_feb = year_month_day{ymdl};

    // assert(last_day_feb == 2018_y / feb / 28);  // for 2018

    auto days = number_of_days(2018_y / apr / 1, 2018_y / dec / 25);

    assert(days == 268);

    return 0;
}