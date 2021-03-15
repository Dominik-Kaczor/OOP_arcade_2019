/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <ctime>
#include "Interface/IGames.hpp"

class Map {
private:
    std::vector<int> ParseLine(std::string &test) const;

public:
    Map();
    ~Map();
    std::vector<std::vector<int>> _map;
};

class Ghost {
public:
    Ghost(int x, int y);
    ~Ghost();
    void MoveGhosts(std::vector<std::vector<int>> map,
                    std::vector<std::pair<int, int>> ghosts,
                    std::pair<int, int> player, bool weak);
    int IA(std::vector<std::pair<int, int>> moveable,
           std::pair<int, int> player, bool weak);
    std::pair<int, int> _position;
};

class Player {
public:
    Player(int x, int y);
    ~Player();
    std::pair<int, int> _position;
    bool _is_weak;
    int _time;
};

class Pacman : public IGames {
public:
    Pacman();
    ~Pacman();
    WinCondition loop();
    void initialization();
    void exit();
    std::vector<std::vector<int>> getMap() const;
    int getScore() const;
    void getKey(KeyEnum);
    int GetDeadGhost(void);
    std::vector<std::pair<int, int>> GetGhostsPositions();
    void Move(int, int);
    std::string getName() const;

protected:
private:
    Player *_player;
    std::vector<Ghost *> _ennemies;
    Map *_map;
    int _score;
    bool _lose;
    KeyEnum _key;
    std::string _name;
};

#endif /* !PACMAN_HPP_ */
