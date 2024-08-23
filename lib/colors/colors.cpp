#include "colors.h"

int colorToHex(Colors color)
{
    switch (color)
    {
    case Colors::NAVY:
        return NAVY;
    case Colors::DARKGREEN:
        return DARKGREEN;
    case Colors::DARKCYAN:
        return DARKCYAN;
    case Colors::MAROON:
        return MAROON;
    case Colors::PURPLE:
        return PURPLE;
    case Colors::OLIVE:
        return OLIVE;
    case Colors::LIGHTGREY:
        return LIGHTGREY;
    case Colors::DARKGREY:
        return DARKGREY;
    case Colors::BLUE:
        return BLUE;
    case Colors::GREEN:
        return GREEN;
    case Colors::CYAN:
        return CYAN;
    case Colors::RED:
        return RED;
    case Colors::MAGENTA:
        return MAGENTA;
    case Colors::YELLOW:
        return YELLOW;
    case Colors::WHITE:
        return WHITE;
    case Colors::ORANGE:
        return ORANGE;
    case Colors::GREENYELLOW:
        return GREENYELLOW;
    case Colors::PINK:
        return PINK;
    case Colors::BROWN:
        return BROWN;
    case Colors::GOLD:
        return GOLD;
    case Colors::SILVER:
        return SILVER;
    case Colors::SKYBLUE:
        return SKYBLUE;
    case Colors::VIOLET:
        return VIOLET;
    case Colors::BLACK:
    default:
        return BLACK;
    }
}