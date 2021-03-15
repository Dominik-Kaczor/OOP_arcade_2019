/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** SDL
*/

#include "SDL.hpp"
#include "Interface/Colors.hpp"

SDL::SDL() : _key(UNDEFINED), _mouse(false)
{
    TTF_Init();
    this->_font = TTF_OpenFont("storage/font.ttf", 20);
}

SDL::~SDL()
{
}

void SDL::InitWindow()
{
    this->_window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED,
                                     SDL_WINDOWPOS_CENTERED, 1000, 1000, 0);
    this->_renderer = SDL_CreateRenderer(this->_window, -1, 0);
}

void SDL::PrintBlock(const float a, const float b, Texture c)
{
    SDL_Rect block;
    block.x = 18 * b;
    block.y = 18 * a;
    block.w = 20;
    block.h = 20;
    switch (c) {
    case WALL: {
        SDL_SetRenderDrawColor(this->_renderer, 0, 102, 255, 255);
        SDL_RenderDrawRect(this->_renderer, &block);
        SDL_SetRenderDrawColor(this->_renderer, 0, 102, 255, 255);
        break;
    }
    case PLAYER: {
        SDL_SetRenderDrawColor(this->_renderer, 255, 255, 0, 255);
        SDL_RenderDrawRect(this->_renderer, &block);
        SDL_SetRenderDrawColor(this->_renderer, 255, 255, 0, 255);
        break;
    }
    case ENEMY: {
        SDL_SetRenderDrawColor(this->_renderer, 255, 255, 255, 255);
        SDL_RenderDrawRect(this->_renderer, &block);
        SDL_SetRenderDrawColor(this->_renderer, 255, 255, 255, 255);
        break;
    }
    case ITEM: {
        SDL_SetRenderDrawColor(this->_renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(this->_renderer, &block);
        SDL_SetRenderDrawColor(this->_renderer, 255, 0, 0, 255);
        break;
    }
    case SUPER_MEAT: {
        SDL_SetRenderDrawColor(this->_renderer, 0, 255, 0, 255);
        SDL_RenderDrawRect(this->_renderer, &block);
        SDL_SetRenderDrawColor(this->_renderer, 0, 255, 0, 255);
        break;
    }
    case ENNEMIES_W: {
        SDL_SetRenderDrawColor(this->_renderer, 0, 255, 255, 0);
        SDL_RenderDrawRect(this->_renderer, &block);
        SDL_SetRenderDrawColor(this->_renderer, 0, 255, 255, 0);
        break;
    }
    }
    SDL_RenderFillRect(this->_renderer, &block);
    SDL_SetRenderDrawColor(this->_renderer, 0, 0, 0, 255);
}

void SDL::PrintText(const float a, const float b, const int color,
                    const std::string &str)
{
    SDL_Surface *surfaceMessage = NULL;

    switch (color) {
    case BLUE:
        surfaceMessage =
            TTF_RenderText_Solid(_font, str.c_str(), (SDL_Color){0, 0, 255});
        break;
    case BLACK:
        surfaceMessage =
            TTF_RenderText_Solid(_font, str.c_str(), (SDL_Color){0, 0, 0});
        break;
    case RED:
        surfaceMessage =
            TTF_RenderText_Solid(_font, str.c_str(), (SDL_Color){255, 0, 0});
        break;
    case GREEN:
        surfaceMessage =
            TTF_RenderText_Solid(_font, str.c_str(), (SDL_Color){0, 255, 0});
        break;
    case WHITE:
        surfaceMessage = TTF_RenderText_Solid(_font, str.c_str(),
                                              (SDL_Color){255, 255, 255});
        break;
    default:
        surfaceMessage = TTF_RenderText_Solid(_font, str.c_str(),
                                              (SDL_Color){255, 255, 255});
        break;
    }
    if (surfaceMessage == NULL)
        return;
    SDL_Texture *Message =
        SDL_CreateTextureFromSurface(_renderer, surfaceMessage);
    SDL_Rect Message_rect = {static_cast<int>(b) * 18, static_cast<int>(a) * 18,
                             surfaceMessage->w, surfaceMessage->h};
    SDL_RenderCopy(_renderer, Message, NULL, &Message_rect);
}

bool SDL::IsWindowOpen()
{
    return (true);
}

void SDL::ProcessInput()
{
    while (SDL_PollEvent(&this->_event)) {
        switch (this->_event.type) {
        case SDL_QUIT:
            _key = KeyEnum::SYS_EXIT;
            return;
        case SDL_KEYDOWN:
            switch (this->_event.key.keysym.sym) {
            case (SDLK_z):
                _key = KeyEnum::UP;
                return;
            case (SDLK_q):
                _key = KeyEnum::LEFT;
                return;
            case (SDLK_d):
                _key = KeyEnum::RIGHT;
                return;
            case (SDLK_s):
                _key = KeyEnum::DOWN;
                return;
            case (SDLK_RETURN):
                _key = KeyEnum::ENTER;
                return;
            case (SDLK_SPACE):
                _key = KeyEnum::SPACE;
                return;
            case (SDLK_o):
                _key = KeyEnum::SYS_PREVIOUS_GRAPHICAL_LIBRARY;
                return;
            case (SDLK_p):
                _key = KeyEnum::SYS_NEXT_GRAPHICAL_LIBRARY;
                return;
            case (SDLK_l):
                _key = KeyEnum::SYS_PREVIOUS_GAME;
                return;
            case (SDLK_m):
                _key = KeyEnum::SYS_NEXT_GAME;
                return;
            case (SDLK_x):
                _key = KeyEnum::SYS_RESTART;
                return;
            case (SDLK_ESCAPE):
                _key = KeyEnum::SYS_BACK_TO_MENU;
                return;
            case (SDLK_w):
                _key = KeyEnum::SYS_EXIT;
                return;
            default:
                _key = KeyEnum::UNDEFINED;
                return;
            }
        }
    }
    _key = KeyEnum::UNDEFINED;
}

bool SDL::is_mouse_clicked()
{
    return _mouse;
}

KeyEnum SDL::KeyPressed()
{
    this->ProcessInput();
    return _key;
}

std::vector<int> SDL::GetMousePosition()
{
    std::vector<int> positon;

    if (this->_event.type == SDL_MOUSEBUTTONUP) {
        if (this->_event.button.button == SDL_BUTTON_LEFT) {
            positon.push_back(this->_event.button.x);
            positon.push_back(this->_event.button.y);
            _mouse = true;
            return positon;
        }
    }
    _mouse = false;
    positon.push_back(0);
    positon.push_back(0);
    return positon;
}

std::string SDL::GetPlayerUsername()
{
    return ("NULL");
}

void SDL::CloseWindow()
{
    SDL_DestroyWindow(this->_window);
}

void SDL::DisplayWindow()
{
    SDL_RenderPresent(this->_renderer);
}

void SDL::ClearWindow()
{
    SDL_RenderClear(this->_renderer);
}

extern "C" IGraphicals *constructor()
{
    return new SDL;
}