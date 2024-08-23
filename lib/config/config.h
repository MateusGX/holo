#ifndef CONFIG_H
#define CONFIG_H
#include "colors.h"

enum class MenuRotation
{
    LEFT,
    RIGHT
};

class Config
{
private:
    Colors textColor;
    Colors foregroundColor;
    Colors backgroundColor;
    int padding;
    MenuRotation rotation;
    bool soundEnabled;
    int brightness;

public:
    Config();
    Colors getTextColor();
    Colors getForegroundColor();
    Colors getBackgroundColor();
    MenuRotation getRotation();
    int getPadding();
    int getBrightness();
    bool getSoundEnabled();
};

#endif