#include "Board.h"
#include "Ship.h"
#include <iostream>
#include <vector>
#include <conio.h>
#include <fstream>
using namespace std;

Board::Board(unsigned size, vector <Ship>* MasOfShips) {
	this->size = 10;
	field = new int* [size];
	this->MasOfShips = MasOfShips;
	for (int i = 0; i < size; i++)
	{
		field[i] = new int[size];
		for (int j = 0; j < size; j++) field[i][j] = 0;
	}
	adres = new Ship * *[size];
	for (int i = 0; i < size; i++)
	{
		adres[i] = new Ship * [size];
		for (int j = 0; j < size; j++) adres[i][j] = NULL;
	}
};
bool Board::arrange_the_ships(Ship& boat, bool in_adres)
{
	unsigned x = boat.get_x(), y = boat.get_y();
	if (x >= size || y >= size) return 0;
	if (boat.get_orient())
	{
		for (int i = 0; i < boat.get_size(); i++) if (y + i >= size) return 0; // Возвращаем 0, если выходим за матрицу
		for (int i = 0; i < boat.get_size(); i++) if (field[x][y + i] == 3 || field[x][y + i] == 1) return 0; // Возвращаем 0, если попадаем к другому кораблю
		if (in_adres)
		{
			MasOfShips->push_back(boat);
			for (int i = 0; i < boat.get_size(); i++)
			{
				//cout << x << " " << y + i;
				field[x][y + i] = 1;
				//cout << " " << field[x][y + i] << endl;
				if (in_adres) adres[x][y + i] = &((*MasOfShips)[MasOfShips->size() - 1]);
				if (x != 0) field[x - 1][y + i] = 3;
				if (x != size - 1) field[x + 1][y + i] = 3;
			}
			if (y != 0)
			{
				field[x][y - 1] = 3;
				if (x != 0) field[x - 1][y - 1] = 3;
				if (x != size - 1) field[x + 1][y - 1] = 3;
			}
			if (y + boat.get_size() != size)
			{
				field[x][y + boat.get_size()] = 3;
				if (x != 0) field[x - 1][y + boat.get_size()] = 3;
				if (x != size - 1) field[x + 1][y + boat.get_size()] = 3;
			}
		}
	}
	else
	{
		for (int i = 0; i < boat.get_size(); i++) if (x + i >= size) return 0; // Возвращаем 0, если выходим за матрицу
		for (int i = 0; i < boat.get_size(); i++) if (field[x + i][y] == 3 || field[x + i][y] == 1) return 0; // Возвращаем 0, если попадаем к другому кораблю
		if (in_adres)
		{
			MasOfShips->push_back(boat);
			for (int i = 0; i < boat.get_size(); i++)
			{
				field[x + i][y] = 1;
				if (in_adres)adres[x + i][y] = &((*MasOfShips)[MasOfShips->size() - 1]);
				if (y != 0) field[x + i][y - 1] = 3;
				if (y != size - 1) field[x + i][y + 1] = 3;
			}
			if (x != 0)
			{
				field[x - 1][y] = 3;
				if (y != 0) field[x - 1][y - 1] = 3;
				if (y != size - 1) field[x - 1][y + 1] = 3;
			}
			if (x + boat.get_size() != size)
			{
				field[x + boat.get_size()][y] = 3;
				if (y != 0) field[x + boat.get_size()][y - 1] = 3;
				if (y != size - 1) field[x + boat.get_size()][y + 1] = 3;
			}
		}
	}
	return 1;
};
int Board::get_cell(unsigned x, unsigned y) { return field[x][y]; };
unsigned  Board::get_size() { return size; };
Ship* Board::get_ship(unsigned x, unsigned y) { return adres[x][y]; };
vector <Ship>* Board::get_vector() { return MasOfShips; };
bool Board::make_a_hit(unsigned x, unsigned y) // 1 - целая палуба, -1 - подбитая палуба, 0 - пусто, -2 - пусто подбито, 3 - пусто, но около корабля
{

	if (x < size || y < size)
	{
		if (field[x][y] == 1)
		{
			field[x][y] = -1;
			adres[x][y]->get_a_hit();
			//print_status(adres[x][y]->check_status());
			return 1;
		}
		else if (field[x][y] == 0 || field[x][y] == 3)
		{
			field[x][y] = -2;
			//cout << "Мимо!" << endl;
			return 1;
		}
		else return 0;
	}
	else return 0;
};
bool Board::all_ships_is_dead()
{
	bool fl = 1;
	for (int i = 0; i != this->size; i++) for (int j = 0; j != this->size; j++) { if (field[i][j] == 1) fl = 0; }
	return fl;
}
void Board::vizual(bool its_mine) // 1 - я смотрю на моё поле, 0 - я смотрю на поле прпотивника
{
	if (its_mine)
	{
		cout << "Ваше поле:" << endl;
		cout << "   ";
		for (int i = 0; i < size; i++) cout << i + 1;
		cout << endl;
		//cout << endl;
		for (int i = 0; i < size; i++)
		{
			if (i < 9) cout << i + 1 << "  ";
			else cout << i + 1 << " ";
			for (int j = 0; j < size; j++)
			{
				if (field[j][i] == 1) cout << "#";
				else if (field[j][i] == -1) cout << "X";
				else if (field[j][i] == -2) cout << "*";
				else cout << "0";
			}
			cout << endl;
		}
		cout << endl;
	}
	else
	{
		cout << "Поле противника:" << endl;
		cout << "   ";
		for (int i = 0; i < size; i++) cout << i + 1;
		cout << endl;
		//cout << endl;
		for (int i = 0; i < size; i++)
		{
			if (i < 9) cout << i + 1 << "  ";
			else cout << i + 1 << " ";
			for (int j = 0; j < size; j++)
			{
				if (field[j][i] == -1) cout << "X";
				else if (field[j][i] == -2) cout << "*";
				else cout << "0";
			}
			cout << endl;
		}
		cout << endl;
	}
}
void Board::get_field()
{
	cout << endl << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << field[j][i];
		}
		cout << endl;
	}
}
Board::~Board() {
	for (int i = 0; i < size; i++)
	{
		delete[] field[i];
		delete[] adres[i];
	}
	delete[] field;
	delete[] adres;
};