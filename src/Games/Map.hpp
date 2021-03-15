/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

enum MapEnum {
    VOID = 0,
    WALL,
    PLAYER,
    FOOD,
    ENEMY,
    DOOR,
    TP,
    SUPER_FOOD,
    WEAK_EN
};

enum DirectionsEnum {
    DIR_LEFT = -1,
    DIR_RIGHT = 1,
    DIR_UP = -1,
    DIR_DOWN = 1,
    NO_DIRECTIONS = 0
};

#endif /* !MAP_HPP_ */
