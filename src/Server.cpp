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

long Server::ping() {
    long int t0 = std::time(nullptr);
    long int t1;
    long int t2;
    long int t3;

    std::map<std::string, std::string> args;
    args["t0"] = std::to_string(t0);
    HTTPResponse response = connection.get("/pings", args);

    t3 = std::time(nullptr);

    auto result = response.to_map();
    if ( !(std::istringstream(result["t1"]) >> t1) ) t1 = 0;
    if ( !(std::istringstream(result["t2"]) >> t2) ) t2 = 0;

    auto ping = ( (t1 - t0) + (t2 - t3) ) / 2;

    // TODO : rectifier, faux resultat

    printf("t0: %lu\nt1: %lu\nt2: %lu\nt3: %lu", t0, t1, t2, t3);
    printf("\nping : %lu", ping);

    return ping;
}
