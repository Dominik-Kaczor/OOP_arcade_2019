/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** Core
*/

#include "Core.hpp"
#include "Component/Error.hpp"

Core::Core(const std::string &library)
{
    this->_next = NO_ACTIONS;
    this->_graphical_library = nullptr;
    this->_game_library = nullptr;
    this->_username = Constants::STRING_NULL;
    this->_score = 0;
    this->_score_implementation = std::make_unique<Arcade::Score>();
    this->_mouse = std::make_unique<Arcade::Mouse>();
    this->_timer = std::make_unique<Arcade::Timer>();
    this->_selected = 0;
    this->GetAllGames();
    this->GetAllGraphicalLibs();
    this->LoadGraphical(library);
    this->LoadGame(Constants::PREFIX_GAMES + this->GetFirstGame() +
                   Constants::LIB_EXT);
    this->GetLibraryNameFromFolder(library);
}

void Core::AskForUsername()
{
    std::string username;

    std::cout << Constants::ASK_FOR_USERNAME << std::endl;
    std::cin >> username;
    this->_username = username;
    this->_score_implementation->SetUsername(username);
}

const std::string &Core::GetFirstGame()
{
    if (this->_games->GetFolder().size() == 0) {
        Arcade::Error::Print(Constants::NO_GAMES);
        Arcade::Error::Exit();
    }
    this->_gam = this->_games->GetFolder().at(0).GetFilenameNoExtension();
    return (this->_gam);
}

void Core::GetLibraryNameFromFolder(const std::string &library)
{
    for (size_t i = 0; i != this->_graphical_libs->GetFolder().size(); i++) {
        if (library.find(this->_graphical_libs->GetFolder().at(i).GetFilename(),
                         0) != std::string::npos) {
            this->_graph = this->_graphical_libs->GetFolder()
                               .at(i)
                               .GetFilenameNoExtension();
            return;
        }
    }
    Arcade::Error::Print(Constants::LIB_NOT_IN_LIBS);
    Arcade::Error::Exit();
}

void Core::LoadGraphical(const std::string &library)
{
    try {
        this->_graphical_handle = std::make_unique<Arcade::DLLoader>(library);
        this->LoadGraphicalLibrary();
    } catch (Arcade::DLLoaderError &message) {
        Arcade::Error::Print(message.what());
        Arcade::Error::Exit();
    }
}

void Core::LoadGame(const std::string &game)
{
    try {
        this->_game_handle = std::make_unique<Arcade::DLLoader>(game);
        this->LoadGameLibrary();
    } catch (Arcade::DLLoaderError &message) {
        Arcade::Error::Print(message.what());
        Arcade::Error::Exit();
    }
}

void Core::EventHandling()
{
    KeyEnum key = this->_graphical_library->KeyPressed();

    switch (key) {
    case (KeyEnum::SYS_BACK_TO_MENU):
    case (KeyEnum::SYS_EXIT):
        this->_score_implementation->SetScore(this->_game_library->getScore());
        this->Start();
        break;
    default:
        this->_game_library->getKey(key);
        break;
    }
}

void Core::EventHandlingMenu()
{
    KeyEnum key = this->_graphical_library->KeyPressed();

    std::vector<int> mouse = this->_graphical_library->GetMousePosition();
    this->_mouse->SetMouse(mouse[0], mouse[1]);
    if (this->_graphical_library->is_mouse_clicked()) {
        if (this->_mouse->CompareMouses() == true)
            return;
        this->_mouse->SetOldMouse();
        this->_next = this->_mouse->GetActionByButton();
    }
    switch (key) {
    case (KeyEnum::SYS_EXIT):
        this->_score_implementation->SaveScoreInFile();
        this->_graphical_library->CloseWindow();
        std::exit(Constants::TEK_EXIT_SUCCESS);
    case (KeyEnum::SYS_NEXT_GRAPHICAL_LIBRARY):
        this->_next = NEXT_GRAPHICAL_LIB;
        break;
    case (KeyEnum::SYS_PREVIOUS_GRAPHICAL_LIBRARY):
        this->_next = PREVIOUS_GRAPHICAL_LIB;
        break;
    case (KeyEnum::SYS_NEXT_GAME):
        this->_next = NEXT_GAME_LIB;
        break;
    case (KeyEnum::SYS_PREVIOUS_GAME):
        this->_next = PREVIOUS_GAME_LIB;
        break;
    case (KeyEnum::DOWN):
        if (this->_selected != MAX_OPTIONS_MENU - 1)
            this->_selected += OPTIONS_SELECT::NEXT;
        else
            this->_selected = OPTIONS_SELECT::FIRST;
        break;
    case (KeyEnum::UP):
        if (this->_selected != OPTIONS_SELECT::FIRST)
            this->_selected -= OPTIONS_SELECT::PREVIOUS;
        else
            this->_selected = MAX_OPTIONS_MENU - 1;
        break;
    case (KeyEnum::ENTER):
        if (this->_selected == OPTIONS_SELECT::LAST)
            this->_selected = OPTIONS_SELECT::OUT_OF_BOUNDS;
        break;
    default:
        break;
    }
}

void Core::Update()
{
    WinCondition condition;

    this->_graphical_library->ClearWindow();
    if (this->_clock->GetElapsedTimeMilliSeconds() >
        static_cast<std::chrono::milliseconds>(Constants::BASE_CLOCK)) {
        condition = this->_game_library->loop();
        if (condition == WinCondition::WIN) {
            this->_score_implementation->SetScore(
                this->_game_library->getScore());
            this->LoadGameLibrary();
            this->Start();
        }
        if (condition == WinCondition::LOSE) {
            this->_score_implementation->SetScore(
                this->_game_library->getScore());
            LoadGameLibrary();
            this->Start();
        }
        this->_clock->Restart();
    }
}

