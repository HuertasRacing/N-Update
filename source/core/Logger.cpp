#include "Logger.hpp"

#include <cstdio>

void Logger::Info(const std::string& message)
{
    printf("[INFO] %s\n", message.c_str());
}

void Logger::Warning(const std::string& message)
{
    printf("[WARNING] %s\n", message.c_str());
}

void Logger::Error(const std::string& message)
{
    printf("[ERROR] %s\n", message.c_str());
}