//
// Created by tristan on 30/01/19.
//

#include "Server.h"
#include "Player.h"

bool Server::stopped = false;

Server::Server(Player &player, Player &opponent): player(player), opponent(opponent) {
    SDL_Thread *pingUpdater = SDL_CreateThread(run_pingUpdater, "PON Ping Updater", (void *) this);
    threads.push_back(pingUpdater);
}

void Server::startStateSharing() {
    SDL_Thread *stateSender = SDL_CreateThread(run_padPlayerStateSender, "PON State Sender", (void *) this);
    SDL_Thread *stateReader = SDL_CreateThread(run_padPlayerStateReader, "PON State Sender", (void *) this);
    threads.push_back(stateSender);
    threads.push_back(stateReader);
}

void Server::close() {
    stopped = true;
    for (auto &thread : threads) SDL_WaitThread(thread, nullptr);
}

int Server::run_padPlayerStateReader(void *parent) {
    auto *server = static_cast<Server *>(parent);

    while (not stopped) {
        map<string, string> args;
        args["k"] = to_string(server->player.getKey());
        args["timeout"] = "5";
        HTTPResponse response;
        HTTP::get("/msgs", response, args);

        printf("Read data from server : %s\n", response.body.c_str());
        map<string, string> result = response.to_map();
        int newY;
        if (!(istringstream(result["data"]) >> newY)) newY = 0;
        server->opponent.position.setY(newY);

        SDL_Delay(100);
    }

    return 0;
}

int Server::run_padPlayerStateSender(void *parent) {
    auto *server = static_cast<Server *>(parent);

    while (not stopped) {
        string data = to_string(server->player.position.getY());

        map<string, string> args;
        args["k"] = to_string(server->player.getKey());
        args["to"] = to_string(server->opponent.getKey());
        args["data"] = data;
        HTTPResponse response;

        HTTP::post("/msgs", args);
        printf("Send data to server : %s\n", data.c_str());

        SDL_Delay(100);
    }

    return 0;
}

int Server::run_pingUpdater(void *parent) {
    auto *server = static_cast<Server *>(parent);

    while (not stopped) {
        long long t0 = getTimestamp();
        long long t1;
        long long t2;
        long long t3;

        map<string, string> args;
        args["k"] = to_string(server->player.getKey());
        args["t0"] = to_string(t0);
        HTTPResponse response;
        HTTP::get("/pings", response, args);

        t3 = getTimestamp();

        auto result = response.to_map();
        if (!(istringstream(result["t1"]) >> t1)) t1 = 0;
        if (!(istringstream(result["t2"]) >> t2)) t2 = 0;

        if (t1 == 0 or t2 == 0) exit(EXIT_FAILURE);

        server->ping = static_cast<int>((t3 - t0) - (t2 - t1));

        SDL_Delay(100);
    }
    return 0;
}

long long int Server::getTimestamp() {
    struct timeval tp{};
    gettimeofday(&tp, nullptr);
    return (long long) tp.tv_sec * 1000L + tp.tv_usec / 1000;;
}
