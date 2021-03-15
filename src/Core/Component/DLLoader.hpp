/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** DLLoader
*/

#ifndef DLLOADER_HPP_
#define DLLOADER_HPP_
#include <iostream>

namespace Arcade {
    class DLLoaderError : public std::exception {
    public:
        DLLoaderError(const std::string &);
        const char *what() const noexcept override;

    private:
        std::string _message;
    };
    class DLLoader {
    public:
        DLLoader();
        DLLoader(const std::string &);
        void Open(const std::string &);
        void Close();
        void *GetHandle();
        void *GetConstructor();
        ~DLLoader();

    protected:
    private:
        void OpenLibrary();
        void CloseLibrary();
        // Variables
        std::string _lib_name;
        void *_handle;
    };
} // namespace Arcade

#endif /* !DLLOADER_HPP_ */
