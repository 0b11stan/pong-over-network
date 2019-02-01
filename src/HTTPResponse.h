//
// Created by tristan on 30/01/19.
//

#ifndef PONG_OVER_NETWORK_HTTPRESPONSE_H
#define PONG_OVER_NETWORK_HTTPRESPONSE_H


#include <string>
#include <curl/curl.h>
#include <map>

enum JSON { START_KEY, END_KEY, START_VALUE, END_VALUE };

class HTTPResponse {

public:
    HTTPResponse(const CURLcode code, const char *body) : responseCode(code), responseBody(body) {}

    const CURLcode getCode() { return responseCode; }

    const std::string getBody() { return responseBody; }

    const std::map<std::string, std::string> to_map();

private:
    CURLcode responseCode;
    std::string responseBody;
};


#endif //PONG_OVER_NETWORK_HTTPRESPONSE_H
