//
// Created by tristan on 25/01/19.
//

#include "HTTP.h"

//const std::string HTTP::baseURI = "http://rtplay.local";
//const std::string HTTP::baseKEY = "123";
const std::string HTTP::baseURI = "http://syllab.com/PTRE839";
const std::string HTTP::baseKEY = "255058";


void HTTP::get(std::string path, HTTPResponse &response, std::map<std::string, std::string> parameters) {
    std::string url = buildURL(path, parameters);
    CURL *curlHandler = curl_easy_init();

    curl_easy_setopt(curlHandler, CURLOPT_WRITEFUNCTION, writer);
    curl_easy_setopt(curlHandler, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curlHandler, CURLOPT_WRITEDATA, &response.body);

    response.code = curl_easy_perform(curlHandler);

    curl_easy_cleanup(curlHandler);
}

std::string HTTP::buildURL(std::string &path, std::map<std::string, std::string> &parameters) {
    std::string url = baseURI + path + "?k=" + baseKEY;
    for (auto const &param : parameters) url.append("&" + param.first + "=" + param.second);
    return url;
}

size_t HTTP::writer(char *inputContent, size_t sizeFactor, size_t contentSize, std::string *outputContent) {
    if (outputContent == nullptr) return 0;
    outputContent->append(inputContent, sizeFactor * contentSize);
    return sizeFactor * contentSize;
}


