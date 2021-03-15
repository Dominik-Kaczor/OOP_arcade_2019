/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Mouse
*/

#include "Mouse.hpp"

Arcade::Mouse::Mouse()
{
    this->_mouse.push_back(0);
    this->_mouse.push_back(0);
    this->_old_mouse.push_back(0);
    this->_old_mouse.push_back(0);
}

void Arcade::Mouse::SetMouse(int x, int y)
{
    this->_mouse[0] = x;
    this->_mouse[1] = y;
}

void Arcade::Mouse::SetOldMouse()
{
    this->_old_mouse[0] = this->_mouse[0];
    this->_old_mouse[1] = this->_mouse[1];
}

bool Arcade::Mouse::CompareMouses() const
{
    if (this->_mouse[0] == this->_old_mouse[0] &&
        this->_mouse[1] == this->_old_mouse[1])
        return (true);
    else
        return (false);
}

Actions Arcade::Mouse::GetActionByButton() const
{
    if ((this->_mouse[0] <= 45 && this->_mouse[0] >= 40) &&
        (this->_mouse[1] <= 21 && this->_mouse[1] >= 19)) {
        return (NEXT_GAME_LIB);
    }
    if ((this->_mouse[1] <= 205 && this->_mouse[1] >= 180) &&
        (this->_mouse[0] <= 780 && this->_mouse[0] >= 715)) {
        return (NEXT_GRAPHICAL_LIB);
    }
    if ((this->_mouse[1] <= 380 && this->_mouse[1] >= 360) &&
        (this->_mouse[0] <= 780 && this->_mouse[0] >= 715)) {
        return (NEXT_GAME_LIB);
    }
    if ((this->_mouse[0] <= 45 && this->_mouse[0] >= 40) &&
        (this->_mouse[1] <= 11 && this->_mouse[1] >= 9)) {
        return (NEXT_GRAPHICAL_LIB);
    }
    return (NO_ACTIONS);
}
