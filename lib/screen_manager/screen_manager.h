#ifndef SCREEN_MANAGER_H
#define SCREEN_MANAGER_H

#include <map>
#include "config.h"
#include "screen.h"

enum class Screens;
class Screen;

enum class ScreenManagerState
{
    INITIALIZED,
    UNINITIALIZED
};

class ScreenManager
{
private:
    ScreenManagerState state;
    std::map<Screens, Screen *> screens;
    Screen *currentScreen;
    Screen *previousScreen;
    Config *config;

public:
    ScreenManager(Config *config);
    void addScreen(Screen *screen, Screens screenName);
    void changeScreen(Screens screenName);
    void changeScreenWithoutSetPrevious(Screens screenName);
    void loop();
    void begin(Screens screenName);
    void applyConfig();
    bool goBack();
    void clearScreen();
    bool screenExists(Screens screenName);
};

#endif