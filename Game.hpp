#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <algorithm>
#pragma once
using namespace std;

namespace coup
{
    class Player;
    class Game
    {
    private:
    public:
        vector<string> playersList;
        unsigned int i;
        vector<string> players();
        string turn();
        string winner();
    };
}
