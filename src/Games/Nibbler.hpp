/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** Nibbler
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include "Interface/IGames.hpp"

class Nibbler : public IGames {
public:
    Nibbler();
    ~Nibbler();
    void initialization();
    void exit();
    std::vector<std::vector<int>> getMap() const;
    WinCondition loop();
    int getScore() const;
    void getKey(KeyEnum);
    WinCondition moveSnake(int, int);
    void newApple();
    bool checkWin() const;
    WinCondition increaseSnake(int, int);
    void updateSnake(int, int);
    void updateMap(int, int);
    std::string getName() const;
    void checkDirection();
    std::vector<int> parse_line(std::string &test) const;

private:
    std::vector<std::vector<int>> _map;
    std::vector<std::vector<int>> _snake;
    int _score;
    KeyEnum _direction;
    KeyEnum _new_Key;
    std::string _name;
};

#endif /* !NIBBLER_HPP_ */
