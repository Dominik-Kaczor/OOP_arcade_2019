/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** SFML
*/

#include <iostream>
#include "SFML.hpp"
#include "Interface/Colors.hpp"

SFML::SFML() : _key(UNDEFINED), _mouse(false)
{
    _font.loadFromFile("storage/font.ttf"); // faire gestion d'erreur
}

SFML::~SFML()
{
}

void SFML::InitWindow()
{
    this->_window.create(sf::VideoMode(1000, 1000), "Arcade");
}

/*
    VOID = 0,  /// Free space
    WALL,      1/// Indestructible wall
    BLOCK,     2/// Destructible wall
    PLAYER,    3/// You
    BOMB,      4/// Bomb in free space
    FIRE,      5/// Explosion in free case
    IA,        6/// Computer ennemy
    DESTROY,   7/// Explosion in wall destroy
    SPEED,     8/// Speed Up
    WALLPASS,  9/// Wall Pass
    POWER,     10/// Fire Up
    UPBOMB,    11/// Bomb Up
    PASS,      12/// You and wall destructible on the same case
    BOMBPLAYER 13/// You and bomb on the same case
*/

void SFML::PrintBlock(const float a, const float b, Texture c)
{
    switch (c) {
        case 1: {
            sf::RectangleShape block(sf::Vector2f(20, 20));
            block.setFillColor(sf::Color(0, 102, 255));
            block.setPosition(21 * b, 21 * a);
            this->_window.draw(block);
            break;
        }
        case 2: {
            sf::RectangleShape block(sf::Vector2f(20, 20));
            block.setFillColor(sf::Color(152, 138, 112));
            block.setPosition(21 * b, 21 * a);
            this->_window.draw(block);
            break;
        }
        case 3: {
            sf::CircleShape block(10);
            block.setFillColor(sf::Color(255, 255, 0));
            block.setPosition(21 * b, 21 * a);
            this->_window.draw(block);
            break;
        }
        case 4: {
            sf::CircleShape block(9, 6);
            block.setFillColor(sf::Color(255, 0, 0));
            block.setPosition(21 * b + 1, 21 * a);
            this->_window.draw(block);
            break;
        }
        case 5: {
            sf::CircleShape block(9);
            block.setFillColor(sf::Color(255, 204, 102));
            block.setPosition(21 * b, 21 * a);
            this->_window.draw(block);
            break;
        }
        case 6: {
            sf::CircleShape block(10);
            block.setFillColor(sf::Color(0, 255, 0));
            block.setPosition(21 * b, 21 * a);
            this->_window.draw(block);
            break;
        }
        case 7: {
            sf::CircleShape block(9);
            block.setFillColor(sf::Color(255, 204, 102));
            block.setPosition(21 * b, 21 * a);
            this->_window.draw(block);
            break;
        }
        case 8: {
            sf::CircleShape block(5);
            block.setFillColor(sf::Color(153, 153, 255));
            block.setPosition(21 * b + 4.5, 21 * a + 4.5);
            this->_window.draw(block);
            break;
        }
        case 9: {
            sf::CircleShape block(5);
            block.setFillColor(sf::Color(205, 51, 255));
            block.setPosition(21 * b + 4.5, 21 * a + 4.5);
            this->_window.draw(block);
            break;
        }
        case 10: {
            sf::CircleShape block(5);
            block.setFillColor(sf::Color(255, 0, 102));
            block.setPosition(21 * b + 4.5, 21 * a + 4.5);
            this->_window.draw(block);
            break;
        }
        case 11: {
            sf::CircleShape block(5);
            block.setFillColor(sf::Color(255, 51, 0));
            block.setPosition(21 * b + 4.5, 21 * a + 4.5);
            this->_window.draw(block);
            break;
        }
        case 12: {
            sf::RectangleShape block(sf::Vector2f(20, 20));
            block.setFillColor(sf::Color(152, 138, 112));
            block.setPosition(21 * b, 21 * a);
            this->_window.draw(block);
            sf::CircleShape block2(10);
            block2.setFillColor(sf::Color(255, 255, 0));
            block2.setPosition(21 * b, 21 * a);
            this->_window.draw(block2);
            break;
        }
        case 13: {
            sf::CircleShape block2(10);
            block2.setFillColor(sf::Color(255, 255, 0));
            block2.setPosition(21 * b, 21 * a);
            this->_window.draw(block2);
            sf::CircleShape block(9, 6);
            block.setFillColor(sf::Color(255, 0, 0));
            block.setPosition(21 * b + 1, 21 * a);
            this->_window.draw(block);
            break;
        }
    }
}

