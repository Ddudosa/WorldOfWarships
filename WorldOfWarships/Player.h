#pragma once
#include "Ship.h"
#include "Board.h"
#include <iostream>
#include <vector>
#include <conio.h>
#include <fstream>

using namespace std;

class Player {
public:
	string name;
	bool ItsII;
	Board* PlayerBoard;
	Board* EnemyBoard;

public:
	Player(string name, bool ItsII, Board* PlayerBoard, Board* EnemyBoard);
	Board* get_my_Board();
	Board* get_enemy_Board();
	string retun_name();
	void Ship_on_Board(vector<int> countTypes);
	int attack();
	void Stat();
	bool return_II();
	~Player();
};

