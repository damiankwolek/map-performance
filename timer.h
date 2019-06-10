#ifndef __TIMER_H
#define __TIMER_H

#include <iostream>
#include <chrono>
#include <ctime>

namespace timer{
class timer
{
    private:
        std::string id;
        std::chrono::time_point<std::chrono::steady_clock> t_start;
    public:
        timer()
            :t_start(std::chrono::steady_clock::now())
        {};

        timer(const std::string & s)
            :id(s), t_start(std::chrono::steady_clock::now())
        {};

        ~timer()
        {
            auto t_end = std::chrono::steady_clock::now(); 
            std::chrono::duration<double> elapsed_seconds = t_end - t_start;
            std::cout << "Timer:" << id << " elapsed:" << elapsed_seconds.count() << "s\n";
        }
};
}// namespace timer

#endif
