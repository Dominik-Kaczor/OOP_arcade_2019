/*
** EPITECH PROJECT, 2020
** Arcade_2019
** File description:
** Arcade
*/

#include <iostream>
#include <memory>
#include "Constants.hpp"
#include "Core/Core.hpp"
#include "Core/Arguments.hpp"

int arcade(int ac, char **av)
{
    std::unique_ptr<Arcade::Arguments> Args(new Arcade::Arguments(
        const_cast<const int &>(ac), const_cast<const char **>(av)));
    std::unique_ptr<Core> my_core;
    Args->SetRequired(Constants::MINIMAL_ARGUMENTS);
    try {
        Args->CheckIfRequired();
    } catch (const Arcade::ArgumentsError &error) {
        Args->PrintErrorOutput(Constants::USAGE);
        return (Constants::TEK_EXIT_FAILRUE);
    }
    if (Args->CheckAndPrint(1, Constants::FLAG_HELP, Constants::USAGE) == true)
        return (Constants::TEK_EXIT_SUCCESS);
    if (Args->CheckAndPrint(1, Constants::FLAG_HELP_LITTLE, Constants::USAGE) ==
        true)
        return (Constants::TEK_EXIT_SUCCESS);
    my_core = std::make_unique<Core>(Args->GetAt(1));
    try {
        my_core->AskForUsername();
        my_core->Start();
        return (Constants::TEK_EXIT_SUCCESS);
    } catch (...) {
        return (Constants::TEK_EXIT_FAILRUE);
    }
}