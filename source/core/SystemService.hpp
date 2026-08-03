#pragma once

class SystemService
{
public:
    bool Initialize();

    bool IsSdCardAvailable() const;
};