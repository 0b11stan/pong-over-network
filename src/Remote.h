//
// Created by tristan on 25/01/19.
//

#ifndef BROCKENBRICK_REMOTE_H
#define BROCKENBRICK_REMOTE_H

#include <curl/curl.h>
#include <string>

enum HttpMethod { GET, POST, DELETE };

class Remote {

public:
    void requestPing();

private:
    /**
     * TODO : on peut proposer à l'utilisateur de choisir
     * qui il est dans une list déroulante qui viendra d'un
     * appel au serveur ==> /players
     */
    CURL *curlHandler = curl_easy_init();
    std::string baseURI = "http://syllab.com/PTRE839";
    std::string baseKEY = "255058";
    char* request(HttpMethod method, std::string path);
    static size_t callbackWriter(char *content, size_t size, size_t contentSize, void *output);

};


#endif //BROCKENBRICK_REMOTE_H
