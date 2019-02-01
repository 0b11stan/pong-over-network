//
// Created by tristan on 30/01/19.
//

#ifndef PONG_OVER_NETWORK_SERVER_H
#define PONG_OVER_NETWORK_SERVER_H


#include <string>
#include "HTTP.h"

class Server {

public:
    explicit Server(HTTP &connection);

    std::string help();
    int ping();

private:
    HTTP &connection;

};


#endif //PONG_OVER_NETWORK_SERVER_H
