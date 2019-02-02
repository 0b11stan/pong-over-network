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
    long long t0 = getTimestamp();
    long long t1;
    long long t2;
    long long t3;

    std::map<std::string, std::string> args;
    args["t0"] = std::to_string(t0);
    HTTPResponse response = connection.get("/pings", args);

    t3 = getTimestamp();

    auto result = response.to_map();
    if (!(std::istringstream(result["t1"]) >> t1)) t1 = 0;
    if (!(std::istringstream(result["t2"]) >> t2)) t2 = 0;
    if (t1 == 0 or t2 == 0) exit(EXIT_FAILURE);

    return ((t1 - t0) + (t2 - t3)) / 2;
}

long long int Server::getTimestamp() {
    struct timeval tp{};
    gettimeofday(&tp, nullptr);
    return (long long) tp.tv_sec * 1000L + tp.tv_usec / 1000;;
}
