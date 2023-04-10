#pragma once
#include <string>

std::string CreateGUID(const int length) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    std::string temp;
    temp.reserve(length);

    for (int i = 0; i < length; ++i) {
        temp += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return temp;
}