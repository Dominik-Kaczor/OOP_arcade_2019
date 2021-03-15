/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** NCurses
*/

#include "NCurses.hpp"
#include "Interface/Colors.hpp"

NCurses::NCurses() : _key(UNDEFINED), _first(0), _mouse(false)
{
}

NCurses::~NCurses()
{
}

void NCurses::InitWindow()
{
    initscr();
    curs_set(0);
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    start_color();
    init_pair(1, COLOR_RED, COLOR_RED);
    init_pair(2, COLOR_BLUE, COLOR_BLUE);
    init_pair(3, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(4, COLOR_GREEN, COLOR_GREEN);
    init_pair(5, COLOR_WHITE, COLOR_WHITE);
    init_pair(6, COLOR_BLACK, COLOR_BLACK);
    init_pair(7, COLOR_RED, COLOR_BLACK);
    init_pair(8, COLOR_CYAN, COLOR_CYAN);
    init_pair(11, COLOR_RED, COLOR_BLACK);
    init_pair(12, COLOR_BLUE, COLOR_BLACK);
    init_pair(13, COLOR_YELLOW, COLOR_BLACK);
    init_pair(14, COLOR_GREEN, COLOR_BLACK);
    init_pair(15, COLOR_WHITE, COLOR_BLACK);
    init_pair(16, COLOR_BLACK, COLOR_BLACK);
    init_pair(17, COLOR_RED, COLOR_BLACK);
    init_pair(18, COLOR_CYAN, COLOR_BLACK);
}

void NCurses::PrintBlock(const float a, const float b, Texture c)
{
    if (c == 5) {
        attron(COLOR_PAIR(6));
        mvprintw(static_cast<int>(a), static_cast<int>(b), " ");
    }
    if (c == 1) {
        attron(COLOR_PAIR(2));
        mvprintw(static_cast<int>(a), static_cast<int>(b), " ");
    }
    if (c == 0) {
        attron(COLOR_PAIR(6));
        mvprintw(static_cast<int>(a), static_cast<int>(b), " ");
    }
    if (c == 4) {
        attron(COLOR_PAIR(1));
        mvprintw(static_cast<int>(a), static_cast<int>(b), " ");
    }
    if (c == 3) {
        attron(COLOR_PAIR(5));
        mvprintw(static_cast<int>(a), static_cast<int>(b), " ");
    }
    if (c == 2) {
        attron(COLOR_PAIR(3));
        mvprintw(static_cast<int>(a), static_cast<int>(b), " ");
    }
    if (c == 7) {
        attron(COLOR_PAIR(4));
        mvprintw(static_cast<int>(a), static_cast<int>(b), " ");
    }
    if (c == 8) {
        attron(COLOR_PAIR(8));
        mvprintw(static_cast<int>(a), static_cast<int>(b), " ");
    }
}

void NCurses::PrintText(const float a, const float b, const int color,
                        const std::string &str)
{
    switch (color) {
    case BLUE:
        attron(COLOR_PAIR(12));
        break;
    case BLACK:
        attron(COLOR_PAIR(16));
        break;
    case RED:
        attron(COLOR_PAIR(11));
        break;
    case GREEN:
        attron(COLOR_PAIR(14));
        break;
    case WHITE:
        attron(COLOR_PAIR(15));
        break;
    default:
        attron(COLOR_PAIR(16));
        break;
    }
    mvprintw(static_cast<int>(a), static_cast<int>(b), str.c_str());
}

bool NCurses::IsWindowOpen()
{
    return (true);
}

void NCurses::ProcessInput()
{
    MEVENT event;
    int character = wgetch(stdscr);

    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
    switch (character) {
    case 'z':
        _key = KeyEnum::UP;
        return;
    case 'd':
        _key = KeyEnum::RIGHT;
        return;
    case 'q':
        _key = KeyEnum::LEFT;
        return;
    case 's':
        _key = KeyEnum::DOWN;
        return;
    case 10:
        _key = KeyEnum::ENTER;
        return;
    case ' ':
        _key = KeyEnum::SPACE;
        return;
    case 'o':
        _key = KeyEnum::SYS_PREVIOUS_GRAPHICAL_LIBRARY;
        return;
    case 'p':
        _key = KeyEnum::SYS_NEXT_GRAPHICAL_LIBRARY;
        return;
    case 'l':
        _key = KeyEnum::SYS_PREVIOUS_GAME;
        return;
    case 'm':
        _key = KeyEnum::SYS_NEXT_GAME;
        return;
    case 'x':
        _key = KeyEnum::SYS_RESTART;
        return;
    case 27:
        _key = KeyEnum::SYS_BACK_TO_MENU;
        return;
    case 'w':
        _key = KeyEnum::SYS_EXIT;
        return;
    case KEY_MOUSE:
        _event = event;
        return;
    default:
        _key = KeyEnum::UNDEFINED;
        return;
    }
    _key = KeyEnum::UNDEFINED;
}

KeyEnum NCurses::KeyPressed()
{
    this->ProcessInput();
    return _key;
}

bool NCurses::is_mouse_clicked()
{
    return _mouse;
}

std::vector<int> NCurses::GetMousePosition()
{
    std::vector<int> positon;

    if (getmouse(&_event) == OK && BUTTON1_PRESSED) {
        positon.push_back(_event.x);
        positon.push_back(_event.y);
        _mouse = true;
        return positon;
    }
    _mouse = false;
    positon.push_back(0);
    positon.push_back(0);
    return positon;
}

std::string NCurses::GetPlayerUsername()
{
    return ("Anton");
}

void NCurses::CloseWindow()
{
    endwin();
}

void NCurses::DisplayWindow()
{
    refresh();
}

void NCurses::ClearWindow()
{
    if (_first == 1000) {
        erase();
        _first = 0;
    } else {
        _first++;
    }
}

extern "C" IGraphicals *constructor()
{
    return new NCurses;
}