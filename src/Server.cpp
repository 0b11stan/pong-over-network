//
// Created by tristan on 30/01/19.
//

#include "Server.h"

Server::Server(HTTP &connection) : connection(connection) {
    if (!connection.init()) {
        fprintf(stderr, "HTTP initialization failed\n");
        exit(EXIT_FAILURE);
    }
}

std::string Server::help() { return connection.get("/help").getBody(); }

int Server::ping() {
    return 0;
}
