#include "Application.hpp"

#include <switch.h>
#include <cstdio>

int Application::Run()
{
    // Inicializar la consola
    consoleInit(nullptr);

    // Configurar entrada del mando
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

    consoleExit(nullptr);

    return 0;
}