#include "config.h"

Config::Config()
{
    this->textColor = Colors::GREEN;
    this->foregroundColor = Colors::GREEN;
    this->backgroundColor = Colors::BLACK;
    this->rotation = MenuRotation::RIGHT;
    this->padding = 10;
    this->brightness = 100;
    this->soundEnabled = true;
}

Colors Config::getTextColor()
{
    return this->textColor;
}

Colors Config::getForegroundColor()
{
    return this->foregroundColor;
}

Colors Config::getBackgroundColor()
{
    return this->backgroundColor;
}

MenuRotation Config::getRotation()
{
    return this->rotation;
}

int Config::getPadding()
{
    return this->padding;
}

int Config::getBrightness()
{
    return this->brightness;
}

bool Config::getSoundEnabled()
{
    return this->soundEnabled;
}