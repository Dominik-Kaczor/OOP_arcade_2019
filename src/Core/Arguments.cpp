/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Arguments
*/

#include "Arguments.hpp"
#include "Constants.hpp"

Arcade::ArgumentsError::ArgumentsError(const std::string &message)
{
    this->_message = message;
}

const char *Arcade::ArgumentsError::what() const noexcept
{
    return (this->_message.data());
}

Arcade::Arguments::Arguments(const int ac, const char **av)
{
    this->_ac = ac;

    for (int i = 0; i != ac; i++) {
        this->_av.push_back(std::string(av[i]));
    }
}

std::string Arcade::Arguments::GetAt(const size_t pos)
{
    std::string str;

    try {
        str = this->_av.at(pos);
    } catch (std::out_of_range &e) {
        return (Constants::STRING_NULL);
    }
    return (this->_av.at(pos));
}

void Arcade::Arguments::SetRequired(const int required)
{
    this->_minimum_required = required;
}

void Arcade::Arguments::CheckIfRequired()
{
    if (this->_ac != this->_minimum_required) {
        throw ArgumentsError(Constants::ERROR_ARGS);
    }
}

void Arcade::Arguments::PrintStandardOutput(const std::string &print)
{
    std::cout << print << std::endl;
}

void Arcade::Arguments::PrintErrorOutput(const std::string &print)
{
    std::cerr << print << std::endl;
}

bool Arcade::Arguments::CheckAndPrint(const size_t pos,
                                      const std::string &to_compare,
                                      const std::string &to_print)
{
    if (this->GetAt(pos) == to_compare) {
        this->PrintStandardOutput(to_print);
        return (true);
    } else {
        return (false);
    }
}

Arcade::Arguments::~Arguments()
{
}
