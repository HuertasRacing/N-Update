#include "Engine.hpp"
#include "UpdateManager.hpp"

UpdateManager g_UpdateManager;

bool Engine::Initialize()
{
    return g_UpdateManager.Initialize();
}

void Engine::Run()
{
    // Aquí irá la lógica principal más adelante.
}

void Engine::Shutdown()
{
    g_UpdateManager.Shutdown();
}