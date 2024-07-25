#include <Arduino.h>

#include "M5StickCPlus2.h"
#include "menu/menu.h"

Menu mainMenu("Holo", true);

void setup()
{
    auto cfg = M5.config();
    StickCP2.begin(cfg);
    mainMenu.addItem({"Applications", []()
                      { Serial.println("applications"); }});
    mainMenu.addItem({"About", []()
                      { Serial.println("About"); }});
    mainMenu.addItem({"Settings", []()
                      { Serial.println("Settings"); }});
    mainMenu.addItem({"Exit", []()
                      { Serial.println("Exit"); }});
    mainMenu.init();
}

void loop()
{
    StickCP2.update();
    mainMenu.loop();
}