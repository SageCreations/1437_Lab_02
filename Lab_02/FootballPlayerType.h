#ifndef FOOTBALLPLAYERTYPE_H
#define FOOTBALLPLAYERTYPE_H

#include <string>

struct Player {
    std::string name;
    std::string position;
    int touch_downs;
    int catches;
    int passing_yards;
    int recieving_yards;
    int rushing_yards;
};

#endif
