// Run with cl example_simple_no_module.cpp /EHsc

#include <algorithm>
#include <iterator>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<std::string> v{ "Plato", "Descartes", "Bacon" };
    std::copy(v.begin(), v.end(), std::ostream_iterator<std::string>(std::cout, "\n"));

    return 0;
}