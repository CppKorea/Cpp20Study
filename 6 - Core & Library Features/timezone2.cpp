// Run with in cl
/*
cl.exe timezone2.cpp /I date/include /std:c++latest /EHsc
*/

#include <date/tz.h>

#include <chrono>
#include <iomanip>
#include <iostream>

using namespace date;

int main()
{
    auto zone_names = {
        "Asia/Tokyo",       "Asia/Hong_Kong", "Europe/Bucharest",
        "Europe/Berlin",    "Europe/London",  "America/New_York",
        "Pacific/Honolulu",
    };

    auto now = floor<std::chrono::seconds>(std::chrono::system_clock::now());
    for (const auto& name : zone_names)
    {
        std::cout << std::left << std::setw(25) << std::setfill(' ') << name
                  << zoned_time<std::chrono::milliseconds>(name, now)
                  << std::endl;
    }

    return 0;
}