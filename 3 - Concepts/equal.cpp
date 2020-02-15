#include <iostream>

template <class T, class U>
concept SameHelper = std::is_same<T, U>::value;

template <class T, class U>
concept same_as = SameHelper<T, U> && SameHelper<U, T>;

template <typename T>
concept Equal = requires(T a, T b)
{
    { a == b } -> same_as<bool>;
    { a != b } -> same_as<bool>;
};

bool areEqual(Equal auto a, Equal auto b)   // (1)
{
    return a == b;
}

/*
struct WithoutEqual
{
    bool operator==(const WithoutEqual& other) = delete;
};

struct WithoutUnequal
{
    bool operator!=(const WithoutUnequal& other) = delete;
};
*/

int main()
{
    std::cout << std::boolalpha << std::endl;

    std::cout << "areEqual(1, 5): " << areEqual(1, 5) << std::endl;

    /*
    bool res = areEqual(WithoutEqual(),  WithoutEqual());
    bool res2 = areEqual(WithoutUnequal(),  WithoutUnequal());
    */

    std::cout << std::endl;
}