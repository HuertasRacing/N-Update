#include "SystemService.hpp"

#include <switch.h>

SystemService::SystemService()
    : m_Initialized(false)
{
}

bool SystemService::Initialize()
{
    Result rc = setsysInitialize();

    if (R_FAILED(rc))
        return false;

    m_Initialized = true;

    return true;
}

void SystemService::Shutdown()
{
    if (m_Initialized)
    {
        setsysExit();
        m_Initialized = false;
    }
}

bool SystemService::IsSdCardAvailable() const
{
    FsFileSystem fs;

    Result rc = fsOpenSdCardFileSystem(&fs);

    if (R_SUCCEEDED(rc))
    {
        fsFsClose(&fs);
        return true;
    }

    return false;
}

std::string SystemService::GetFirmwareVersion() const
{
    if (!m_Initialized)
        return "SystemService not initialized";

    SetSysFirmwareVersion fw{};

    Result rc = setsysGetFirmwareVersion(&fw);

    if (R_FAILED(rc))
    {
        char buffer[32];
        snprintf(buffer, sizeof(buffer), "0x%08X", rc);
        return buffer;
    }

    return std::string(fw.display_version);
}