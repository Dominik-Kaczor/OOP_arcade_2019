/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** SFML
*/

#ifndef SFML_HPP_
#define SFML_HPP_
#include <SFML/Graphics.hpp>
#include "Interface/IGraphicals.hpp"
#include "Interface/Key.hpp"

class SFML : public IGraphicals {
public:
    SFML();
    ~SFML();
    void InitWindow();
    bool IsWindowOpen();
    void CloseWindow();
    void PrintBlock(const float, const float, Texture texture);
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
    sf::RenderWindow _window;
    sf::Font _font;
    sf::Event _event;
    bool _mouse;
    KeyEnum _key;
};

#endif /* !SFML_HPP_ */
