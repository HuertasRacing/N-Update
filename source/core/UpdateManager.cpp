#include "UpdateManager.hpp"
#include "Version.hpp"

#include <cstdio>

bool UpdateManager::Initialize()
{
    printf("=================================\n");
    printf("%s %s\n",
           Version::GetName().c_str(),
           Version::GetVersion().c_str());

    printf("Autor: %s\n",
           Version::GetAuthor().c_str());

    printf("=================================\n\n");

    return true;
}

void UpdateManager::Shutdown()
{
    printf("Cerrando N-Update...\n");
}