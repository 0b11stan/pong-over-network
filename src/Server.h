//
// Created by tristan on 30/01/19.
//

#ifndef PONG_OVER_NETWORK_SERVER_H
#define PONG_OVER_NETWORK_SERVER_H

#include <ctime>
#include <string>
#include <sstream>
#include <vector>
#include <SDL_thread.h>
#include <SDL_timer.h>
#include "HTTP.h"
#include "Player.h"
#include "LocalPlayer.h"
#include "RemotePlayer.h"

using namespace std;

class Server {

    // TODO : abstraire tout le vocabulaire http pour être plus flexible
    // TODO : faire une sémaphore pour la variable ping

public:

    explicit Server(LocalPlayer &player, RemotePlayer &opponent);

    void close();

    void startStateSharing();

    static int run_pingUpdater(void *parent);

    static int run_padPlayerStateSender(void *parent);

    static int run_padPlayerStateReader(void *parent);

    const int sendReadiness();

    const int clearQueue() const;

    const bool remoteIsReady() const { return remoteReadiness; }

    const bool localIsReady() const { return localReadiness; }

    const int getPing() const { return ping; }

    vector<SDL_Thread *> threads = vector<SDL_Thread *>();

private:

    LocalPlayer &player;
    RemotePlayer &opponent;
    bool remoteReadiness = false;
    bool localReadiness = false;
    int ping = 0;
    static bool stopped;

    static long long getTimestamp();

};


#endif //PONG_OVER_NETWORK_SERVER_H
