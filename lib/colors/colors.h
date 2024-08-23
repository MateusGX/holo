#ifndef COLORS_H
#define COLORS_H

#include "M5StickCPlus2.h"

enum class Colors
{
    BLACK,
    NAVY,
    DARKGREEN,
    DARKCYAN,
    MAROON,
    PURPLE,
    OLIVE,
    LIGHTGREY,
    DARKGREY,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    YELLOW,
    WHITE,
    ORANGE,
    GREENYELLOW,
    PINK,
    BROWN,
    GOLD,
    SILVER,
    SKYBLUE,
    VIOLET
};

int colorToHex(Colors color);

#endif