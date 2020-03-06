// Run with in g++
/*
g++ thread_join.cpp -Wall -Wextra -std=gnu++2a
*/

#include <iostream>
#include <thread>

int main()
{
    std::cout << std::endl;
    std::cout << std::boolalpha;

    std::thread thr{[] { std::cout << "Joinable std::thread" << std::endl; }};

    std::cout << "thr.joinable(): " << thr.joinable() << std::endl;

    std::cout << std::endl;

    return 0;
}