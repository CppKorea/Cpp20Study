// Run with in g++
/*
g++ endian.cpp -Wall -Wextra -std=gnu++2a
*/

#include <bit>
#include <iostream>
#include <string>

template <typename T, std::endian endianess = std::endian::native>
std::string HEX__1(const T& value, size_t value_size = sizeof(T))
{
    using namespace std;
    uint8_t* buffer = (uint8_t*)(&value);
    char converted[value_size * 2 + 1];
    
    if (endianess == std::endian::big)
    {
        for (size_t i = 0; i < value_size; ++i)
        {
            sprintf(&converted[i * 2], "%02X", buffer[i]);
        }
    }
    else
    {
        for (size_t i = 0; i < value_size; ++i)
        {
            sprintf(&converted[i * 2], "%02X", buffer[value_size - 1 - i]);
        }
    }
    
    return converted;
}

int main()
{
    {
        uint8_t a = 0x10;
        std::cout << HEX__1(a) << std::endl;
        if (HEX__1(a) != "10")
        {
            throw std::runtime_error("");
        }
    }
    {
        int32_t a = -128;
        std::cout << HEX__1(a) << std::endl;
        if (HEX__1(a) != "FFFFFF80")
        {
            throw std::runtime_error("");
        }
    }
    {
        uint64_t a = 0x0000000000000102;
        std::cout << HEX__1(a) << std::endl;
        if (HEX__1(a) != "0000000000000102")
        {
            throw std::runtime_error("");
        }
    }
    {
        double a = 1;
        std::cout << HEX__1(a) << std::endl;
        if (HEX__1(a) != "3FF0000000000000")
        {
            throw std::runtime_error("");
        }
    }
    std::cout << "------------------" << std::endl;
    {
        uint64_t a = 0;
        std::cout << HEX__1(a) << std::endl;
        if (HEX__1(a) != "0000000000000000")
        {
            throw std::runtime_error("");
        }
    }

    return 0;
}