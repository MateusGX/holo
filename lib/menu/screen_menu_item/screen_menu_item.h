#ifndef SCREEN_MENU_ITEM_H
#define SCREEN_MENU_ITEM_H

#include <WString.h>
#include "screen.h"
#include "screen_manager.h"
#include "generic_menu_item/generic_menu_item.h"

class ScreenMenuItem : public GenericMenuItem
{
private:
    Screens screenName;

public:
    ScreenMenuItem(String name, Screens screenName);
    void action();
};

#endif