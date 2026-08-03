#pragma once

#include <string>

class HttpClient
{
public:
    HttpClient();

    bool Get(const std::string& url, std::string& response);

private:
    static size_t WriteCallback(void* contents,
                                size_t size,
                                size_t nmemb,
                                void* userp);
};