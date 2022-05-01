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
        vector<string> list_of_playes;
        unsigned int i;
        vector<string> vec();
        string turn();
        string winner();
    };
}
