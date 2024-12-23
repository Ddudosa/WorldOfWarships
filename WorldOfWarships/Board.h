#pragma once
#include "Ship.h"
#include <iostream>
#include <vector>
#include <conio.h>
#include <fstream>
using namespace std;

class Board {
protected:
	unsigned size;
	int** field;
	Ship*** adres;
	vector <Ship>* MasOfShips;
public:
	Board(unsigned size, vector <Ship>* MasOfShips);
	bool arrange_the_ships(Ship& boat, bool in_adres = 0);
	int get_cell(unsigned x, unsigned y);
	unsigned  get_size();
	Ship* get_ship(unsigned x, unsigned y);
	vector <Ship>* get_vector();
	bool make_a_hit(unsigned x, unsigned y);
	bool all_ships_is_dead();
	void vizual(bool its_mine);
	void get_field();

	~Board();
};
