# C++ Split Timer / Code Profiler
Split Timer is a very simple code timer for debugging and profiling purposes.
There's nothing at all complicated going on here but I thought I'd write this up as a quick component 
to save me perpetually rewriting it.

# Usage
```code
#include <iostream>
#include <thread>
#include <chrono>
#include "SplitTimer.h"

int main()
{
    using namespace std::chrono_literals;
    
    SplitTimer::Timer t;
    t.reset(); // reset the total elapsed time of the timer
    std::cout << "Hello World!\n";
    t.split("Finished Printing"); // split and print result under the label 'Finished Printing'
    std::this_thread::sleep_for(100ms);
    t.split("Finished Sleeping");
    t.elapsedTime("Total Runtime"); // print the total time since we reset the timer
}
```
