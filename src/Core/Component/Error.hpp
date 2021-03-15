/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Error
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_
#include <iostream>
#include "Constants.hpp"

namespace Arcade {
    namespace Error {
        void Print(const std::string &error)
        {
            std::cerr << error << std::endl;
        }
        void Exit(const short error = Constants::TEK_EXIT_FAILRUE)
        {
            std::exit(error);
        }
    } // namespace Error
} // namespace Arcade
#endif /* !ERROR_HPP_ */
