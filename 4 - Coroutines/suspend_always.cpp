// Run with in cl
/*
cl suspend_always.cpp /std:c++latest /await /EHsc
*/

#include <experimental/coroutine>
#include <iostream>

class return_ignore final
{
 public:
    class promise_type final
    {
     public:
        auto initial_suspend() noexcept
        {
            return std::experimental::suspend_never{};
        }

        auto final_suspend() noexcept
        {
            return std::experimental::suspend_never{};
        }

        void return_void() noexcept
        {
            // nothing to do because this is `void` return
        }

        void unhandled_exception() noexcept(false)
        {
            std::terminate();  // customize this part
        }

        promise_type* get_return_object() noexcept
        {
            return this;
        }
    };

 public:
    return_ignore(const promise_type*) noexcept
    {
        // the type truncates all given info about its frame
    }
};

using namespace std;
namespace coro = std::experimental;

auto example() -> return_ignore
{
    puts("step 1");
    co_await coro::suspend_always{};
    puts("step 2");
}

int main(int, char* [])
{
    example();
    puts("step 3");

    return 0;
}