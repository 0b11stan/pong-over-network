//
// Created by tristan on 30/01/19.
//

#include <SDL_thread.h>
#include "Server.h"

//std::string Server::help() { return httpConnection.get("/help").getBody(); }

int Server::run_pingUpdate(void *server) {
    auto *parent = static_cast<Server *>(server);

    long long t0 = getTimestamp();
    long long t1;
    long long t2;
    long long t3;

    std::map<std::string, std::string> args;
    args["t0"] = std::to_string(t0);
    HTTPResponse response;
    HTTP::get("/pings", response, args);

    t3 = getTimestamp();

    auto result = response.to_map();
    if (!(std::istringstream(result["t1"]) >> t1)) t1 = 0;
    if (!(std::istringstream(result["t2"]) >> t2)) t2 = 0;

    if (t1 == 0 or t2 == 0) exit(EXIT_FAILURE);

    parent->ping = static_cast<int>((t3 - t0) - (t2 - t1));

    return 0;
}

long long int Server::getTimestamp() {
    struct timeval tp{};
    gettimeofday(&tp, nullptr);
    return (long long) tp.tv_sec * 1000L + tp.tv_usec / 1000;;
}

void Server::updatePing() {
    SDL_Thread *pingUpdater = SDL_CreateThread(run_pingUpdate, "PON Ping Updater", (void *)this);
}
