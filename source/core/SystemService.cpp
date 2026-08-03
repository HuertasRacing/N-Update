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