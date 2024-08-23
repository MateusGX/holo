#ifndef MENU_H
#define MENU_H

#include "screen.h"
#include "generic_menu_item/generic_menu_item.h"
#include <vector>
#include <WString.h>

enum class MenuState
{
    INITIALIZED,
    UNINITIALIZED
};

class Menu : public Screen
{
private:
    MenuState state;
    std::vector<GenericMenuItem *> items;
    String title;
    int selectedItem;

public:
    Menu(String title);
    void draw();
    void loop();
    void addItem(GenericMenuItem *item);
    void initialize();
    void uninitialize();
};

#endif