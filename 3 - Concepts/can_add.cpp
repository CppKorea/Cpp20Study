// Run with in cl
/*
cl can_add.cpp /std:c++latest
*/

#include <concepts>

template <typename T, typename U>
concept can_add = requires(T t, U u)
{
    t + u;
};

template <typename T, typename U> requires can_add<T, U>
auto add(T t, U u)
{
    return t + u;
}

int main()
{
    add(3, 4);
    //add("T", "U");

    return 0;
}