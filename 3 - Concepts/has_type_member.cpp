// Run with in cl
/*
cl has_type_member.cpp /std:c++latest
*/

#include <concepts>

template <typename T>
concept has_type_member = requires
{
    typename T::type;
};

struct S1
{

};

struct S2
{
    using type = int;
};

template <class T>
constexpr bool has_type_member_f(T)
{
    return has_type_member<T>;
}

int main()
{
    static_assert(!has_type_member<S1>);
    static_assert(has_type_member<S2>);

    static_assert(!has_type_member_f(S1{}));
    static_assert(has_type_member_f(S2{}));

    return 0;
}