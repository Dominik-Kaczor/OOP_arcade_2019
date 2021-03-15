/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** Constants
*/

#ifndef CONSTANTS_HPP_
#define CONSTANTS_HPP_
#include <iostream>
#include <vector>

namespace Constants {
    static const int TEK_EXIT_SUCCESS = 0;
    static const int TEK_EXIT_FAILRUE = 84;
    static const int MINIMAL_ARGUMENTS = 2;
    static const int LIBC_ERROR = -1;
    static const int DL_ERROR = 0;
    static const int NB_CHAR_EXT_LIB = 11;
    static const int BASE_CLOCK = 250;
    static const double FPS = 60;
    static const std::string STRING_NULL = "NULL";
    static const std::string FLAG_HELP = "--help";
    static const std::string FLAG_HELP_LITTLE = "-h";
    static const std::string LIB_EXT = ".so";
    static const std::string LIB_FIRST_EXT = "lib_arcade_";
    static const std::string USAGE =
        "USAGE\n\t./arcade lib_aracade_[sfml|ncurses|sdl]\n\t./arcade "
        "[-h|--help]\n\nDESCRIPTION\n\tArcade "
        "is a gaming platform: a program that lets the user choose a game to "
        "play "
        "and keeps a register of player scores.\n";
    static const std::string PREFIX_GAMES = "games/";
    static const std::string PREFIX_LIBS = "lib/";
    static const std::string ASK_FOR_USERNAME = "Please enter your username";
    static const std::string NO_GAMES = "No games";
    static const std::string LIB_NOT_IN_LIBS = "All libraries must be in lib folder !";
    static const std::string SCORE = "Score = ";
    static const std::string CONSTRUCTOR = "constructor";
    static const std::string ERROR_ARGS = "Not enough arguments";
}; // namespace Constants

#endif /* !CONSTANTS_HPP_ */
