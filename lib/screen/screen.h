#ifndef SCREEN_H
#define SCREEN_H

#include "config.h"
#include "screen_manager.h"

class ScreenManager;

class Screen
{
private:
    Config *config;
    ScreenManager *screenManager;

public:
    virtual void run();
    virtual void draw();
    virtual void clear();
    virtual void loop();
    virtual void init(Config *config);
    ScreenManager *getScreenManager();

    friend class Menu;
    friend class ScreenManager;
};

#endif