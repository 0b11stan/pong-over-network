//
// Created by tristan on 30/01/19.
//

#ifndef PONG_OVER_NETWORK_HTTPRESPONSE_H
#define PONG_OVER_NETWORK_HTTPRESPONSE_H


#include <string>
#include <curl/curl.h>
#include <map>

enum JSON {
    START_KEY, END_KEY, START_VALUE, END_VALUE
};

class HTTPResponse {

public:
    const std::map<std::string, std::string> to_map();

    std::string body;
    CURLcode code;

};


#endif //PONG_OVER_NETWORK_HTTPRESPONSE_H
