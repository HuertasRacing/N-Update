#include "NetworkService.hpp"

bool NetworkService::Initialize()
{
    m_Initialized = true;
    return true;
}

void NetworkService::Shutdown()
{
    m_Initialized = false;
}

bool NetworkService::IsInitialized() const
{
    return m_Initialized;
}