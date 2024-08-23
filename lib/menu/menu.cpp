#include "menu.h"
#include "M5StickCPlus2.h"
#include "hardware_control.h"

Menu::Menu(String title) : title(title)
{
    selectedItem = 0;
    state = MenuState::UNINITIALIZED;
}

void Menu::draw()
{
    if (state == MenuState::UNINITIALIZED)
        return;

    StickCP2.Display.setFont(&fonts::Orbitron_Light_32);
    StickCP2.Display.drawString(title, config->getPadding(), config->getPadding() / 2);
    StickCP2.Display.setFont(&fonts::Orbitron_Light_24);
    StickCP2.Display.drawLine(config->getPadding() + 1, 46, StickCP2.Display.width() - config->getPadding(), 46, colorToHex(config->getForegroundColor()));

    int itemsRenderCount = 0;
    int skipCount = 0;

    for (int i = 0; i < items.size(); i++)
    {
        if (skipCount < selectedItem - 2)
        {
            skipCount++;
            continue;
        }
        if (i == selectedItem)
            StickCP2.Display.drawString(">", config->getPadding(), 38 + config->getPadding() + itemsRenderCount * 25);
        StickCP2.Display.drawString(items[i]->getName(), config->getPadding() + 20, 38 + config->getPadding() + itemsRenderCount * 25);

        itemsRenderCount++;
        if (itemsRenderCount >= 3)
            break;
    }
}

void Menu::loop()
{
    if (state == MenuState::UNINITIALIZED)
        return;
    if (PrimaryButton.wasPressed())
    {
        if (config->getSoundEnabled())
            StickCP2.Speaker.tone(7000, 100);
        switch (items[selectedItem]->getType())
        {
        case MenuItemType::CALLBACK:
            items[selectedItem]->action();
            break;

        case MenuItemType::SCREEN:
            items[selectedItem]->action();
            break;

        default:
            Serial.println("Unknown MenuItemType");
            break;
        }
    }

    if (SecondaryButton.wasPressed())
    {
        if (config->getSoundEnabled())
            StickCP2.Speaker.tone(6000, 100);
        if (items.size() == 0)
            return;
        if (selectedItem == items.size() - 1)
            selectedItem = 0;
        else
            selectedItem++;
        clear();
        draw();
    }

    if (PowerButton.wasPressed())
    {
        if (config->getSoundEnabled())
            StickCP2.Speaker.tone(6000, 100);
        selectedItem = 0;
        screenManager->goBack();
    }
}

void Menu::addItem(GenericMenuItem *item)
{
    if (state == MenuState::INITIALIZED)
        return;
    if (this->screenManager == nullptr)
        return;
    item->setScreenManager(screenManager);
    items.push_back(item);
}

void Menu::initialize()
{
    if (state == MenuState::INITIALIZED)
        return;
    state = MenuState::INITIALIZED;
}

void Menu::uninitialize()
{
    if (state == MenuState::UNINITIALIZED)
        return;
    state = MenuState::UNINITIALIZED;
}