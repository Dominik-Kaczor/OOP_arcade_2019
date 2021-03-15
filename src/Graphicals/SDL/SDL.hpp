/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** SDL
*/

#ifndef SDL_HPP_
#define SDL_HPP_
#include "Interface/IGraphicals.hpp"
#include "Interface/Key.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>

class SDL : public IGraphicals {
public:
    SDL();
    ~SDL();
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

protected:
private:
    SDL_Window *_window;
    SDL_Renderer *_renderer;
    SDL_Event _event;
    TTF_Font *_font;
    KeyEnum _key;
    bool _mouse;
};

#endif /* !SDL_HPP_ */
