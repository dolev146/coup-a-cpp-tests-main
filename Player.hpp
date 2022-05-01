
#include "Game.hpp"
#include <string>
#pragma once
using namespace std;
namespace coup
{
    class Game;
    class Player
    {
    private:
        string name;
        int money;
        Game *board;

    public:
        Player(Game &board, string name);
        int income();
        void foreign_aid();
        void coup(Player p);
        void role();
        int coins();
        ~Player();
    };

}