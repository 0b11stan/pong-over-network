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
    long int now = std::time(nullptr);
    printf("t0: %lu\n", now);

    std::map<std::string, std::string> args;

    args["t0"] = std::to_string(now);

    std::string ping = connection.get("/pings", args).getBody();
    printf("ping : %s", ping.c_str());
    return 0;
}
