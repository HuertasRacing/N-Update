#pragma once

#include <string>
#include <vector>

#include "GitHubAsset.hpp"

struct GitHubRelease
{
    std::string tagName;
    std::string name;
    std::string body;
    std::string publishedAt;

    std::vector<GitHubAsset> assets;
};