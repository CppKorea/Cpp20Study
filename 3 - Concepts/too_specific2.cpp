#include <iostream>
#include <string>

struct MyHouse
{
    MyHouse() = default;  // (1)
    MyHouse(const std::string& fam) : family(fam)
    {
        // Do nothing
    }

    operator bool()
    {
        return !family.empty();  // (2)
    }

    std::string family = "";
};

void needInt(int i)
{
    std::cout << "int: " << i << std::endl;
}

int main()
{
    std::cout << std::boolalpha << std::endl;

    MyHouse firstHouse;
    if (!firstHouse)
    {
        std::cout << "The firstHouse is still empty." << std::endl;
    };

    MyHouse secondHouse("grimm");
    if (secondHouse)
    {
        std::cout << "Family grimm lives in secondHouse." << std::endl;
    }

    std::cout << std::endl;

    needInt(firstHouse);   // (3)
    needInt(secondHouse);  // (3)

    std::cout << std::endl;
}