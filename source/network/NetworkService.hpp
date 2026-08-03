#pragma once

#include <string>

class NetworkService
{
public:
    NetworkService();

    bool Initialize();

    void Shutdown();

    bool IsInitialized() const;

    bool GetLatestRelease(
        const std::string& owner,
        const std::string& repository,
        std::string& response) const;

private:
    bool m_Initialized;
};