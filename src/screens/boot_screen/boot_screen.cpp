#include "boot_screen.h"
#include "screens.h"

void BootScreen::draw()
{
    StickCP2.Display.setFont(&fonts::Orbitron_Light_32);
    StickCP2.Display.drawString("HOLO", 20, 35);
    StickCP2.Display.setFont(&fonts::Orbitron_Light_24);
    StickCP2.Display.drawString("STARTING...", 20, 70);
    delay(1500);
    getScreenManager()->applyConfig();
}

void BootScreen::run()
{
    draw();
    getScreenManager()->changeScreenWithoutSetPrevious(Screens::MENU_HOME);
}