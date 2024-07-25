#include "colors/colors.h"

#ifndef MENU_H
#define MENU_H

typedef std::function<void()> MenuCallback;

enum class MenuRotation
{
    LEFT,
    RIGHT
};

enum class MenuState
{
    INITIALIZED,
    UNINITIALIZED
};

struct MenuItem
{
    String name;
    MenuCallback callback;
};

class Menu
{
private:
    Colors textColor;
    Colors foregroundColor;
    Colors backgroundColor;
    int padding;
    MenuState state;
    void startup();
    bool isPrincipal;
    void clear();
    std::vector<MenuItem> items;
    void draw();
    int selectedItem;
    int brightness;
    String title;
    MenuRotation rotation;
    bool soundEnabled;

public:
    Menu(String title, bool isPrincipal = false);
    void init();
    void loop();
    void addItem(MenuItem item);
    void addSubMenu(Menu *menu);
};

#endif