//
// Created by tristan on 25/01/19.
//

#ifndef BROCKENBRICK_REMOTE_H
#define BROCKENBRICK_REMOTE_H

#include <curl/curl.h>
#include <map>
#include <string>
#include "HTTPResponse.h"

using namespace std;

class HTTP {

public:

    static const string baseURI;
    static const string baseKEY;

    static void get(string path, HTTPResponse &response, map<string, string> parameters = {});

private:

    static string buildURL(string &path, map<string, string> &parameters);

    static size_t writer(char *inputContent, size_t sizeFactor, size_t contentSize, string *outputContent);

};


#endif //BROCKENBRICK_REMOTE_H
