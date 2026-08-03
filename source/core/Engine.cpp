#include "Engine.hpp"

bool Engine::Initialize()
{
    if (!m_SystemService.Initialize())
        return false;

    if (!m_UpdateManager.Initialize())
        return false;

    return true;
}

void Engine::Run()
{
}

void Engine::Shutdown()
{
    m_UpdateManager.Shutdown();
}

const SystemService& Engine::GetSystemService() const
{
    return m_SystemService;
}