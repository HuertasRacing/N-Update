#include "GitHubClient.hpp"

#include "HttpClient.hpp"

#include <nlohmann/json.hpp>

using json = nlohmann::json;

bool GitHubClient::GetLatestReleaseJson(
    const std::string& owner,
    const std::string& repository,
    std::string& response) const
{
    HttpClient http;

    const std::string url =
        "https://api.github.com/repos/" +
        owner +
        "/" +
        repository +
        "/releases/latest";

    return http.Get(url, response);
}

bool GitHubClient::ParseRelease(
    const std::string& text,
    GitHubRelease& release) const
{
    json j = json::parse(text, nullptr, false);

    if (j.is_discarded())
        return false;

    release.tagName = j.value("tag_name", "");
    release.name = j.value("name", "");
    release.body = j.value("body", "");
    release.publishedAt = j.value("published_at", "");

    release.assets.clear();

    if (j.contains("assets"))
    {
        for (const auto& asset : j["assets"])
        {
            GitHubAsset a;

            a.name = asset.value("name", "");
            a.downloadUrl = asset.value("browser_download_url", "");
            a.size = asset.value("size", 0ULL);

            release.assets.push_back(a);
        }
    }

    return true;
}