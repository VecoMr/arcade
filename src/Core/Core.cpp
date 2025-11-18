/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Core
*/

#include "Core.hpp"
#include <sys/stat.h>

namespace arcade {
    class IGames;

    Core::Core(const std::string &path)
    : _graphic(DLObject(path).getInst<IGraphics>("createLib")), _game(), _graphicName(DLObject(path).getCall<std::string>("getName")), _menu(nullptr), _controls(), _state(State::MENU), _windowParameters(std::make_shared<windowParameters_t>(DEF_WIDTH, DEF_HEIGHT, std::string("Arcade"), 0, 60, 20)), _events()
    {
        loadControls();
        loadLibPath();
        getScoreboard();

        if (DLObject(path).getCall<LibType>("getType") != LibType::GRAPHIC) {
            throw ErrorH("The library is not a graphic library");
        }

        loadPrimitiveGame();

        _graphic->initWindow(_windowParameters);
        _graphic->loadFonts(getGame()->getFontPaths());
        _graphic->loadTextures(getGame()->getTextures());
    }

    Core::~Core()
    {
        setScoreboard();
    }

    void Core::run()
    {
        using namespace std::chrono;

        const milliseconds frameTime(1000 / _windowParameters->fps);
        const milliseconds tickTime(1000 / _windowParameters->tps);

        steady_clock::time_point startTimeFrame = steady_clock::now();
        steady_clock::time_point startTimeTick = steady_clock::now();

        while (_state != State::EXIT) {
            steady_clock::time_point currentTime = steady_clock::now();
            milliseconds elapsedTime = duration_cast<milliseconds>(currentTime - startTimeTick);

            if (elapsedTime > tickTime) {
                execGame();
                startTimeTick = steady_clock::now();
            }

            elapsedTime = duration_cast<milliseconds>(currentTime - startTimeFrame);

            if (elapsedTime > frameTime) {
                _graphic->displayObjects(getObjects());
                startTimeFrame = steady_clock::now();
            }
        }
    }

    VPtrObject &Core::getObjects()
    {
        return getGame()->getObjects();
    }

    std::unique_ptr<IGames> &Core::getGame()
    {
        if (_state == State::MENU)
            return _menu;
        if (_state == State::SETTINGS)
            return _settings;
        return _game.getInst();
    }

    void Core::execGame()
    {
        VGameEvent &events = getEvents();
        if (_state == State::EXIT)
            return;
        _state = getGame()->execute(events);
        if (_state == State::LOSE || _state == State::WIN)
            _addScoreToScoreboard();
        else
            _scoreIsUploaded = false;
    }

    void Core::getScoreboard()
    {
        const std::string path = "./.score";

        std::ifstream file(path);
        if (!file) {
            std::cerr << "Unable to open file " << path << "\n";
            return;
        }
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string game;
            std::getline(iss, game, ':');
            std::string str;
            while (std::getline(iss, str, ' ')) {
                if (str.empty()) continue;
                std::istringstream stream(str);
                std::string name;
                std::getline(stream, name, ',');
                int score;
                stream >> score;
                game.erase(std::remove(game.begin(), game.end(), ' '), game.end());
                name.erase(std::remove(name.begin(), name.end(), ' '), name.end());
                _scoreboard[game].emplace(name, score);
            }
        }
    }

    void Core::setScoreboard()
    {
        const std::string path = "./.score";

        std::ofstream file(path);
        if (!file) {
            std::cerr << "Unable to open file " << path << "\n";
            return;
        }
        for (auto game: _scoreboard) {
            file << game.first << " :";
            for (auto score: game.second) {
                file << " " << score.first << "," << score.second;
            }
            file << "\n";
        }
    }

    void Core::_addScoreToScoreboard() {
        int score = getGame()->getScore();

        if (!score || _scoreIsUploaded)
            return;

        _scoreboard.find(_gameName)->second.emplace(_playerName, score);
        _scoreIsUploaded = true;
    }
}