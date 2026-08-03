#pragma once

class NetworkService
{
public:
    NetworkService();

    bool Initialize();

    void Shutdown();

    bool IsInitialized() const;

private:
    bool m_Initialized;
};