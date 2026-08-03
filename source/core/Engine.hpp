#pragma once

#include "UpdateManager.hpp"
#include "SystemService.hpp"
#include "../network/NetworkService.hpp"

class Engine
{
public:
    bool Initialize();

    void Run();

    void Shutdown();

    const SystemService& GetSystemService() const;
    const NetworkService& GetNetworkService() const;

private:
    UpdateManager m_UpdateManager;
    SystemService m_SystemService;
    NetworkService m_NetworkService;
};