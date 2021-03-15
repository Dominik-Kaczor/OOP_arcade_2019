/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Mouse
*/

#ifndef MOUSE_HPP_
#define MOUSE_HPP_
#include <vector>
#include "Interface/Actions.hpp"

namespace Arcade {
    class Mouse {
    public:
        Mouse();
        void SetMouse(int, int);
        void SetOldMouse();
        bool CompareMouses() const;
        Actions GetActionByButton() const;

    protected:
    private:
        std::vector<int> _mouse;
        std::vector<int> _old_mouse;
    };
} // namespace Arcade

#endif /* !MOUSE_HPP_ */
