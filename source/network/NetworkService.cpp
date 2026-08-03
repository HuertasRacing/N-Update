#include "NetworkService.hpp"
#include "HttpClient.hpp"

NetworkService::NetworkService()
    : m_Initialized(false)
{
}

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

bool NetworkService::TestConnection(std::string& response) const
{
    HttpClient client;

    return client.Get(
        "https://httpbin.org/get",
        response);
}