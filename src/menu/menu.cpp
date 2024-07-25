#include "M5StickCPlus2.h"
#include "menu.h"

void Menu::init()
{
    Serial.println("Menu init");
    StickCP2.Display.setRotation(rotation == MenuRotation::LEFT ? 1 : 3);
    StickCP2.Display.setTextColor(colorToHex(textColor));
    StickCP2.Display.fillScreen(colorToHex(backgroundColor));
    StickCP2.Display.setFont(&fonts::Orbitron_Light_24);
    if (isPrincipal)
        startup();
    draw();
    state = MenuState::INITIALIZED;
}

void Menu::startup()
{
    Serial.println("Menu startup");
    Serial.println(StickCP2.Display.width());
    Serial.println(StickCP2.Display.height());
    StickCP2.Display.setFont(&fonts::Orbitron_Light_32);
    StickCP2.Display.setTextColor(colorToHex(textColor));
    StickCP2.Display.drawString("HOLO", 20, 35);
    StickCP2.Display.setFont(&fonts::Orbitron_Light_24);
    StickCP2.Display.drawString("STARTING...", 20, 70);
    delay(1500);
    clear();
    StickCP2.Display.setBrightness(brightness);
}

void Menu::clear()
{
    StickCP2.Display.clear(colorToHex(backgroundColor));
}

Menu::Menu(String title, bool isPrincipal)
    : isPrincipal(isPrincipal), title(title)
{
    backgroundColor = Colors::BLACK;
    textColor = Colors::GREEN;
    foregroundColor = Colors::GREEN;
    padding = 10;
    selectedItem = 0;
    brightness = 100;
    soundEnabled = true;
    rotation = MenuRotation::RIGHT;
    state = MenuState::UNINITIALIZED;
    Serial.println("Menu created");
}

void Menu::addItem(MenuItem item)
{
    items.push_back(item);
}

void Menu::draw()
{
    clear();
    StickCP2.Display.setTextColor(colorToHex(textColor));
    int itemsRenderCount = 0;
    int skipCount = 0;

    StickCP2.Display.setFont(&fonts::Orbitron_Light_32);
    StickCP2.Display.setTextColor(colorToHex(textColor));
    StickCP2.Display.drawString("HOLO", padding, padding / 2);
    StickCP2.Display.setFont(&fonts::Orbitron_Light_24);
    StickCP2.Display.drawLine(padding + 1, 42, StickCP2.Display.width() - padding, 42, colorToHex(foregroundColor));

    for (int i = 0; i < items.size(); i++)
    {
        if (skipCount < selectedItem - 2)
        {
            skipCount++;
            continue;
        }

        if (i == selectedItem)
            StickCP2.Display.drawString(">", padding, 38 + padding + itemsRenderCount * 25);
        StickCP2.Display.drawString(items[i].name, padding + 20, 38 + padding + itemsRenderCount * 25);

        itemsRenderCount++;
        if (itemsRenderCount >= 3)
            break;
    }
}

void Menu::loop()
{
    if (state == MenuState::UNINITIALIZED)
    {
        return;
    }

    if (StickCP2.BtnB.wasPressed())
    {
        if (soundEnabled)
            StickCP2.Speaker.tone(6000, 100);
        if (selectedItem == items.size() - 1)
        {
            selectedItem = 0;
        }
        else
        {
            selectedItem++;
        }
        Serial.println(selectedItem);
        draw();
    }

    if (StickCP2.BtnA.wasPressed())
    {
        if (soundEnabled)
            StickCP2.Speaker.tone(7000, 100);
    }
}

// void initMenu() {
//     StickCP2.Display.setRotation(1);
//     StickCP2.Display.setTextColor(GREEN);
//     StickCP2.Display.setTextDatum(middle_center);
//     StickCP2.Display.setFont(&fonts::Orbitron_Light_24);
// }