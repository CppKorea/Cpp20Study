// Run with in clang++
/*
clang++ -std=c++2a -fmodules-ts --precompile simple_math_template.cppm -o simple_math_template.pcm
clang++ -std=c++2a -fmodules-ts -c simple_math_template.pcm -o simple_math_template.pcm.o
clang++ -std=c++2a -fmodules-ts -c simple_main_template.cpp -fmodule-file=simple_math_template.pcm -o simple_main_template.o
clang++ simple_math_template.pcm simple_main_template.o -o simple_main_template
*/

// Run with in cl
/*
cl.exe /std:c++latest /experimental:module /TP /EHsc /MD /c simple_math_template.cppm /module:interface /Fo: simple_math_template.pcm.obj /module:output simple_math_template.pcm
cl.exe /std:c++latest /experimental:module /TP /EHsc /MD /c simple_main_template.cpp /module:reference simple_math_template.pcm /Fo: simple_main_template.obj
cl.exe simple_main_template.obj simple_math_template.pcm.obj
*/

import std.core;
import simple_math;

int main()
{
    std::vector<int> v1;
    v1.emplace_back(add<int>(100, 200));
    v1.emplace_back(add<int>(30, 40));

    std::copy(v1.begin(), v1.end(), std::ostream_iterator<int>(std::cout, "\n"));

    std::vector<std::string> v2;
    v2.emplace_back(add<std::string>("Hello", " World!"));
    v2.emplace_back(add<std::string>("Happy", " Weekend!"));

    std::copy(v2.begin(), v2.end(), std::ostream_iterator<std::string>(std::cout, "\n"));

    return 0;
}