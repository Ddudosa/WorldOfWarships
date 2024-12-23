#include "Player.h"
#include "Board.h"
#include <iostream>
#include <vector>
#include <conio.h>
#include <fstream>

using namespace std;

Player::Player(string name, bool ItsII, Board* PlayerBoard, Board* EnemyBoard) {
	this->name = name;
	this->ItsII = ItsII;
	this->PlayerBoard = PlayerBoard;
	this->EnemyBoard = EnemyBoard;
}

Board* Player::get_my_Board() {
	return PlayerBoard;
}

Board* Player::get_enemy_Board() {
	return EnemyBoard;
}

string Player::retun_name() {
	return name;
}

void Player::Ship_on_Board(vector<int> countTypes) {
	int x, y;
	bool orient, fl;
	for (int i = 0; i < countTypes[0]; i++)
	{
		fl = 0;
		do
		{
			if (!ItsII)
			{
				cout << "Введите x, y, ориентацию (0/1) для однопалубного корабля:" << endl;
				cin >> x >> y >> orient;
				x--;
				y--;
			}
			else
			{
				x = rand() % PlayerBoard->get_size();
				y = rand() % PlayerBoard->get_size();
				orient = rand() % 2;
			}
			Ship boat(i, x, y, 1, orient);
			fl = PlayerBoard->arrange_the_ships(boat);
			if (fl) PlayerBoard->arrange_the_ships(boat, 1);
			else if (!ItsII)cout << "Так корабль поставить нельзя!" << endl;
		} while (!fl);
	}
	for (int i = 0; i < countTypes[1]; i++)
	{
		fl = 0;
		do
		{
			if (!ItsII)
			{
				cout << "Введите x, y, ориентацию (0/1) для двупалубного корабля:" << endl;
				cin >> x >> y >> orient;
				x--;
				y--;
			}
			else
			{
				x = rand() % PlayerBoard->get_size();
				y = rand() % PlayerBoard->get_size();
			}
			Ship boat(i + countTypes[0], x, y, 2, orient);
			fl = PlayerBoard->arrange_the_ships(boat);
			if (fl) PlayerBoard->arrange_the_ships(boat, 1);
			else if (!ItsII) cout << "Так корабль поставить нельзя!" << endl;
		} while (!fl);
	}
	for (int i = 0; i < countTypes[2]; i++)
	{
		fl = 0;
		do
		{
			if (!ItsII)
			{
				cout << "Введите x, y, ориентацию (0/1) для трёхпалубного корабля:" << endl;
				cin >> x >> y >> orient;
				x--;
				y--;
			}
			else
			{
				x = rand() % PlayerBoard->get_size();
				y = rand() % PlayerBoard->get_size();
			}
			Ship boat(i + countTypes[0] + countTypes[1], x, y, 3, orient);
			fl = PlayerBoard->arrange_the_ships(boat);
			if (fl) PlayerBoard->arrange_the_ships(boat, 1);
			else if (!ItsII) cout << "Так корабль поставить нельзя!" << endl;
		} while (!fl);
	}
	for (int i = 0; i < countTypes[3]; i++)
	{
		fl = 0;
		do
		{
			if (!ItsII)
			{
				cout << "Введите x, y, ориентацию (0/1) для четырёхпалубного корабля:" << endl;
				cin >> x >> y >> orient;
				x--;
				y--;
			}
			else
			{
				x = rand() % PlayerBoard->get_size();
				y = rand() % PlayerBoard->get_size();
			}
			Ship boat(i + countTypes[0] + countTypes[1] + countTypes[2], x, y, 4, orient);
			fl = PlayerBoard->arrange_the_ships(boat);
			if (fl) PlayerBoard->arrange_the_ships(boat, 1);
			else if (!ItsII) cout << "Так корабль поставить нельзя!" << endl;
		} while (!fl);
	}
}

int Player::attack() {
	bool fl, fk;
	unsigned x, y;
	do {
		if (!ItsII) {
			cout << "Введите координаты выстрела по x " << endl;
			cin >> x;
			cout << "Введите координаты выстрела по y " << endl;
			cin >> y;
			x--;
			y--;
		}
		else {
			x = rand() % EnemyBoard->get_size();
			y = rand() % EnemyBoard->get_size();
		}
		fl = EnemyBoard->make_a_hit(x, y);
		if (fl == 0 && !ItsII) cout << "Вы туда уже стреляли, выберите другие координаты!" << endl;
		else {
			if (EnemyBoard->get_cell(x, y) == -2) return 0; // Попали в пустую клетку
			else
			{
				if (EnemyBoard->get_ship(x, y)->check_status() == 1) return 1; // Ранили корабль
				else return 2; // Убили корабль
			}
		}
	} while (fl == 0);
}

void Player::Stat() {
	int full_enemy = 0, full_player = 0, crippled_enemy = 0, crippled_player = 0, dead_enemy = 0, dead_player = 0;
	//for (int i = 0; i < EnemyBoard->get_vector()->size(); i++)
	//{
	//	int k = (*EnemyBoard->get_vector())[i].check_status();
	//	if (k == 2) full_enemy++;
	//	else if (k == 1) crippled_enemy++;
	//	else if (k == 0) dead_enemy++;
	//}
	for (int i = 0; i < PlayerBoard->get_vector()->size(); i++)
	{
		int k = (*EnemyBoard->get_vector())[i].check_status();
		if (k == 2) full_player++;
		else if (k == 1) crippled_player++;
		else if (k == 0) dead_player++;
	}
	cout << "Колличество целых кораблей:   " << full_player << endl;
	cout << "Колличество подбитых кораблей:   " << crippled_player << endl;
	cout << "Колличество убитых кораблей:   " << dead_player << endl;
}

bool Player::return_II() {
	return ItsII;
}

Player::~Player() {};

