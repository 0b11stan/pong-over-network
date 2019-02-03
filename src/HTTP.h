//
// Created by tristan on 25/01/19.
//

#ifndef BROCKENBRICK_REMOTE_H
#define BROCKENBRICK_REMOTE_H

#include <curl/curl.h>
#include <map>
#include <string>
#include "HTTPResponse.h"

class HTTP {

public:

    static const std::string baseURI;
    static const std::string baseKEY;

//    static CURL *create();

    static void destroy(CURL *connection);

    static void get(std::string path, HTTPResponse &response, std::map<std::string, std::string> parameters = {});

private:

    static std::string buildURL(std::string &path, std::map<std::string, std::string> &parameters);

    static size_t writer(char *inputContent, size_t sizeFactor, size_t contentSize, std::string *outputContent);

};


#endif //BROCKENBRICK_REMOTE_H
