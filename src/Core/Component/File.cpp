/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** File
*/

#include <iostream>
#include "File.hpp"

Arcade::File::File(std::string &filename)
{
    this->_filename = filename;
}

Arcade::File::File(const char *filename)
{
    std::string _new_filename(filename);
    this->_filename = _new_filename;
}

void Arcade::File::SetFilename(std::string &filename)
{
    this->_filename = filename;
}
Arcade::File::~File()
{
}

std::string Arcade::File::GetFilename()
{
    return (this->_filename);
}

std::string Arcade::File::GetFilenameNoExtension()
{
    size_t lastdot = _filename.find_last_of(".");
    if (lastdot == std::string::npos)
        return _filename;
    if (lastdot == 0)
        return (Constants::STRING_NULL);
    return _filename.substr(0, lastdot);
}

std::string Arcade::File::GetExtension()
{
    if (this->_filename.find_last_of(".") != std::string::npos) {
        std::string _test = _filename.substr(_filename.find_last_of(".") + 1);
        if (_test == "")
            return (Constants::STRING_NULL);
        return (_test);
    }
    return (Constants::STRING_NULL);
}