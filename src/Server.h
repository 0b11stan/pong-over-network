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

using namespace std;

class Server {

    // TODO : abstraire tout le vocabulaire http pour être plus flexible
    // TODO : faire une sémaphore pour la variable ping

public:

    Server();

    void close();

    static int run_pingUpdate(void *data);

    const int getPing() { return ping; }

private:

    int ping = 0;
    static bool stopped;
    vector<SDL_Thread *> threads = vector<SDL_Thread *>();

    static long long getTimestamp();

};


#endif //PONG_OVER_NETWORK_SERVER_H
