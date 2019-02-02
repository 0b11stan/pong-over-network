//
// Created by tristan on 30/01/19.
//

#ifndef PONG_OVER_NETWORK_SERVER_H
#define PONG_OVER_NETWORK_SERVER_H


#include <ctime>
#include <string>
#include <sstream>
#include "HTTP.h"

class Server {

public:
    explicit Server(HTTP &connection);

    std::string help();

    long ping();

private:
    HTTP &connection;
    long long getTimestamp();

};


#endif //PONG_OVER_NETWORK_SERVER_H
