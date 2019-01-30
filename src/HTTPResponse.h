//
// Created by tristan on 30/01/19.
//

#ifndef PONG_OVER_NETWORK_HTTPRESPONSE_H
#define PONG_OVER_NETWORK_HTTPRESPONSE_H


#include <string>
#include <curl/curl.h>

class HTTPResponse {

public:
    HTTPResponse(const CURLcode code, const char *body) : responseCode(code), responseBody(body) {}
    const CURLcode getCode() { return responseCode; }
    const std::string getBody() { return responseBody; }

private:
    CURLcode responseCode;
    std::string responseBody;
};


#endif //PONG_OVER_NETWORK_HTTPRESPONSE_H
