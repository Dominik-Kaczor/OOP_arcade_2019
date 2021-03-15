/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** File
*/

#ifndef FILE_HPP_
#define FILE_HPP_
#include <iostream>
#include "Constants.hpp"

namespace Arcade {
    class File {
    public:
        File(std::string &);
        File(const char *);
        ~File();
        void SetFilename(std::string &);
        std::string GetFilename();
        std::string GetFilenameNoExtension();
        std::string GetExtension();

    protected:
    private:
        std::string _filename;
    };
} // namespace Arcade

#endif /* !FILE_HPP_ */
