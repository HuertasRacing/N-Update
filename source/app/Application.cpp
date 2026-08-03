#include "Application.hpp"

#include <cstdio>
#include <switch.h>

#include "../core/Engine.hpp"
#include "../core/Version.hpp"

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
    printf("%s %s\n",
        Version::GetName().c_str(),
        Version::GetVersion().c_str());
    printf("=================================\n\n");

    printf("SD Card  : %s\n",
        engine.GetSystemService().IsSdCardAvailable() ? "OK" : "ERROR");

    printf("Firmware : %s\n",
        engine.GetSystemService().GetFirmwareVersion().c_str());

    printf("\nPulsa + para salir.\n");

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