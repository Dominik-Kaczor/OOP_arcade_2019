/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** TimerFPS
*/

#include "Timer.hpp"

void Arcade::Timer::HandleFPS()
{
    _a = std::chrono::system_clock::now();
    std::chrono::duration<double, std::milli> actual = _a - _b;

    if (actual.count() < Constants::FPS) {
        std::chrono::duration<double, std::milli> delta_ms(Constants::FPS -
                                                           actual.count());
        auto delta_ms_duration =
            std::chrono::duration_cast<std::chrono::milliseconds>(delta_ms);
        std::this_thread::sleep_for(
            std::chrono::milliseconds(delta_ms_duration.count()));
    }
    _b = std::chrono::system_clock::now();
    std::chrono::duration<double, std::milli> sleep_time = _b - _a;
}