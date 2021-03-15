/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** TimerFPS
*/

#ifndef TIMERFPS_HPP_
#define TIMERFPS_HPP_
#include <chrono>
#include <iostream>
#include <thread>
#include "Constants.hpp"

namespace Arcade {
    class Timer {
    public:
        void HandleFPS();

    protected:
    private:
        std::chrono::system_clock::time_point _a;
        std::chrono::system_clock::time_point _b;
    };
} // namespace Arcade
#endif /* !TIMERFPS_HPP_ */
