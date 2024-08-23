#include <Arduino.h>

#include "M5StickCPlus2.h"
#include <config.h>
#include <menu.h>
#include <screen_menu_item/screen_menu_item.h>
#include <callback_menu_item/callback_menu_item.h>
#include <screen_manager.h>
#include "screens/boot_screen/boot_screen.h"
#include "screens.h"

Config config;
ScreenManager screenManager(&config);

#pragma region Screens

BootScreen bootScreen;

#pragma endregion

#pragma region Menus

Menu menuHome("Holo");
Menu menuApplications("Apps");

#pragma endregion

void setup()
{
    auto cfg = M5.config();
    StickCP2.begin(cfg);
    screenManager.addScreen(&bootScreen, Screens::BOOT);
    screenManager.addScreen(&menuHome, Screens::MENU_HOME);
    screenManager.addScreen(&menuApplications, Screens::MENU_APPLICATIONS);

    menuHome.addItem(new ScreenMenuItem("Applications", Screens::MENU_APPLICATIONS));
    menuHome.addItem(new CallbackMenuItem("About", []()
                                          { Serial.println("About"); }));
    menuHome.addItem(new CallbackMenuItem("Settings", []()
                                          { Serial.println("Settings"); }));
    menuHome.addItem(new CallbackMenuItem("Exit", []()
                                          { Serial.println("Exit"); }));
    menuHome.initialize();

    menuApplications.addItem(new CallbackMenuItem("Calculator", []()
                                                  { Serial.println("Calculator"); }));
    menuApplications.addItem(new CallbackMenuItem("Calendar", []()
                                                  { Serial.println("Calendar"); }));
    menuApplications.initialize();
    screenManager.begin(Screens::BOOT);
}

void loop()
{
    StickCP2.update();
    screenManager.loop();
}