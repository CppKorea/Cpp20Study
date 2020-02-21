// References: https://github.com/roger-dv/cpp20-coro-generator

#ifndef GENERATOR_HPP
#define GENERATOR_HPP

#include <experimental/coroutine>
#include <iostream>
#include <memory>

namespace coro_exp
{
template <typename T>
class generator
{
 public:
    struct promise_type;
    using handle_type = std::experimental::coroutine_handle<promise_type>;

 private:
    handle_type coro;

 public:
    explicit generator(handle_type h) : coro(h)
    {
    }
    generator(const generator &) = delete;
    generator(generator &&oth) noexcept : coro(oth.coro)
    {
        oth.coro = nullptr;
    }
    generator &operator=(const generator &) = delete;
    generator &operator=(generator &&other) noexcept
    {
        coro = other.coro;
        other.coro = nullptr;
        return *this;
    }
    ~generator()
    {
        if (coro)
        {
            coro.destroy();
        }
    }

    bool next()
    {
        coro.resume();
        return !coro.done();
    }

    T getValue()
    {
        return coro.promise().current_value;
    }

    struct promise_type
    {
     private:
        T current_value{};
        friend class generator;

     public:
        promise_type() = default;
        ~promise_type() = default;
        promise_type(const promise_type &) = delete;
        promise_type(promise_type &&) = delete;
        promise_type &operator=(const promise_type &) = delete;
        promise_type &operator=(promise_type &&) = delete;

        auto initial_suspend()
        {
            return std::experimental::suspend_always{};
        }

        auto final_suspend()
        {
            return std::experimental::suspend_always{};
        }

        auto get_return_object()
        {
            return generator{handle_type::from_promise(*this)};
        }

        auto return_void()
        {
            return std::experimental::suspend_never{};
        }

        auto yield_value(T some_value)
        {
            current_value = some_value;
            return std::experimental::suspend_always{};
        }

        void unhandled_exception()
        {
            std::exit(1);
        }
    };
};

}  // namespace coro_exp

#endif  // GENERATOR_HPP