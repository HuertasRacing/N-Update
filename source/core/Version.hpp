#pragma once

#include <string>

class Version
{
public:
    static std::string GetName();

    static std::string GetVersion();

    static std::string GetAuthor();

    static std::string GetWebsite();
};