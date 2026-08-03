#include "Application.hpp"

#include <cstdio>
#include <string>
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

    std::string response;

    bool httpOk =
        engine.GetNetworkService().TestConnection(response);

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

    printf("HTTP     : %s\n\n",
           httpOk ? "OK" : "ERROR");

    if (httpOk)
    {
        printf("%.300s\n", response.c_str());
    }

    printf("\nPulsa + para salir.\n");

    while (appletMainLoop())
    {
        padUpdate(&pad);

        if (padGetButtonsDown(&pad) & HidNpadButton_Plus)
            break;

        consoleUpdate(nullptr);
    }

    engine.Shutdown();

    consoleExit(nullptr);

    return 0;
}