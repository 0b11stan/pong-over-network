//
// Created by tristan on 25/01/19.
//

#include <curl/curl.h>
#include "Remote.h"


char *Remote::request(HttpMethod method, std::string path) {
    char *output = nullptr;
    if (curlHandler) {
        char url[baseURI.length() + path.length() + baseKEY.length() + 3];
        sprintf(url, "%s%s?k=%s", baseURI.c_str(), path.c_str(), baseKEY.c_str());

        curl_easy_setopt(curlHandler, CURLOPT_URL, url);
//        curl_easy_setopt(curlHandler, CURLOPT_WRITEDATA, output);
//        curl_easy_setopt(curlHandler, CURLOPT_WRITEFUNCTION, callbackWriter);

        CURLcode result = curl_easy_perform(curlHandler);
        curl_easy_cleanup(curlHandler);
        if (result != CURLE_OK) {
            printf("Error : Performing request failed : %s\n", curl_easy_strerror(result));
        }
    } else {
        printf("Error : Could not init curl.");
    }
    return output;
}

void Remote::requestPing() {
    char* test = request(HttpMethod::GET, "/help");
    printf("test : %s", test);
}

size_t Remote::callbackWriter(char *content, size_t size, size_t contentSize, void *output) {
    output = content;
    return contentSize;
}
