/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** DLLoader
*/

#include <dlfcn.h>
#include "DLLoader.hpp"
#include "Constants.hpp"

Arcade::DLLoaderError::DLLoaderError(const std::string &message)
{
    this->_message = message;
}

const char *Arcade::DLLoaderError::what() const noexcept
{
    return (this->_message.data());
}

Arcade::DLLoader::DLLoader()
{
    this->_handle = NULL;
    this->_lib_name = Constants::STRING_NULL;
}

void Arcade::DLLoader::Open(const std::string &library)
{
    this->_lib_name = library;
    try {
        this->OpenLibrary();
    } catch (DLLoaderError &message) {
        throw(DLLoaderError(message));
    }
}

void Arcade::DLLoader::Close()
{
    try {
        this->CloseLibrary();
    } catch (DLLoaderError &message) {
        throw(DLLoaderError(message));
    }
}

Arcade::DLLoader::DLLoader(const std::string &library)
{
    this->_handle = NULL;
    this->_lib_name = Constants::STRING_NULL;
    try {
        this->Open(library);
    } catch (DLLoaderError &message) {
        throw(DLLoaderError(message));
    }
}

void Arcade::DLLoader::OpenLibrary()
{
    this->_handle = dlopen(this->_lib_name.c_str(), RTLD_NOW);
    if (this->_handle == NULL) {
        throw(DLLoaderError(std::string(dlerror())));
    }
}

void Arcade::DLLoader::CloseLibrary()
{
    if (this->_handle != NULL) {
        if (dlclose(this->_handle) != Constants::TEK_EXIT_SUCCESS) {
            throw(DLLoaderError(std::string(dlerror())));
        }
    }
}

void *Arcade::DLLoader::GetConstructor()
{
    void *handle = NULL;

    handle = dlsym(this->_handle, Constants::CONSTRUCTOR.c_str());
    if (handle == NULL) {
        throw(DLLoaderError(std::string(dlerror())));
    }
    return (handle);
}

void *Arcade::DLLoader::GetHandle()
{
    return (this->_handle);
}

Arcade::DLLoader::~DLLoader()
{
    this->CloseLibrary();
}
