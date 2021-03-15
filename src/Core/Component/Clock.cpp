/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Clock
*/

#include "Clock.hpp"

Arcade::Clock::Clock() : _timer(std::chrono::system_clock::now())
{
}

Arcade::Clock::~Clock()
{
}

std::chrono::seconds Arcade::Clock::GetElapsedTimeSeconds()
{
    return (std::chrono::duration_cast<std::chrono::seconds>(
        std::chrono::system_clock::now() - this->_timer));
}

std::chrono::microseconds Arcade::Clock::GetElapsedTimeMicroSeconds()
{
    return (std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::system_clock::now() - this->_timer));
}

std::chrono::milliseconds Arcade::Clock::GetElapsedTimeMilliSeconds()
{
    return (std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::system_clock::now() - this->_timer));
}

void Arcade::Clock::Restart()
{
    this->_timer = std::chrono::system_clock::now();
}