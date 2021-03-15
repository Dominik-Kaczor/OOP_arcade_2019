/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** Key
*/

#ifndef KEY_HPP_
#define KEY_HPP_

/*!
    Key Enumeration
*/
enum KeyEnum {
    UP = 0,                         /// Z Move up
    RIGHT,                          /// D Move right
    DOWN,                           /// S Move down
    LEFT,                           /// Q Move left
    ENTER,                          /// Enter Run selected
    SPACE,                          /// Open menu
    UNDEFINED,                      /// No Key Pressed
    SYS_PREVIOUS_GRAPHICAL_LIBRARY, /// O Go to previous lib
    SYS_NEXT_GRAPHICAL_LIBRARY,     /// P Go to next lib
    SYS_PREVIOUS_GAME,              /// L Go to previous game
    SYS_NEXT_GAME,                  /// M Go to next game
    SYS_RESTART,                    /// X Restart the game
    SYS_BACK_TO_MENU,               /// Echap
    SYS_EXIT                        /// W exit Aracade
};

#endif /* !KEY_HPP_ */
