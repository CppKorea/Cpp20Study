// Run with in cl
/*
cl has_bool_value_member.cpp /std:c++latest
*/

#include <concepts>

template <typename T>
concept has_bool_value_member = requires
{
    { T::value } -> std::convertible_to<bool>;
};

struct S1
{

};

struct S2
{
    constexpr static bool value = true;
};

struct S3
{
    constexpr static S1 value{};
};

template <has_bool_value_member T>
bool get_value()
{
    return T::value;
}

int main()
{
    static_assert(!has_bool_value_member<S1>);
    static_assert(has_bool_value_member<S2>);
    static_assert(!has_bool_value_member<S3>);

    S1 s1;
    S2 s2;
    S3 s3;

    //get_value<S1>();
    get_value<S2>();
    //get_value<S3>();

    return 0;
}