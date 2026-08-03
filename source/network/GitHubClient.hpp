#pragma once

#include <string>

#include "../models/GitHubRelease.hpp"

class GitHubClient
{
public:
    bool GetLatestReleaseJson(
        const std::string& owner,
        const std::string& repository,
        std::string& json) const;

    bool ParseRelease(
        const std::string& json,
        GitHubRelease& release) const;
};