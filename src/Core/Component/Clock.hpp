/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Clock
*/

#ifndef CLOCK_HPP_
#define CLOCK_HPP_
#include <iostream>
#include <chrono>
#include <thread>
#include "Constants.hpp"

namespace Arcade {
    class Clock {
    public:
        Clock();
        ~Clock();
        std::chrono::seconds GetElapsedTimeSeconds();
        std::chrono::microseconds GetElapsedTimeMicroSeconds();
        std::chrono::milliseconds GetElapsedTimeMilliSeconds();
        void Restart();

    protected:
    private:
        std::chrono::system_clock::time_point _timer;
    };
} // namespace Arcade

#endif /* !CLOCK_HPP_ */
