/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Folder
*/

#ifndef FOLDER_HPP_
#define FOLDER_HPP_
#include <iostream>
#include <vector>
#include <memory>
#include <dirent.h>
#include "File.hpp"

namespace Arcade {
    class Folder {
    public:
        Folder();
        Folder(const std::string &);
        void SetFolderPath(const std::string &);
        void OpenFolder();
        void ListFolder();
        std::vector<Arcade::File> GetFolder();
        std::vector<std::string> GetVectorFolder();
        ~Folder();

    protected:
    private:
        std::string _name_folder;
        std::vector<Arcade::File> _files;
    };
} // namespace Arcade

#endif /* !FOLDER_HPP_ */
