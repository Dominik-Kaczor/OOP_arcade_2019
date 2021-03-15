/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <algorithm>
#include "Constants.hpp"
#include "Component/File.hpp"
#include "Interface/IConstructor.hpp"
#include "Interface/Actions.hpp"
#include "Interface/Colors.hpp"
#include "Interface/Options.hpp"
#include "Component/DLLoader.hpp"
#include "Component/Folder.hpp"
#include "Component/Clock.hpp"
#include "Component/Timer.hpp"
#include "Component/Score.hpp"
#include "Component/Mouse.hpp"


static std::vector<int> MOUSE{0, 0};

class Core {
public:
    Core(const std::string &);
    void LoadGraphicalLibrary();
    void LoadGameLibrary();
    void LoadGame(const std::string &);
    void LoadGraphical(const std::string &);
    const std::string &GetFirstGame();
    void GetLibraryNameFromFolder(const std::string &);
    void GetAllGames();
    void GetAllGraphicalLibs();
    void Start();
    void LoadGameNext(Actions);
    void LoadGraphicalLibraryNext(Actions);
    void AskForUsername();
    void EventHandling();
    void EventHandlingMenu();
    void Update();
    void Render();
    void loop();
    ~Core();

protected:
private:
    IGraphicals *_graphical_library;
    IGames *_game_library;
    std::unique_ptr<Arcade::DLLoader> _game_handle;
    std::unique_ptr<Arcade::DLLoader> _graphical_handle;
    std::unique_ptr<Arcade::Folder> _games;
    std::unique_ptr<Arcade::Folder> _graphical_libs;
    std::unique_ptr<Arcade::Clock> _clock;
    std::unique_ptr<Arcade::Score> _score_implementation;
    std::unique_ptr<Arcade::Timer> _timer;
    std::unique_ptr<Arcade::Mouse> _mouse;
    std::string _username;
    std::string _graph;
    std::string _gam;
    int _selected;
    int _score;
    Actions _next;
};

#endif /* !CORE_HPP_ */
