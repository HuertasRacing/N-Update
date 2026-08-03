#include "NetworkService.hpp"
#include "GitHubClient.hpp"

#include <switch.h>

NetworkService::NetworkService()
    : m_Initialized(false)
{
}

bool NetworkService::Initialize()
{
    Result rc = socketInitializeDefault();

    if (R_FAILED(rc))
        return false;

    m_Initialized = true;
    return true;
}

void NetworkService::Shutdown()
{
    if (m_Initialized)
    {
        socketExit();
        m_Initialized = false;
    }
}

bool NetworkService::IsInitialized() const
{
    return m_Initialized;
}

bool NetworkService::GetLatestRelease(
    const std::string& owner,
    const std::string& repository,
    std::string& response) const
{
    if (!m_Initialized)
        return false;

    GitHubClient github;

    return github.GetLatestReleaseJson(
        owner,
        repository,
        response);
}