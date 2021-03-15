/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Folder
*/

#include "Folder.hpp"

Arcade::Folder::Folder()
{
}

Arcade::Folder::Folder(const std::string &folder)
{
    this->SetFolderPath(folder);
}

void Arcade::Folder::SetFolderPath(const std::string &folder)
{
    this->_name_folder = folder;
}

void Arcade::Folder::OpenFolder()
{
    DIR *directory = opendir(this->_name_folder.c_str());
    struct dirent *dir;
    std::unique_ptr<Arcade::File> file;
    while ((dir = readdir(directory)) != NULL) {
        file = std::make_unique<Arcade::File>(dir->d_name);
        if (file->GetExtension() != Constants::STRING_NULL &&
            file->GetFilenameNoExtension() != Constants::STRING_NULL) {
            if (file->GetFilenameNoExtension().substr(
                    0, Constants::NB_CHAR_EXT_LIB) ==
                Constants::LIB_FIRST_EXT) {
                this->_files.push_back(*file);
            }
        }
        file.reset();
    }
    closedir(directory);
}

void Arcade::Folder::ListFolder()
{
    for (std::vector<Arcade::File>::iterator it = this->_files.begin();
         it != this->_files.end(); ++it) {
        std::cout << it->GetFilenameNoExtension() << std::endl;
    }
}

std::vector<Arcade::File> Arcade::Folder::GetFolder()
{
    return (this->_files);
}

std::vector<std::string> Arcade::Folder::GetVectorFolder()
{
    std::vector<std::string> vector;

    for (std::vector<Arcade::File>::iterator it = this->_files.begin();
         it != this->_files.end(); ++it) {
        vector.push_back(it->GetFilenameNoExtension());
    }
    return (vector);
}

Arcade::Folder::~Folder()
{
}
