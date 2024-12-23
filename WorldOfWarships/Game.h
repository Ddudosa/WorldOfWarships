#pragma once
#include "Player.h"
#include <iostream>
#include <vector>
#include <conio.h>
#include <fstream>
class Game {
private:
	bool game_status;
	bool turn;
	string winner_name;
	Player* player1_game;
	Player* player2_game;

public:
	Game(bool ItsII, Player* player1, Player* player2, vector <int>* VC);

	bool Check_status();

	void Start_play(bool player);

	void post_game_status();
};

