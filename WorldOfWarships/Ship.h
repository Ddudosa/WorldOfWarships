#pragma once
#include "Ship.h"
#include <iostream>
#include <vector>
#include <conio.h>
#include <fstream>
using namespace std;
class Ship {
private:
	int name; //номер корабля. 1 - n -- 1-го игрока, n+1 - 2n -- 2-го игрока или компьютера
	unsigned size; // Размер
	unsigned x; // Ордината
	unsigned y; // Абсцисса
	unsigned count_of_whole_decks; // Количество целых палуб
	bool orient_vertical; // Ориентация
public:
	Ship();
	Ship(int name, unsigned x, unsigned y, unsigned size, bool orient);
	bool get_orient(); // Получить ориентацию
	unsigned get_size(); // Получить размер
	unsigned get_x(); // Получить x
	unsigned get_y(); // Получить y
	unsigned get_status();// Вернуть количество целых палуб
	unsigned check_status(); // Вернуть состояние корабля: 2 - цел, 1 - ранен, 0 - убит
	void get_a_hit(); // Сделать удар
	~Ship(); // Деструктор
};

