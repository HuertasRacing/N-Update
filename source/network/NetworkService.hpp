#pragma once

class NetworkService
{
public:
    bool Initialize();

    void Shutdown();

    bool IsInitialized() const;

private:
    bool m_Initialized = false;
};