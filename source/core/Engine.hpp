#pragma once

#include "UpdateManager.hpp"
#include "SystemService.hpp"

class Engine
{
public:
    bool Initialize();

    void Run();

    void Shutdown();

    const SystemService& GetSystemService() const;

private:
    UpdateManager m_UpdateManager;
    SystemService m_SystemService;
};