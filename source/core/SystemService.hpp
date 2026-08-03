#pragma once

#include <string>

class SystemService
{
public:
    SystemService();

    bool Initialize();
    void Shutdown();

    bool IsSdCardAvailable() const;
    std::string GetFirmwareVersion() const;

private:
    bool m_Initialized;
};