// Run with in g++
/*
g++ span.cpp -Wall -Wextra -std=gnu++2a
*/

#include <array>
#include <iostream>
#include <span>
#include <string>
#include <vector>

template <typename T>
void func(std::span<T> arr)
{
    for (auto&& s : arr)
    {
        s[0] = std::toupper(s[0]);
    }
}

int main()
{
    std::vector<std::string> greeting = { "hello", "world" };
    func<std::string>(greeting);

    for (const auto& word : greeting)
    {
        std::cout << word << ' ';
    }
    std::cout << '\n';
    
    std::array<std::string, 2> name = { "tom", "john" };
    func<std::string>(name);
    
    for (const auto& word : name)
    {
        std::cout << word << ' ';
    }
    std::cout << '\n';
    
    return 0;
}