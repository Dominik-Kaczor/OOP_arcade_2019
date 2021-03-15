/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** Nibbler
*/

#include "Nibbler.hpp"

std::vector<int> Nibbler::parse_line(std::string &line) const
{
    std::vector<int> new_line;

    for (int i = 0; i < line.size(); i++)
        new_line.push_back(line[i] - '0');
    return (new_line);
}

Nibbler::Nibbler() : _score(0), _new_Key(UNDEFINED), _direction(DOWN), _name("Nibbler")
{
}

std::string Nibbler::getName() const
{
    return _name;
}

void Nibbler::initialization()
{
    _map = {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };
    _snake.push_back({10, 11});
    _snake.push_back({10, 10});
    _snake.push_back({10, 9});
    _snake.push_back({10, 8});

    std::srand(std::time(nullptr));
    newApple();
}

Nibbler::~Nibbler()
{
    exit();
}

void Nibbler::exit()
{    
    _map.clear();
    _snake.clear();
}

std::vector<std::vector<int>> Nibbler::getMap() const
{
    return _map;
}

void Nibbler::newApple()
{
    while (1) {
        int x = std::rand() % (_map[0].size() - 1) + 1;
        int y = std::rand() % (_map.size() - 1) + 1;
        if (_map[y][x] == 0) {
            _map[y][x] = 3;
            break;
        }
    }
}

WinCondition Nibbler::increaseSnake(int hx, int hy)
{
    _snake.push_back({0, 0});
    _map[hy][hx] = 2;
    updateSnake(hx, hy);
    if (checkWin() == true)
        return WIN;
    newApple();
    _score++;
    return NOT_ENDED;
}

void Nibbler::getKey(KeyEnum Key)
{
    if (Key == UNDEFINED)
        return;
    _new_Key = Key;
    return;
}

void Nibbler::updateSnake(int hx, int hy)
{
    int x = _snake[0][0];
    int y = _snake[0][1];

    _snake[0][0] = hx;
    _snake[0][1] = hy;
    for (int i = 1; i < _snake.size(); i++) {
        hx = _snake[i][0];
        hy = _snake[i][1];
        _snake[i][0] = x;
        _snake[i][1] = y;
        x = hx;
        y = hy;
    }
    return;
}

void Nibbler::updateMap(int hx, int hy)
{
    int lx = _snake[_snake.size() - 1][0];
    int ly = _snake[_snake.size() - 1][1];

    _map[hy][hx] = 2;
    _map[ly][lx] = 0;
    return;
}

WinCondition Nibbler::moveSnake(int hx, int hy)
{
    if (_map[hy][hx] == 1 || _map[hy][hx] == 2)
        return LOSE;
    if (_map[hy][hx] == 3)
        return increaseSnake(hx, hy);
    updateMap(hx, hy);
    updateSnake(hx, hy);
    return NOT_ENDED;
}

void Nibbler::checkDirection()
{
    switch (_new_Key) {
    case LEFT: {
        switch (_direction) {
        case LEFT:
            _new_Key = DOWN;
            break;
        case UP:
            _new_Key = LEFT;
            break;
        case RIGHT:
            _new_Key = UP;
            break;
        case DOWN:
            _new_Key = LEFT;
            break;
        }
        break;
    }
    case RIGHT: {
        switch (_direction) {
        case LEFT:
            _new_Key = UP;
            break;
        case UP:
            _new_Key = RIGHT;
            break;
        case RIGHT:
            _new_Key = DOWN;
            break;
        case DOWN:
            _new_Key = RIGHT;
            break;
        }
        break;
    }
    }
    return;
}

bool Nibbler::checkWin() const
{
    for (int i = 0; i < _map.size(); i++) {
        for (int j = 0; j < _map[i].size(); j++) {
            if (_map[i][j] == 0)
                return false;
        }
    }
    return true;
}

WinCondition Nibbler::loop()
{
    int sx = _snake[0][0];
    int sy = _snake[0][1];

    if (checkWin() == true)
        return WIN;
    if (_new_Key != RIGHT && _new_Key != LEFT)
        _new_Key = _direction;
    else
        checkDirection();
    _direction = _new_Key;
    _new_Key = UNDEFINED;
    switch (_direction) {
    case UP:
        return moveSnake(sx, sy - 1);
    case RIGHT:
        return moveSnake(sx + 1, sy);
    case DOWN:
        return moveSnake(sx, sy + 1);
    case LEFT:
        return moveSnake(sx - 1, sy);
    }
    return NOT_ENDED;
}

int Nibbler::getScore() const
{
    return _score;
}

extern "C" IGames *constructor()
{
    return new Nibbler;
}