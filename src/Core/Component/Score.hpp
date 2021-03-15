/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Score
*/

#ifndef SCORE_HPP_
#define SCORE_HPP_
#include <iostream>
#include <fstream>

namespace Arcade {
    class Score {
    public:
        void SetScore(unsigned int);
        void SetUsername(std::string &);
        void SaveScoreInFile();
        unsigned int GetScore() const;

    protected:
    private:
        unsigned int _score;
        std::string _username;
    };
} // namespace Arcade

#endif /* !SCORE_HPP_ */
