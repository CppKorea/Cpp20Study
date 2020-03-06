// Run with in cl
/*
cl.exe timezone1.cpp /I date/include /std:c++latest /EHsc
*/

#include <date/tz.h>

#include <chrono>
#include <iomanip>
#include <iostream>

using namespace date;

int main()
{
    auto time =
        floor<std::chrono::milliseconds>(std::chrono::system_clock::now());
    std::cout << std::left << std::setw(25) << std::setfill(' ') << "Time"
              << time << std::endl;
    auto localtime =
        zoned_time<std::chrono::milliseconds>(date::current_zone(), time);
    std::cout << std::left << std::setw(25) << std::setfill(' ') << "Local"
              << localtime << std::endl;

    return 0;
}