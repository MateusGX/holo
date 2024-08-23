#include "screen_manager.h"

void ScreenManager::applyConfig()
{
    StickCP2.Display.setRotation(config->getRotation() == MenuRotation::LEFT ? 1 : 3);
    StickCP2.Display.setTextColor(colorToHex(config->getTextColor()));
    StickCP2.Display.fillScreen(colorToHex(config->getBackgroundColor()));
    StickCP2.Display.setFont(&fonts::Orbitron_Light_24);
}

ScreenManager::ScreenManager(Config *config)
{
    this->state = ScreenManagerState::UNINITIALIZED;
    this->config = config;
}

void ScreenManager::addScreen(Screen *screen, Screens screenName)
{
    screen->screenManager = this;
    screens[screenName] = screen;
}

void ScreenManager::changeScreenWithoutSetPrevious(Screens screenName)
{
    if (!screenExists(screenName))
        return;
    applyConfig();
    currentScreen = screens[screenName];
    currentScreen->init(config);
    currentScreen->run();
}

void ScreenManager::changeScreen(Screens screenName)
{
    if (!screenExists(screenName))
        return;
    applyConfig();
    previousScreen = currentScreen;
    currentScreen = screens[screenName];
    currentScreen->init(config);
    currentScreen->run();
}

void ScreenManager::loop()
{
    if (currentScreen == nullptr || this->state == ScreenManagerState::UNINITIALIZED)
        return;

    currentScreen->loop();
}

void ScreenManager::begin(Screens screenName)
{
    if (this->state == ScreenManagerState::INITIALIZED)
        return;

    applyConfig();
    if (!screenExists(screenName))
        return;
    currentScreen = screens[screenName];
    currentScreen->init(config);
    currentScreen->run();
    this->state = ScreenManagerState::INITIALIZED;
}

bool ScreenManager::goBack()
{
    if (previousScreen == nullptr)
    {
        return false;
    }
    applyConfig();
    currentScreen = previousScreen;
    previousScreen = nullptr;
    currentScreen->init(config);
    currentScreen->run();
    return true;
}

void ScreenManager::clearScreen()
{
    StickCP2.Display.fillScreen(colorToHex(config->getBackgroundColor()));
}

bool ScreenManager::screenExists(Screens screenName)
{
    return screens.find(screenName) != screens.end();
}