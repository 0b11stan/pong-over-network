//
// Created by tristan on 25/01/19.
//

#include <curl/curl.h>
#include "Remote.h"

Remote::Remote() {
    CURL *curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "http://syllab.com/PTRE839/help?k=255058");
        CURLcode result = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if (result != CURLE_OK) {
            printf("Error while performing request : %s\n", curl_easy_strerror(result));
        }
    }

}

int Remote::getPing() {
    return 0;
}
