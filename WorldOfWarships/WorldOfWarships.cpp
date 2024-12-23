// WorldOfWarships.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <conio.h>
#include <fstream>
#include "Game.h"

using namespace std;

int main()
{
	srand(time(0));
	setlocale(0, "");
	vector <Ship> vPlayer_1;
	vector <Ship> vEnemy_1;
	vector <int> vCount{ 4, 3, 2, 1 };
	Board PlBoard_1(10, &vPlayer_1);
	Board EnBoard_1(10, &vEnemy_1);

	bool ISII;
	string player1_name, player2_name = "Компьютер";
	cout << "Добро пожаловать в Морской бой, вы хотите сыграть с компьютером? 1-да, 0-нет " << endl;
	cin >> ISII;
	cout << "Введите имя игрока  №1 "; cin >> player1_name;
	if (not ISII) { cout << "Введите имя игрока  №2 "; cin >> player2_name; };
	Player Player1(player1_name, 0, &PlBoard_1, &EnBoard_1);
	Player Player2(player2_name, ISII, &EnBoard_1, &PlBoard_1);

	Game Main(ISII, &Player1, &Player2, &vCount);
	Main.Start_play(ISII);
	Main.post_game_status();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
