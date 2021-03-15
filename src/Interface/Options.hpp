/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Options
*/

#ifndef OPTIONS_HPP_
#define OPTIONS_HPP_
#include <iostream>

static const int MAX_OPTIONS_MENU = 4;

static const std::string options[] = {
    "Username:", "Graphical lib:", "Game:", "Enter"};

enum OPTIONS_SELECT {
    NEXT=1,
    PREVIOUS=1,
    FIRST=0,
    LAST=3,
    OUT_OF_BOUNDS=5,
};

#endif /* !OPTIONS_HPP_ */
