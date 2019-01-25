//
// Created by tristan on 25/01/19.
//

#ifndef BROCKENBRICK_REMOTE_H
#define BROCKENBRICK_REMOTE_H


class Remote {

public:
    Remote();
    int getPing();

private:
    const char* baseURI = "http://syllab.com/PTRE839/";

};


#endif //BROCKENBRICK_REMOTE_H
