#include "screen.h"

void Screen::init(Config *config)
{
    this->config = config;
}

void Screen::run()
{
    draw();
}

void Screen::draw()
{
    // Do nothing
}

void Screen::clear()
{
    screenManager->clearScreen();
}

void Screen::loop()
{
    // Do nothing
}

ScreenManager *Screen::getScreenManager()
{
    return screenManager;
}