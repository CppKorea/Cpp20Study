// Run with in clang++
/*
clang++ -std=c++2a -fmodules-ts --precompile simple_math_overloading.cppm -o simple_math_overloading.pcm
clang++ -std=c++2a -fmodules-ts -c simple_math_overloading.pcm -o simple_math_overloading.pcm.o
clang++ -std=c++2a -fmodules-ts -c simple_math_overloading.cpp -fmodule-file=simple_math_overloading.pcm -o simple_math_overloading.o
clang++ -std=c++2a -fmodules-ts -c simple_main_overloading.cpp -fmodule-file=simple_math_overloading.pcm -o simple_main_overloading.o
clang++ simple_math_overloading.pcm simple_math_overloading.o simple_main_overloading.o -o simple_main_overloading
*/

// Run with in cl
/*
cl.exe /std:c++latest /experimental:module /TP /EHsc /MD /c simple_math_overloading.cppm /module:interface /Fo: simple_math_overloading.pcm.obj /module:output simple_math_overloading.pcm
cl.exe /std:c++latest /experimental:module /TP /EHsc /MD /c simple_math_overloading.cpp /module:reference simple_math_overloading.pcm /Fo: simple_math_overloading.obj
cl.exe /std:c++latest /experimental:module /TP /EHsc /MD /c simple_main_overloading.cpp /module:reference simple_math_overloading.pcm /Fo: simple_main_overloading.obj
cl.exe simple_math_overloading.obj simple_main_overloading.obj simple_math_overloading.pcm.obj
*/

import std.core;
import simple_math;

int main()
{
    std::vector<int> v;
    v.emplace_back(add(100, 200));
    v.emplace_back(add(30, 40, 50));

    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, "\n"));

    return 0;
}