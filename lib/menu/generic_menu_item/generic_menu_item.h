#ifndef GENERIC_MENU_ITEM_H
#define GENERIC_MENU_ITEM_H

#include <WString.h>
#include "screen_manager.h"

enum class MenuItemType
{
    CALLBACK,
    SCREEN
};

class ScreenMenuItem;
class CallbackMenuItem;

class GenericMenuItem
{
private:
    String name;
    MenuItemType type;
    ScreenManager *screenManager;

public:
    GenericMenuItem(String name, MenuItemType type);
    void setScreenManager(ScreenManager *screenManager);
    String getName();
    MenuItemType getType();
    virtual void action();

    friend class ScreenMenuItem;
    friend class CallbackMenuItem;
};

#endif