void SFML::PrintText(const float y, const float x, const int color,
                     const std::string &str)
{
    sf::Text text;

    text.setFont(_font);
    text.setString(str);
    text.setCharacterSize(20);
    switch (color) {
    case BLUE:
        text.setFillColor(sf::Color::Blue);
        break;
    case BLACK:
        text.setFillColor(sf::Color::Black);
        break;
    case RED:
        text.setFillColor(sf::Color::Red);
        break;
    case GREEN:
        text.setFillColor(sf::Color::Green);
        break;
    case WHITE:
        text.setFillColor(sf::Color::White);
        break;
    }
    text.setPosition(x * 18, y * 18);
    this->_window.draw(text);
}

bool SFML::IsWindowOpen()
{
    return (this->_window.isOpen());
}

bool SFML::is_mouse_clicked()
{
    return _mouse;
}

void SFML::ProcessInput()
{
    while (this->_window.pollEvent(this->_event)) {
        if (this->_event.type == sf::Event::Closed) {
            _key = KeyEnum::SYS_EXIT;
            return;
        }
        if (this->_event.type == sf::Event::KeyPressed) {
            switch (this->_event.key.code) {
            case (sf::Keyboard::Z):
                _key = KeyEnum::UP;
                return;
            case (sf::Keyboard::Q):
                _key = KeyEnum::LEFT;
                return;
            case (sf::Keyboard::D):
                _key = KeyEnum::RIGHT;
                return;
            case (sf::Keyboard::S):
                _key = KeyEnum::DOWN;
                return;
            case (sf::Keyboard::Return):
                _key = KeyEnum::ENTER;
                return;
            case (sf::Keyboard::Space):
                _key = KeyEnum::SPACE;
                return;
            case (sf::Keyboard::O):
                _key = KeyEnum::SYS_PREVIOUS_GRAPHICAL_LIBRARY;
                return;
            case (sf::Keyboard::P):
                _key = KeyEnum::SYS_NEXT_GRAPHICAL_LIBRARY;
                return;
            case (sf::Keyboard::L):
                _key = KeyEnum::SYS_PREVIOUS_GAME;
                return;
            case (sf::Keyboard::M):
                _key = KeyEnum::SYS_NEXT_GAME;
                return;
            case (sf::Keyboard::X):
                _key = KeyEnum::SYS_RESTART;
                return;
            case (sf::Keyboard::Escape):
                _key = KeyEnum::SYS_BACK_TO_MENU;
                return;
            case (sf::Keyboard::W):
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

KeyEnum SFML::KeyPressed()
{
    this->ProcessInput();
    return _key;
}

std::vector<int> SFML::GetMousePosition()
{
    std::vector<int> positon;

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        _mouse = true;
        sf::Vector2i localPosition = sf::Mouse::getPosition(_window);
        positon.push_back(localPosition.x);
        positon.push_back(localPosition.y);
        return positon;
    }
    _mouse = false;
    positon.push_back(0);
    positon.push_back(0);
    return positon;
}

std::string SFML::GetPlayerUsername()
{
    return ("Anton");
}

void SFML::CloseWindow()
{
    this->_window.close();
}

void SFML::DisplayWindow()
{
    this->_window.display();
}

void SFML::ClearWindow()
{
    this->_window.clear(sf::Color::Black);
}

extern "C" IGraphicals *constructor()
{
    return new SFML;
}
