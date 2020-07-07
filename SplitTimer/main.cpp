#include <iostream>
#include <thread>
#include <chrono>
#include "SplitTimer.h"

int main()
{
    using namespace std::chrono_literals;
    SplitTimer::Timer t;
    t.reset();
    std::cout << "Hello World!\n";
    t.split("Finished Printing");
    std::this_thread::sleep_for(100ms);
    t.split("Finished Sleeping");
    t.elapsedTime("Total Runtime");
}