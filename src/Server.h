//
// Created by tristan on 30/01/19.
//

#ifndef PONG_OVER_NETWORK_SERVER_H
#define PONG_OVER_NETWORK_SERVER_H

#include <ctime>
#include <string>
#include <sstream>
#include "HTTP.h"

using namespace std;

class Server {

    // TODO : abstraire tout le vocabulaire http pour être plus flexible

public:

    void updatePing();

    static int run_pingUpdate(void *data);

    const int getPing() { return ping; }

private:

    static long long getTimestamp();

    // TODO : faire une sémaphore pour la variable ping
    int ping = 0; // ! not thread safe

};


#endif //PONG_OVER_NETWORK_SERVER_H
