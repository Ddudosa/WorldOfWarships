#include "Ship.h"
#include <iostream>
#include <vector>
#include <conio.h>
#include <fstream>

using namespace std;

Ship::Ship() {
	this->name = 0;
	this->x = 0;
	this->y = 0;
	this->size = 0;
	this->orient_vertical = 0;
	this->count_of_whole_decks = 0;
};
Ship::Ship(int name, unsigned x, unsigned y, unsigned size, bool orient)
{
	this->name = name;
	this->x = x;
	this->y = y;
	this->size = size;
	this->orient_vertical = orient;
	this->count_of_whole_decks = size;
};
bool Ship::get_orient() { return orient_vertical; };
unsigned Ship::get_size() { return size; };
unsigned Ship::get_x() { return x; };
unsigned Ship::get_y() { return y; };
unsigned Ship::get_status() { return count_of_whole_decks; };
unsigned Ship::check_status()
{
	if (count_of_whole_decks == 0) return 0; // убит
	else if (count_of_whole_decks < size) return 1; // ранен
	else return 2; // цел
};
void Ship::get_a_hit() { count_of_whole_decks--; };
Ship::~Ship() {};