//
// Created by tristan on 30/01/19.
//

#include "Server.h"

Server::Server(HTTP connection) {
    connection.init();

}

std::string Server::help() {
    return "";
}
