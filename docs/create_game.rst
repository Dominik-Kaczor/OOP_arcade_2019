Create a game
=============

Here is you can create a new game using our Arcade !


How ?
-----

It's very easy to create a game if your game have the following requirements :

- A two dimensional map
- A player
- One ennemy / multiples enemies
- A score manager

.. note::

    A game like the Minesweeper can be created using our Arcade !

Tutorial
--------

For the tutorial, let's assume you will create a Minesweeper.

- Create a Minesweeper.cpp and Minesweeper.hpp file in a new directory in *src/Games/*
- Includes thoses files in the Makefile in *src/Games/*
- Create a Minesweeper class that inherits from *IGames*
- Add the Interface function in your class and re-implement them for your game
- (Optional) Add others functions if needed
- Compile and run the game on the selected graphical library
- That's it, enjoy !