/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Score
*/

#include "Score.hpp"

void Arcade::Score::SetScore(unsigned int score)
{
    this->_score = score;
}

void Arcade::Score::SetUsername(std::string &username)
{
    this->_username = username;
}

unsigned int Arcade::Score::GetScore() const
{
    return (this->_score);
}

void Arcade::Score::SaveScoreInFile()
{
    std::ofstream file;
    file.open("score", std::ofstream::out | std::ofstream::app);
    file << this->_username << "," << this->_score << std::endl;
    file.close();
}