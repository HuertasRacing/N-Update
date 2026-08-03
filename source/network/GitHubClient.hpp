#pragma once

#include <string>

#include "../models/GitHubRelease.hpp"

class GitHubClient
{
public:
    bool GetLatestRelease(
        const std::string& owner,
        const std::string& repository,
        std::string& response) const;

    bool ParseRelease(
        const std::string& json,
        GitHubRelease& release) const;
};