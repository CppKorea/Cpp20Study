// Run with in clang++
/*
clang++ -std=c++2a -fmodules-ts --precompile simple_math.cppm -o simple_math.pcm
clang++ -std=c++2a -fmodules-ts -c simple_math.pcm -o simple_math.pcm.o
clang++ -std=c++2a -fmodules-ts -c simple_math.cpp -fmodule-file=simple_math.pcm -o simple_math.o
clang++ -std=c++2a -fmodules-ts -c simple_main.cpp -fmodule-file=simple_math.pcm -o simple_main.o
clang++ simple_math.pcm simple_main.o simple_main.o -o simple_main
*/

// Run with in cl
/*
cl.exe /std:c++latest /experimental:module /TP /EHsc /MD /c simple_math.cppm /module:interface /Fo: simple_math.pcm.obj /module:output simple_math.pcm
cl.exe /std:c++latest /experimental:module /TP /EHsc /MD /c simple_math.cpp /module:reference simple_math.pcm /Fo: simple_math.obj
cl.exe /std:c++latest /experimental:module /TP /EHsc /MD /c simple_main.cpp /module:reference simple_math.pcm /Fo: simple_main.obj
cl.exe simple_math.obj simple_main.obj simple_math.pcm.obj
*/

import std.core;
import simple_math;

int main()
{
    std::vector<int> v;
    v.emplace_back(add(100, 200));
    v.emplace_back(add(30, 40));

    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, "\n"));

    return 0;
}