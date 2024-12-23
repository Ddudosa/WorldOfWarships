#pragma once
#include "Ship.h"
#include <iostream>
#include <vector>
#include <conio.h>
#include <fstream>
using namespace std;
class Ship {
private:
	int name; //����� �������. 1 - n -- 1-�� ������, n+1 - 2n -- 2-�� ������ ��� ����������
	unsigned size; // ������
	unsigned x; // ��������
	unsigned y; // ��������
	unsigned count_of_whole_decks; // ���������� ����� �����
	bool orient_vertical; // ����������
public:
	Ship();
	Ship(int name, unsigned x, unsigned y, unsigned size, bool orient);
	bool get_orient(); // �������� ����������
	unsigned get_size(); // �������� ������
	unsigned get_x(); // �������� x
	unsigned get_y(); // �������� y
	unsigned get_status();// ������� ���������� ����� �����
	unsigned check_status(); // ������� ��������� �������: 2 - ���, 1 - �����, 0 - ����
	void get_a_hit(); // ������� ����
	~Ship(); // ����������
};

