#ifndef CALLBACK_MENU_ITEM_H
#define CALLBACK_MENU_ITEM_H

#include <functional>
#include <WString.h>
#include "screen.h"
#include "screen_manager.h"
#include "generic_menu_item/generic_menu_item.h"

typedef std::function<void()> MenuCallbackFunction;

class CallbackMenuItem : public GenericMenuItem
{
private:
    MenuCallbackFunction callback;

public:
    CallbackMenuItem(String name, MenuCallbackFunction callback);
    void action();
};

#endif