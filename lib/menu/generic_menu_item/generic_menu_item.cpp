#include "generic_menu_item.h"
#include "M5StickCPlus2.h"

GenericMenuItem::GenericMenuItem(String name, MenuItemType type) : name(name), type(type)
{
}

String GenericMenuItem::getName()
{
    return name;
}

MenuItemType GenericMenuItem::getType()
{
    return type;
}

void GenericMenuItem::action()
{
    Serial.println("Calling MenuItem::action()");
}

void GenericMenuItem::setScreenManager(ScreenManager *screenManager)
{
    this->screenManager = screenManager;
}