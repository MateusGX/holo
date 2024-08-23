#include "screen_menu_item.h"

ScreenMenuItem::ScreenMenuItem(String name, Screens screenName) : GenericMenuItem(name, MenuItemType::SCREEN)
{
    this->screenName = screenName;
}

void ScreenMenuItem::action()
{
    if (this->screenManager == nullptr)
        return;
    this->screenManager->changeScreen(screenName);
}