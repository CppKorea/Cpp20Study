// Run with cl /experimental:module /EHsc /MD /std:c++latest example_simple.cpp

import std.core;

int main()
{
    std::vector<std::string> v{ "Plato", "Descartes", "Bacon" };
    std::copy(v.begin(), v.end(), std::ostream_iterator<std::string>(std::cout, "\n"));

    return 0;
}