void Core::Render()
{
    std::vector<std::vector<int>> map = this->_game_library->getMap();
    for (size_t i = 0; i < map.size(); i++) {
        for (size_t j = 0; j < map[i].size(); j++) {
            this->_graphical_library->PrintBlock(
                static_cast<float>(i), static_cast<float>(j),
                static_cast<Texture>(map[i][j]));
        }
    }
    this->_graphical_library->PrintText(
        0, float(map.size()) + 10, 0,
        Constants::SCORE + std::to_string(this->_game_library->getScore()));
    this->_graphical_library->DisplayWindow();
}

void Core::Start()
{
    this->_selected = 0;
    this->_next = NO_ACTIONS;
    this->_clock = std::make_unique<Arcade::Clock>();
    this->_graphical_library->InitWindow();
    this->_graphical_library->ClearWindow();
    std::string plus;

    while (true) {
        this->_timer->HandleFPS();
        this->_graphical_library->ClearWindow();
        for (int i = 0; i != MAX_OPTIONS_MENU; i++) {
            if (i == 0)
                plus = this->_username;
            if (i == 1)
                plus = this->_graph;
            if (i == 2)
                plus = this->_gam + "   ";
            this->_graphical_library->PrintText(
                i * 10, 0, (this->_selected == i) ? RED : WHITE,
                options[i] + " " + plus);
            plus = "";
        }
        this->_graphical_library->PrintText(10, 40, 0, "NEXT");
        this->_graphical_library->PrintText(20, 40, 0, "NEXT");
        if (this->_selected == 5)
            break;
        if (this->_next != NO_ACTIONS)
            break;
        this->_graphical_library->PrintText(
            0, 40, 0,
            Constants::SCORE +
                std::to_string(this->_score_implementation->GetScore()));
        this->_graphical_library->DisplayWindow();
        this->EventHandlingMenu();
    }
    switch (this->_next) {
    case NEXT_GRAPHICAL_LIB:
    case PREVIOUS_GRAPHICAL_LIB:
        this->LoadGraphicalLibraryNext(this->_next);
        return;
    case NEXT_GAME_LIB:
    case PREVIOUS_GAME_LIB:
        this->LoadGameNext(this->_next);
        return;
    default:
        this->loop();
        return;
    }
}

void Core::loop()
{
    while (true) {
        this->_timer->HandleFPS();
        this->Update();
        this->EventHandling();
        this->Render();
    }
}

void Core::LoadGameNext(Actions mode)
{
    this->_selected = 0;
    this->_next = NO_ACTIONS;
    this->_game_handle.reset();
    std::vector<std::string> libraries = this->_games->GetVectorFolder();
    auto it = std::find(libraries.begin(), libraries.end(), this->_gam);
    if (mode == NEXT_GAME_LIB)
        this->_gam =
            *(it = (it + 1 == libraries.end()) ? libraries.begin() : it + 1);
    else if (mode == PREVIOUS_GAME_LIB)
        this->_gam =
            *(it = (it == libraries.begin()) ? libraries.end() - 1 : it - 1);
    this->_game_handle = std::make_unique<Arcade::DLLoader>(
        Constants::PREFIX_GAMES + this->_gam + Constants::LIB_EXT);
    this->LoadGameLibrary();
    this->Start();
}

void Core::LoadGraphicalLibraryNext(Actions mode)
{
    this->_selected = 0;
    this->_next = NO_ACTIONS;
    this->_graphical_library->CloseWindow();
    this->_graphical_handle.reset();
    std::vector<std::string> libraries =
        this->_graphical_libs->GetVectorFolder();
    auto it = std::find(libraries.begin(), libraries.end(), this->_graph);
    if (mode == NEXT_GRAPHICAL_LIB)
        this->_graph =
            *(it = (it + 1 == libraries.end()) ? libraries.begin() : it + 1);
    else if (mode == PREVIOUS_GRAPHICAL_LIB)
        this->_graph =
            *(it = (it == libraries.begin()) ? libraries.end() - 1 : it - 1);
    this->_graphical_handle = std::make_unique<Arcade::DLLoader>(
        Constants::PREFIX_LIBS + this->_graph + Constants::LIB_EXT);
    this->LoadGraphicalLibrary();
    this->Start();
}

void Core::GetAllGames()
{
    this->_games = std::make_unique<Arcade::Folder>(Constants::PREFIX_GAMES);
    this->_games->OpenFolder();
}

void Core::GetAllGraphicalLibs()
{
    this->_graphical_libs =
        std::make_unique<Arcade::Folder>(Constants::PREFIX_LIBS);
    this->_graphical_libs->OpenFolder();
}

void Core::LoadGraphicalLibrary()
{
    void *handle = NULL;
    constructor_graphical *constructor = nullptr;

    try {
        handle = this->_graphical_handle->GetConstructor();
    } catch (Arcade::DLLoaderError &message) {
        throw(Arcade::DLLoaderError(message));
    }
    constructor = (constructor_graphical *)handle;
    this->_graphical_library = constructor();
}

void Core::LoadGameLibrary()
{
    void *handle = NULL;
    constructor_game *constructor = nullptr;

    try {
        handle = this->_game_handle->GetConstructor();
    } catch (Arcade::DLLoaderError &message) {
        throw(Arcade::DLLoaderError(message));
    }
    constructor = (constructor_game *)handle;
    this->_game_library = constructor();
    this->_game_library->initialization();
}

Core::~Core()
{
}
