#include "doctest.h"
#include <string>
#include <stdexcept>
#include <iostream>
#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Game.hpp"
using namespace std;
using namespace coup;

TEST_SUITE("checking that functions doesnt throw exceptions")
{
	TEST_CASE("first check that constructor doesnt throws")
	{
		// check for initilising the board
		CHECK_NOTHROW_MESSAGE(coup::Game(), "Constructor should not throw");
		coup::Game board{};
		CHECK_NOTHROW_MESSAGE(coup::Captain(board, "Dolev"), "Constructor should not throw");
		// check that we new is working and ok constructor
		CHECK_NOTHROW_MESSAGE(coup::Captain(board, "Dolev"), "Constructor should not throw");
		// check that we new is working and ok constructor
		CHECK_NOTHROW_MESSAGE(coup::Assassin(board, "Dolev"), "Constructor should not throw");
		// check that we new is working and ok constructor
		CHECK_NOTHROW_MESSAGE(coup::Duke(board, "Dolev"), "Constructor should not throw");
		// check that we new is working and ok constructor
		CHECK_NOTHROW_MESSAGE(coup::Ambassador(board, "Dolev"), "Constructor should not throw");
	}

	TEST_CASE("check that game functions doesnt throw")
	{
		coup::Game board{};
		coup::Duke duke{board, "Moshe"};
		coup::Assassin assassin{board, "Yossi"};
		coup::Ambassador ambassador{board, "Meirav"};
		coup::Captain captain{board, "Reut"};
		coup::Contessa contessa{board, "Gilad"};

		// check that we can get the players

		CHECK_NOTHROW_MESSAGE(board.vec(), "playes work");
		CHECK_NOTHROW_MESSAGE(board.vec(), "playes work");
		CHECK_NOTHROW_MESSAGE(board.vec(), "playes work");
		CHECK_NOTHROW_MESSAGE(board.vec(), "playes work");
		CHECK_NOTHROW_MESSAGE(board.vec(), "playes work");
		CHECK_NOTHROW_MESSAGE(board.turn(), "turn work");
		CHECK_NOTHROW_MESSAGE(duke.income(), "income work");
		CHECK_NOTHROW_MESSAGE(assassin.income(), "income work");
		CHECK_NOTHROW_MESSAGE(ambassador.income(), "income work");
		CHECK_NOTHROW_MESSAGE(captain.income(), "income work");
		CHECK_NOTHROW_MESSAGE(contessa.income(), "income work");
	}
}

TEST_SUITE("checking game rulse ")
{
	TEST_CASE("check the game rules")
	{
		coup::Game board{};
		coup::Duke duke{board, "Moshe"};
		coup::Assassin assassin{board, "Yossi"};
		coup::Ambassador ambassador{board, "Meirav"};
		coup::Captain captain{board, "Reut"};
		coup::Contessa contessa{board, "Gilad"};

		CHECK_EQ(captain.coins(), 0);
		CHECK_EQ(contessa.coins(), 0);
		CHECK_EQ(duke.coins(), 0);
		CHECK_EQ(assassin.coins(), 0);
		CHECK_EQ(ambassador.coins(), 0);

		CHECK_EQ(board.turn(), "Moshe");
		CHECK_EQ(board.vec().size(), 5);
		CHECK_EQ(board.vec()[0], "Moshe");
		CHECK_EQ(board.vec()[1], "Yossi");
		CHECK_EQ(board.vec()[2], "Meirav");
		CHECK_EQ(board.vec()[3], "Reut");
		CHECK_EQ(board.vec()[4], "Gilad");
		CHECK_EQ(duke.income(), 2);
		CHECK_EQ(assassin.income(), 2);
		CHECK_EQ(ambassador.income(), 2);
		CHECK_EQ(captain.income(), 2);
		CHECK_EQ(contessa.income(), 2);
		CHECK_EQ(board.turn(), "Yossi");
		CHECK_EQ(assassin.income(), 4);
		CHECK_EQ(board.turn(), "Meirav");
		CHECK_EQ(ambassador.coins(), 4);
		CHECK_EQ(board.turn(), "Reut");
		CHECK_EQ(captain.coins(), 4);
		CHECK_EQ(board.turn(), "Gilad");
		CHECK_EQ(contessa.coins(), 4);
		


	}
}
