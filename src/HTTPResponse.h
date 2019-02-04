//
// Created by tristan on 30/01/19.
//

#ifndef PONG_OVER_NETWORK_HTTPRESPONSE_H
#define PONG_OVER_NETWORK_HTTPRESPONSE_H

#include <string>
#include <curl/curl.h>
#include <map>

using namespace std;

enum JSON {
    START_KEY, END_KEY, START_VALUE, END_VALUE
};

class HTTPResponse {

public:
    const map<string, string> to_map() const;

    string body;
    CURLcode code;

};


#endif //PONG_OVER_NETWORK_HTTPRESPONSE_H
