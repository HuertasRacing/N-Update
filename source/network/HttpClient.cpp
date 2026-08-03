#include "HttpClient.hpp"

#include <curl/curl.h>

HttpClient::HttpClient()
{
    curl_global_init(CURL_GLOBAL_DEFAULT);
}

size_t HttpClient::WriteCallback(void* contents,
                                 size_t size,
                                 size_t nmemb,
                                 void* userp)
{
    ((std::string*)userp)->append(
        (char*)contents,
        size * nmemb);

    return size * nmemb;
}

bool HttpClient::Get(const std::string& url,
                     std::string& response)
{
    CURL* curl = curl_easy_init();

    if (!curl)
        return false;

    response.clear();

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "N-Update/0.1");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    CURLcode result = curl_easy_perform(curl);

    curl_easy_cleanup(curl);

    return result == CURLE_OK;
}