/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** Pacman
*/

#include "Pacman.hpp"
#include "Map.hpp"
#define NEXT_POSITION \
    (_map->_map[_player->_position.first + y][_player->_position.second + x])

Ghost::Ghost(int x, int y) : _position(std::make_pair(x, y))
{
}

Player::Player(int x, int y)
    : _position(std::make_pair(x, y)), _is_weak(true), _time(0)
{
}

Ghost::~Ghost()
{
}

Player::~Player()
{
}

std::vector<int> Map::ParseLine(std::string &line) const
{
    std::vector<int> new_line;

    for (int i = 0; i < line.size(); i++)
        new_line.push_back(line[i] - '0');
    return (new_line);
}

Map::Map()
{
    _map = {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,7,3,3,3,3,3,3,3,3,3,3,3,1,1,3,3,3,3,3,3,3,3,3,3,3,7,1},
        {1,3,1,1,1,1,3,1,1,1,1,1,3,1,1,3,1,1,1,1,1,3,1,1,1,1,3,1},
        {1,3,1,1,1,1,3,1,1,1,1,1,3,1,1,3,1,1,1,1,1,3,1,1,1,1,3,1},
        {1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1},
        {1,3,1,1,1,1,3,1,1,3,1,1,1,1,1,1,1,1,3,1,1,3,1,1,1,1,3,1},
        {1,3,3,3,3,3,3,1,1,3,3,3,3,1,1,3,3,3,3,1,1,3,3,3,3,3,3,1},
        {1,1,1,1,1,1,3,1,1,1,1,1,3,1,1,3,1,1,1,1,1,3,1,1,1,1,1,1},
        {0,0,0,0,0,1,3,1,1,3,3,3,3,3,3,3,3,3,3,1,1,3,1,0,0,0,0,0},
        {0,0,0,0,0,1,3,1,1,3,3,1,1,5,1,1,3,3,3,1,1,3,1,0,0,0,0,0},
        {1,1,1,1,1,1,3,1,1,3,3,1,0,0,0,1,3,3,3,1,1,3,1,1,1,1,1,1},
        {6,3,3,3,3,3,3,3,3,3,3,1,1,1,1,1,3,3,3,3,3,3,3,3,3,3,3,6},
        {1,1,1,1,1,1,3,1,1,3,3,3,3,3,3,3,3,3,3,1,1,3,1,1,1,1,1,1},
        {0,0,0,0,0,1,3,1,1,3,3,3,3,3,3,3,3,3,3,1,1,3,1,0,0,0,0,0},
        {1,1,1,1,1,1,3,1,1,3,1,1,1,1,1,1,1,1,3,1,1,3,1,1,1,1,1,1},
        {1,3,3,3,3,3,3,3,3,3,3,3,3,1,1,3,3,3,3,3,3,3,3,3,3,3,3,1},
        {1,3,1,1,1,1,3,1,1,1,1,1,3,1,1,3,1,1,1,1,1,3,1,1,1,1,3,1},
        {1,7,3,3,1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,3,3,7,1},
        {1,1,1,3,1,1,3,1,1,3,1,1,1,1,1,1,1,1,3,1,1,3,1,1,3,1,1,1},
        {1,3,3,3,3,3,3,1,1,3,3,3,3,1,1,3,3,3,3,1,1,3,3,3,3,3,3,1},
        {1,3,1,1,1,1,1,1,1,1,1,1,0,1,1,3,1,1,1,1,1,1,1,1,1,1,3,1},
        {1,7,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,7,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
}

Map::~Map()
{
}

Pacman::Pacman() : _score(0), _lose(false), _name("Pacman")
{
}

std::string Pacman::getName() const
{
    return _name;
}

void Pacman::initialization()
{
    this->_player = new Player(20, 12);
    this->_map = new (Map);
    this->_ennemies.push_back(new Ghost(10, 12));
    this->_ennemies.push_back(new Ghost(10, 13));
    this->_ennemies.push_back(new Ghost(10, 14));
    this->_ennemies.push_back(new Ghost(8, 13));
}

Pacman::~Pacman()
{
    exit();
}

void Pacman::exit()
{
    for (int i = 0; i != _ennemies.size(); i++)
        delete (_ennemies[i]);
    this->_ennemies.clear();
    delete (this->_player);
    delete (this->_map);
}

void Pacman::getKey(KeyEnum key)
{
    _key = key;
    if (_key == KeyEnum::UP)
        Move(DirectionsEnum::NO_DIRECTIONS, DirectionsEnum::DIR_UP);
    if (_key == KeyEnum::DOWN)
        Move(DirectionsEnum::NO_DIRECTIONS, DirectionsEnum::DIR_DOWN);
    if (_key == KeyEnum::LEFT)
        Move(DirectionsEnum::DIR_LEFT, DirectionsEnum::NO_DIRECTIONS);
    if (_key == KeyEnum::RIGHT)
        Move(DirectionsEnum::DIR_RIGHT, DirectionsEnum::NO_DIRECTIONS);
}

int Pacman::GetDeadGhost(void)
{
    for (int i = 0; i < _ennemies.size(); i++) {
        if (_ennemies[i]->_position == _player->_position)
            return i;
    }
    return -1;
}

void Pacman::Move(int x, int y)
{
    if (NEXT_POSITION == MapEnum::WALL || NEXT_POSITION == MapEnum::DOOR)
        return;
    switch (NEXT_POSITION) {
    case (MapEnum::SUPER_FOOD):
        this->_score += 10;
        this->_player->_is_weak = false;
        NEXT_POSITION = MapEnum::VOID;
        break;
    case (MapEnum::FOOD):
        this->_score += 1;
        NEXT_POSITION = MapEnum::VOID;
        break;
    case (MapEnum::TP):
        if (x == 1) {
            _map->_map[_player->_position.first][1] = 0;
            _player->_position.second = 1;
            return;
        } else {
            _map->_map[_player->_position.first][26] = 0;
            _player->_position.second = 26;
            return;
        }
    }
    this->_player->_position.first += y;
    this->_player->_position.second += x;
    std::vector<std::pair<int, int>> ghosts = this->GetGhostsPositions();
    if (std::count(ghosts.begin(), ghosts.end(), this->_player->_position) !=
        0) {
        if (_player->_is_weak == true)
            this->_lose = true;
        else {
            int pos = GetDeadGhost();
            if (pos != -1) {
                _ennemies[pos]->_position.first = 10;
                _ennemies[pos]->_position.second = 13;
            }
        }
    }
}

int Pacman::getScore() const
{
    return (this->_score);
}

std::vector<std::vector<int>> Pacman::getMap() const
{
    std::vector<std::vector<int>> clone(this->_map->_map);

    clone[this->_player->_position.first][this->_player->_position.second] =
        MapEnum::PLAYER;
    for (int i = 0; i < this->_ennemies.size(); i++) {
        if (_player->_is_weak)
            clone[this->_ennemies[i]->_position.first]
                 [this->_ennemies[i]->_position.second] = MapEnum::ENEMY;
        else
            clone[this->_ennemies[i]->_position.first]
                 [this->_ennemies[i]->_position.second] = MapEnum::WEAK_EN;
    }
    return (clone);
}

int Ghost::IA(std::vector<std::pair<int, int>> moves,
              std::pair<int, int> player, bool weak)
{
    int i = 0;
    std::vector<int> dists;
    for (i = 0; i < moves.size(); i++) {
        int dx = std::pow((moves[i].first - player.first), 2);
        int dy = std::pow((moves[i].second - player.second), 2);
        dists.push_back(std::sqrt(dx + dy));
    }
    if (weak == true)
        return std::min_element(dists.begin(), dists.end()) - dists.begin();
    else
        return std::max_element(dists.begin(), dists.end()) - dists.begin();
}

void Ghost::MoveGhosts(std::vector<std::vector<int>> map,
                       std::vector<std::pair<int, int>> ghosts,
                       std::pair<int, int> player, bool weak)
{
    std::vector<std::pair<int, int>> posibilities;
    std::srand(std::time(nullptr));
    if (map[_position.first][_position.second + 1] != 1 &&
        !std::count(ghosts.begin(), ghosts.end(),
                    std::make_pair(_position.first, _position.second + 1)))
        posibilities.push_back(
            std::make_pair(_position.first, _position.second + 1));
    if (map[_position.first][_position.second - 1] != 1 &&
        !std::count(ghosts.begin(), ghosts.end(),
                    std::make_pair(_position.first, _position.second - 1)))
        posibilities.push_back(
            std::make_pair(_position.first, _position.second - 1));
    if (map[_position.first + 1][_position.second] != 1 &&
        !std::count(ghosts.begin(), ghosts.end(),
                    std::make_pair(_position.first + 1, _position.second)))
        posibilities.push_back(
            std::make_pair(_position.first + 1, _position.second));
    if (map[_position.first - 1][_position.second] != 1 &&
        !std::count(ghosts.begin(), ghosts.end(),
                    std::make_pair(_position.first - 1, _position.second)))
        posibilities.push_back(
            std::make_pair(_position.first - 1, _position.second));
    if (posibilities.size() == 0)
        return;
    int choice = IA(posibilities, player, weak);
    _position = posibilities[choice];
    if (map[_position.first][_position.second] == 6) {
        if (_position.second == 0)
            _position.second = 26;
        else
            _position.second = 1;
    }
}

std::vector<std::pair<int, int>> Pacman::GetGhostsPositions()
{
    std::vector<std::pair<int, int>> positions;

    for (int i = 0; i < this->_ennemies.size(); i++) {
        positions.push_back(this->_ennemies[i]->_position);
    }
    return (positions);
}

WinCondition Pacman::loop()
{
    if (_score == 339)
        return (WinCondition::WIN);
    if (_player->_is_weak == false)
        _player->_time += 1;
    if (_player->_time == 30) {
        _player->_time = 0;
        _player->_is_weak = true;
    }
    if (this->_lose == true)
        return (WinCondition::LOSE);
    for (int i = 0; i < this->_ennemies.size(); i++)
        this->_ennemies[i]->MoveGhosts(this->_map->_map, GetGhostsPositions(),
                                       _player->_position, _player->_is_weak);
    for (int i = 0; i < _ennemies.size(); i++) {
        if (_player->_is_weak == true) {
            if (std::pair<int, int>(this->_player->_position.first,
                                    this->_player->_position.second) ==
                this->_ennemies[i]->_position)
                return (WinCondition::LOSE);
        }
    }
    return (WinCondition::NOT_ENDED);
}

extern "C" IGames *constructor()
{
    return new Pacman;
}