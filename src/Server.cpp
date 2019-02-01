//
// Created by tristan on 30/01/19.
//

#include "Server.h"

Server::Server(HTTP &connection) : connection(connection) {
    connection.init();
}

std::string Server::help() {

    if (!connection.init()) {
        fprintf(stderr, "HTTP initialization failed\n");
        exit(EXIT_FAILURE);
    }

    std::string response = connection.get("/help").getBody();

    return response;
}

int Server::ping() {
    return 0;
}
