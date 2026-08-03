#include "SystemService.hpp"

#include <switch.h>

bool SystemService::Initialize()
{
    return true;
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
    SetSysFirmwareVersion fw{};

    if (R_SUCCEEDED(setsysGetFirmwareVersion(&fw)))
    {
        return std::string(fw.display_version);
    }

    return "Unknown";
}