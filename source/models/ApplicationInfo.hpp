#pragma once

#include <string>

class ApplicationInfo
{
public:
    ApplicationInfo();

public:
    std::string Name;
    std::string Author;
    std::string Version;
    std::string Description;
    std::string DownloadUrl;
    std::string IconUrl;

    uint64_t Size;
};