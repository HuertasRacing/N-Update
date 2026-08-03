#pragma once

#include <cstdint>
#include <string>

struct GitHubAsset
{
    std::string name;
    std::string downloadUrl;
    std::uint64_t size = 0;
};