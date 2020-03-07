// Run with in g++
/*
g++ jthread_interrupt_argument.cpp -Wall -Wextra -std=gnu++2a
*/

#include <chrono>
#include <iostream>
#include <thread>

using namespace ::std::literals;

void SomeThread(std::stop_token itoken, int* value)
{
    int v = *value;
    while (true)
    {
        std::this_thread::sleep_for(0.2s);
        if (itoken.stop_requested())
            break;
        std::cout << "v = " << v << std::endl;
    }
}

int main()
{
    std::cout << std::endl;

    int v = 100;
    std::jthread jt = std::jthread(&SomeThread, (int*)&v);

    std::this_thread::sleep_for(1s);

    std::cerr << std::endl;
    std::cerr << "Main thread interrupts both jthreads" << std::endl;
    
    jt.request_stop();

    std::cout << std::endl;

    return 0;
}