#include "Application.hpp"

#include <switch.h>
#include <cstdio>

#include "../core/UpdateManager.hpp"

int Application::Run()
{
    consoleInit(nullptr);

    UpdateManager manager;

    if (!manager.Initialize())
    {
        consoleExit(nullptr);
        return -1;
    }

    padConfigureInput(1, HidNpadStyleSet_NpadStandard);

    PadState pad;
    padInitializeDefault(&pad);

    printf("=================================\n");
    printf("          N-Update\n");
    printf("=================================\n\n");

    printf("Bienvenido a N-Update\n\n");
    printf("Pulsa + para salir.\n");

    while (appletMainLoop())
    {
        padUpdate(&pad);

        u64 keys = padGetButtonsDown(&pad);

        if (keys & HidNpadButton_Plus)
            break;

        consoleUpdate(nullptr);
    }

    manager.Shutdown();

    consoleExit(nullptr);

    return 0;
}