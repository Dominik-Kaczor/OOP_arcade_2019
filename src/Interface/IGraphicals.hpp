/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** IGraphicals
*/

#ifndef IGRAPHICAL_HPP_
#define IGRAPHICAL_HPP_
#include <iostream>
#include <vector>
#include "Texture.hpp"
#include "Key.hpp"

/*!
    Game interface
*/
class IGraphicals {
public:
    virtual bool is_mouse_clicked() = 0;
    /// Initialize the window (open it)
    ///
    /// @returns nothing
    ///
    virtual void InitWindow() = 0;
    /// Check if the window is open
    ///
    /// @returns boolean
    ///
    virtual bool IsWindowOpen() = 0;
    /// Close the window
    ///
    /// @returns nothing
    ///
    virtual void CloseWindow() = 0;
    /// Print the block/sprite on the window
    /// @param x position
    /// @param y position
    /// @param BlockEnum block/sprite
    /// @returns nothing
    ///
    virtual void PrintBlock(const float, const float, Texture texture) = 0;
    /// Print text on the window
    /// @param x position
    /// @param y position
    /// @param ColorEnum color
    /// @param str to_print
    /// @returns nothing
    ///
    virtual void PrintText(const float, const float, const int,
                           const std::string &) = 0;
    /// Send display instruction to the graphical interface
    /// @returns nothing
    ///
    virtual void DisplayWindow() = 0;
    /// Clean the window (mostly black color)
    /// @returns nothing
    ///
    virtual void ClearWindow() = 0;
    /// Get the key pressed in the window
    /// @returns KeyEnum
    ///
    virtual KeyEnum KeyPressed() = 0;
    /// Get the mouse position on the screen
    /// @returns std::vector<int>
    ///
    virtual std::vector<int> GetMousePosition() = 0;
    /// Get the player username in the menu
    /// @returns std::string
    ///
    virtual std::string GetPlayerUsername() = 0;
    /// Process every input in the graphical library
    ///
    /// @returns nothing
    ///
    virtual void ProcessInput() = 0;

protected:
private:
};

#endif
