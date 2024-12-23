#include "Game.h"
#include <iostream>
#include <vector>
#include <conio.h>
#include <fstream>
using namespace std;

Game::Game(bool ItsII, Player* player1, Player* player2, vector <int>* VC) {
	winner_name = "0";
	this->player1_game = player1;
	this->player2_game = player2;

	cout << "Доску заполняет " << player1->retun_name() << endl;
	player1_game->Ship_on_Board(*VC);
	cout << "Готово" << endl;

	cout << "Доску заполняет " << player2->retun_name() << endl;
	player2_game->Ship_on_Board(*VC);
	cout << "Готово" << endl;

	turn = 1;
	game_status = 1;
};

bool Game::Check_status() {
	if (player1_game->get_my_Board()->all_ships_is_dead())
	{
		game_status = 0;
		return 0;
	}
	if (player2_game->get_my_Board()->all_ships_is_dead())
	{
		game_status = 0;
		return 1;
	}
}

void Game::Start_play(bool player) {
	int nthg, k = 0;
	bool win_player;
	int status;

	while (game_status)
	{
		if (turn) {
			system("cls");
			if (not player2_game->return_II()) {
				cout << "Пригласите игрока " << player1_game->retun_name() << "И Введите что-нибудь ";
				cin >> nthg;
			}
			player1_game->get_my_Board()->vizual(true);
			player1_game->get_enemy_Board()->vizual(false);

			status = player1_game->attack();
			if (status != 0) turn = 1;
			else turn = 0;
			switch (status)
			{
			case 0:
				cout << "Мимо!" << endl;
				break;
			case 1:
				cout << "Попал!" << endl;
				break;
			case 2:
				cout << "Убит!" << endl;
			default:
				break;
			}
			cout << "Введите что то для продолжения ";
			cin >> nthg;
			win_player = this->Check_status();

		}
		else {
			system("cls");
			if (not player2_game->return_II()) {
				cout << "Пригласите игрока " << player2_game->retun_name() << "И Введите что-нибудь ";
				cin >> nthg;
			}

			player2_game->get_my_Board()->vizual(true);
			player2_game->get_enemy_Board()->vizual(false);


			status = player2_game->attack();
			if (status != 0) turn = 0;
			else turn = 1;
			if (not player2_game->return_II()) {
				switch (status)
				{
				case 0:
					cout << "Мимо!" << endl;
					break;
				case 1:
					cout << "Попал!" << endl;
					break;
				case 2:
					cout << "Убит!" << endl;
					break;
				default:
					break;
				}

				cout << "Введите что то для продолжения ";
				cin >> nthg;
			}
			win_player = this->Check_status();
		};
	}

	if (win_player) winner_name = player1_game->retun_name();
	else winner_name = player2_game->retun_name();
}

void Game::post_game_status() {
	cout << "Победил игрок " << winner_name << endl;

	cout << "Статистика игрока №1 " << endl;
	player1_game->Stat();
	cout << endl;

	cout << "Статистика игрока №2 " << endl;
	player2_game->Stat();
	cout << endl;
}

