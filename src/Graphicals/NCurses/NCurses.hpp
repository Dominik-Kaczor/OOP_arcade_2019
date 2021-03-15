/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** NCurses
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include <ncurses.h>
#include "Interface/IGraphicals.hpp"
#include "Interface/Key.hpp"

class NCurses : public IGraphicals {
public:
    NCurses();
    ~NCurses();
    void InitWindow();
    bool IsWindowOpen();
    void CloseWindow();
    void PrintBlock(const float, const float, Texture c);
    void PrintText(const float, const float, const int, const std::string &);
    void DisplayWindow();
    void ClearWindow();
    KeyEnum KeyPressed();
    std::vector<int> GetMousePosition();
    std::string GetPlayerUsername();
    void ProcessInput();
    bool is_mouse_clicked();

private:
    KeyEnum _key;
    MEVENT _event;
    int _first;
    bool _mouse;
};

#endif /* !NCURSES_HPP_ */
