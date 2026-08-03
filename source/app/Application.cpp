#include "Application.hpp"

#include <switch.h>
#include <cstdio>

#include "../core/Engine.hpp"

int Application::Run()
{
    consoleInit(nullptr);

    Engine engine;

    if (!engine.Initialize())
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

    printf("Pulsa + para salir.\n");

    while (appletMainLoop())
    {
        padUpdate(&pad);

        u64 keys = padGetButtonsDown(&pad);

        if (keys & HidNpadButton_Plus)
            break;

        engine.Run();

        consoleUpdate(nullptr);
    }

    engine.Shutdown();

    consoleExit(nullptr);

    return 0;
}