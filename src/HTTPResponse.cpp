//
// Created by tristan on 30/01/19.
//

#include <iostream>
#include <vector>
#include "HTTPResponse.h"

const map<string, string> HTTPResponse::to_map() const {

    map<string, string> map;
    string key;
    string value;

    JSON state = JSON::END_VALUE;

    for (auto const &elem : body) {
        switch (state) {
            case JSON::START_KEY:
                if (elem == '"') state = JSON::END_KEY;
                else key += elem;
                break;
            case JSON::END_KEY:
                if (elem == ':') state = JSON::START_VALUE;
                break;
            case JSON::START_VALUE:
                if (elem == ',' or elem == '}') {
                    state = JSON::END_VALUE;
                    map[key] = value;
                    key = "";
                    value = "";
                } else if (elem != '"') value += elem;
                break;
            case JSON::END_VALUE:
                if (elem == '"') state = JSON::START_KEY;
                break;
        }
    }

    return map;
}

const vector <string> explode(const string &s, const char &c) {
    string buffer;
    vector<string> result;

    for (auto n:s) {
        if (n != c) buffer += n;
        else if (n == c && !buffer.empty()) {
            result.push_back(buffer);
            buffer = "";
        }
    }
    if (!buffer.empty()) result.push_back(buffer);

    return result;
}
