//
// Created by tristan on 25/01/19.
//

#include "HTTP.h"


HTTP::HTTP(char *baseURI) : baseURI(baseURI) {}

HTTP::~HTTP() { curl_easy_cleanup(curlHandler); }

HTTPResponse HTTP::get(std::string path) {

    std::string url = buildURL(path);
    setUrl(url);

    CURLcode code = curl_easy_perform(curlHandler);

    if (code != CURLE_OK) {
        fprintf(stderr, "Failed to get '%s' [%s]\n", "path", errorBuffer);
        exit(EXIT_FAILURE);
    }
    return HTTPResponse(code, buffer.c_str());
}

std::string HTTP::buildURL(std::string &path) {
    char url[baseURI.length() + path.length() + baseKEY.length() + 3];
    sprintf(url, "%s%s?k=%s", baseURI.c_str(), path.c_str(), baseKEY.c_str());
    return url;
}

void HTTP::setUrl(std::string url) {
    CURLcode code;
    code = curl_easy_setopt(curlHandler, CURLOPT_URL, url.c_str());
    if (code != CURLE_OK) {
        fprintf(stderr, "Failed to set url [%s]\n", errorBuffer);
        exit(EXIT_FAILURE);
    }
}

size_t HTTP::writer(char *inputContent, size_t sizeFactor, size_t contentSize, std::string *outputContent) {
    if (outputContent == nullptr) return 0;
    outputContent->append(inputContent, sizeFactor * contentSize);
    return sizeFactor * contentSize;
}

bool HTTP::init() {
    CURLcode code;
    curlHandler = curl_easy_init();

    if (curlHandler == nullptr) {
        fprintf(stderr, "Failed to create CURL connection\n");
        exit(EXIT_FAILURE);
    }

    code = curl_easy_setopt(curlHandler, CURLOPT_ERRORBUFFER, errorBuffer);
    if (code != CURLE_OK) {
        fprintf(stderr, "Failed to set error buffer [%d]\n", code);
        return false;
    }

    code = curl_easy_setopt(curlHandler, CURLOPT_WRITEFUNCTION, writer);
    if (code != CURLE_OK) {
        fprintf(stderr, "Failed to set writer [%s]\n", errorBuffer);
        return false;
    }

    code = curl_easy_setopt(curlHandler, CURLOPT_WRITEDATA, &buffer);
    if (code != CURLE_OK) {
        fprintf(stderr, "Failed to set output data [%s]\n", errorBuffer);
        return false;
    }

    return true;
}

