#pragma once

#include <string>

class SystemService
{
public:
    bool Initialize();

    bool IsSdCardAvailable() const;

    std::string GetFirmwareVersion() const;
};