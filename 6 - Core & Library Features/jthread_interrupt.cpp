// Run with in g++
/*
g++ jthread_interrupt.cpp -Wall -Wextra -std=gnu++2a
*/

#include <chrono>
#include <iostream>
#include <thread>

using namespace ::std::literals;

int main()
{
    std::cout << std::endl;

    std::jthread nonInterruptable([] {  // (1)
        int counter{0};
        while (counter < 10)
        {
            std::this_thread::sleep_for(0.2s);
            std::cerr << "nonInterruptable: " << counter << std::endl;
            ++counter;
        }
    });

    std::jthread interruptable([](std::stop_token itoken) {  // (2)
        int counter{0};
        while (counter < 10)
        {
            std::this_thread::sleep_for(0.2s);
            if (itoken.stop_requested())
                return;  // (3)
            std::cerr << "interruptable: " << counter << std::endl;
            ++counter;
        }
    });

    std::this_thread::sleep_for(1s);

    std::cerr << std::endl;
    std::cerr << "Main thread interrupts both jthreads" << std::endl;
    nonInterruptable.request_stop();
    interruptable.request_stop();  // (4)

    std::cout << std::endl;

    return 0;
}