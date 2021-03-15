/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** IGames
*/

#ifndef IGAMES_HPP_
#define IGAMES_HPP_
#include <iostream>
#include <vector>
#include "Key.hpp"

/// Used by the core to check the state of the game
///
enum WinCondition { WIN, LOSE, NOT_ENDED };

/*!
    Game interface
*/
class IGames {
public:
    /// Virtual destructor
    ///
    /// @returns nothing
    ///
    virtual ~IGames() = default;
    /// Init every variables needed by the game
    ///
    /// @returns nothing
    ///
    virtual void initialization() = 0;
    /// Exit the game
    ///
    /// @returns nothing
    ///
    virtual void exit() = 0;
    /// Get the state of the game
    ///
    /// @returns WinCondition to determine if the game is ended or not
    ///
    virtual WinCondition loop() = 0;
    /// Get the map of the game
    ///
    /// @returns Map in a two dimensional vector
    ///
    virtual std::vector<std::vector<int>> getMap() const = 0;
    /// Get the score of the game
    ///
    /// @returns Current score in the game
    ///
    virtual int getScore() const = 0;
    /// Send the input of the core to the game to determine the action to do
    /// @param KeyNum& The key pressed by the player
    /// @returns nothing
    ///
    virtual void getKey(KeyEnum) = 0;
    /// Return the name of the game
    ///
    /// @returns std::string name
    ///
    virtual std::string getName() const = 0;

protected:
private:
};

#endif /* !IGAMES_HPP_ */
