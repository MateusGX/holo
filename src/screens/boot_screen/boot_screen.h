#ifndef BOOT_SCREEN_H
#define BOOT_SCREEN_H

#include <screen.h>
#include <colors.h>

class BootScreen : public Screen
{
public:
    void draw();
    void run();
};

#endif