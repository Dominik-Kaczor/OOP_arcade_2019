/*
** EPITECH PROJECT, 2020
** Arcade_2019
** File description:
** tests_01
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <memory>
#include <iostream>
#include "Core/Arguments.hpp"
#include "Core/Core.hpp"

static void redirect()
{
    cr_redirect_stderr();
    cr_redirect_stdout();
}

Test(test_arguments_no_arguments, arguments, .init = redirect)
{
    int ac = 1;
    bool is_true = false;
    const char *av[2] = {"./arcade", NULL};
    std::unique_ptr<Arcade::Arguments> Args(new Arcade::Arguments(
        const_cast<const int &>(ac), const_cast<const char **>(av)));
    Args->SetRequired(Constants::MINIMAL_ARGUMENTS);
    try {
        Args->CheckIfRequired();
    } catch (const Arcade::ArgumentsError &error) {
        Args->PrintErrorOutput(Constants::USAGE);
        is_true = true;
    }
    cr_assert_stderr_eq_str((Constants::USAGE + "\n").c_str());
    cr_assert(is_true == true);
}

Test(test_arguments_arguments_help, arguments, .init = redirect)
{
    int ac = 2;
    bool is_true = false;
    bool is_true_2 = false;
    const char *av[3] = {"./arcade", "--help", NULL};
    std::unique_ptr<Arcade::Arguments> Args(new Arcade::Arguments(
        const_cast<const int &>(ac), const_cast<const char **>(av)));
    Args->SetRequired(Constants::MINIMAL_ARGUMENTS);
    try {
        Args->CheckIfRequired();
    } catch (const Arcade::ArgumentsError &error) {
        Args->PrintErrorOutput(Constants::USAGE);
        is_true = true;
    }
    if (Args->CheckAndPrint(1, Constants::FLAG_HELP, Constants::USAGE) == true)
        is_true_2 = true;
    cr_assert_stdout_eq_str((Constants::USAGE + "\n").c_str());
    cr_assert(is_true == false);
    cr_assert(is_true_2 == true);
}

Test(test_arguments_arguments_little_help, arguments, .init = redirect)
{
    int ac = 2;
    bool is_true = false;
    bool is_true_2 = false;
    const char *av[3] = {"./arcade", "-h", NULL};
    std::unique_ptr<Arcade::Arguments> Args(new Arcade::Arguments(
        const_cast<const int &>(ac), const_cast<const char **>(av)));
    Args->SetRequired(Constants::MINIMAL_ARGUMENTS);
    try {
        Args->CheckIfRequired();
    } catch (const Arcade::ArgumentsError &error) {
        Args->PrintErrorOutput(Constants::USAGE);
        is_true = true;
    }
    if (Args->CheckAndPrint(1, Constants::FLAG_HELP_LITTLE, Constants::USAGE) ==
        true)
        is_true_2 = true;
    cr_assert_stdout_eq_str((Constants::USAGE + "\n").c_str());
    cr_assert(is_true == false);
    cr_assert(is_true_2 == true);
}

Test(test_arguments_arguments_exception, arguments, .init = redirect)
{
    int ac = 1;
    bool is_true = false;
    const char *av[2] = {"./arcade", NULL};
    std::unique_ptr<Arcade::Arguments> Args(new Arcade::Arguments(
        const_cast<const int &>(ac), const_cast<const char **>(av)));
    Args->SetRequired(Constants::MINIMAL_ARGUMENTS);
    try {
        Args->CheckIfRequired();
    } catch (const Arcade::ArgumentsError &error) {
        cr_assert_str_eq(error.what(), "Not enough arguments");
        Args->PrintErrorOutput(Constants::USAGE);
        is_true = true;
    }
    cr_assert_stderr_eq_str((Constants::USAGE + "\n").c_str());
    cr_assert(is_true == true);
}

Test(test_arguments_arguments_no_print, arguments, .init = redirect)
{
    int ac = 1;
    bool is_true = false;
    const char *av[2] = {"./arcade", NULL};
    std::unique_ptr<Arcade::Arguments> Args(new Arcade::Arguments(
        const_cast<const int &>(ac), const_cast<const char **>(av)));
    Args->SetRequired(Constants::MINIMAL_ARGUMENTS);
    try {
        Args->CheckIfRequired();
    } catch (const Arcade::ArgumentsError &error) {
        cr_assert_str_eq(error.what(), "Not enough arguments");
        Args->PrintErrorOutput(Constants::USAGE);
        is_true = true;
    }
    cr_assert(Args->CheckAndPrint(1, Constants::FLAG_HELP_LITTLE, Constants::USAGE) == false);
}

Test(Error_librarie_load, DLLload)
{
    Arcade::DLLoader *test = new Arcade::DLLoader();
    try {
        test->Open("tktBG");
    } catch (const Arcade::DLLoaderError &msg) {
        cr_assert_str_eq(msg.what(), "tktBG: cannot open shared object file: No such file or directory");
        delete test;
    }
}

Test(Get_elapsedMilliSeconds, Clock)
{
    Arcade::Clock *test = new Arcade::Clock();
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    std::chrono::milliseconds ms = test->GetElapsedTimeMilliSeconds();
    cr_assert_eq(300, ms.count());
    delete test;
}

Test(Restart, Clock)
{
    Arcade::Clock *test = new Arcade::Clock();
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    test->Restart();
    std::chrono::milliseconds ms = test->GetElapsedTimeMilliSeconds();
    cr_assert_eq(0, ms.count());
    delete test;
}

Test(Get_elapsedTimeSeconds, Clock)
{
    Arcade::Clock *test = new Arcade::Clock();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::chrono::seconds ms = test->GetElapsedTimeSeconds();
    cr_assert_eq(1, ms.count());
    delete test;
}

Test(Get_elapsedMicroSeconds, Clock)
{
    Arcade::Clock *test = new Arcade::Clock();
    std::this_thread::sleep_for(std::chrono::microseconds(300));
    std::chrono::microseconds ms = test->GetElapsedTimeMicroSeconds();
    cr_assert_neq(0, ms.count());
    delete test;
}

Test(GetFilename, File)
{
    Arcade::File *test = new Arcade::File("Test.so");
    cr_assert_str_eq("Test.so", test->GetFilename().c_str());
}
