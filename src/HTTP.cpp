//
// Created by tristan on 25/01/19.
//

#include "HTTP.h"

const string HTTP::baseURI = "http://rtplay.local";
//const string HTTP::baseURI = "http://syllab.com/PTRE839";

void HTTP::post(string path, map<string, string> parameters) {
    string url = buildURL(path, parameters);
    CURL *curlHandler = curl_easy_init();

    curl_easy_setopt(curlHandler, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curlHandler, CURLOPT_POST, 1);
    curl_easy_setopt(curlHandler, CURLOPT_POSTFIELDS, "");

    curl_easy_perform(curlHandler);

    curl_easy_cleanup(curlHandler);
}

void HTTP::get(string path, HTTPResponse &response, map<string, string> parameters) {
    string url = buildURL(path, parameters);
    CURL *curlHandler = curl_easy_init();

    curl_easy_setopt(curlHandler, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curlHandler, CURLOPT_WRITEFUNCTION, writer);
    curl_easy_setopt(curlHandler, CURLOPT_WRITEDATA, &response.body);

    response.code = curl_easy_perform(curlHandler);

    curl_easy_cleanup(curlHandler);
}

void HTTP::delete_(string path, map<string, string> parameters) {
    string url = buildURL(path, parameters);
    CURL *curlHandler = curl_easy_init();

    curl_easy_setopt(curlHandler, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curlHandler, CURLOPT_CUSTOMREQUEST, "DELETE");

    curl_easy_perform(curlHandler);

    curl_easy_cleanup(curlHandler);
}

string HTTP::buildURL(string &path, map<string, string> &parameters) {
    string url = baseURI + path + "?";
    for (auto const &param : parameters) url.append("&" + param.first + "=" + param.second);
    return url;
}

size_t HTTP::writer(char *inputContent, size_t sizeFactor, size_t contentSize, string *outputContent) {
    if (outputContent == nullptr) return 0;
    outputContent->append(inputContent, sizeFactor * contentSize);
    return sizeFactor * contentSize;
}



