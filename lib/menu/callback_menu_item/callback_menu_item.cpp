#include "callback_menu_item.h"

CallbackMenuItem::CallbackMenuItem(String name, MenuCallbackFunction callback) : GenericMenuItem(name, MenuItemType::CALLBACK)
{
    this->callback = callback;
}

void CallbackMenuItem::action()
{
    callback();
}