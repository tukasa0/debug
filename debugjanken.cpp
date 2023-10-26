#include "janken.h"
#include <iostream>
using namespace std;

#define D_DEBUG_ON

void InitPoint()
{
	player = 0;
	enemy = 0;
	playerPoint = 0;
	enemyPoint = 0;
}

void Playerhand()
{
	bool botton = true;

	cout << "出す手を決めてね" << endl;
	for (int i = 0; i < 3; ++i)
	{
		cout << hand[i] << "..." << i << " ";
	}
	cout << "-> " << flush;

	while (botton)
	{
		cin >> player;

		switch (player)
		{
		case Gu:
			botton = false;
			break;

		case Tyoki:
			botton = false;
			break;

		case Pa:
			botton = false;
			break;

		default:
			cout << "入力し直してください" << endl;
			continue;
		}
	}
	cout << endl;
}

void Enemyhand()
{
	enemy = rand() % 3;

#ifdef D_DEBUG_ON
	cout << "相手は" << hand[enemy] << "を出そうとしている" << endl;
#endif
}

void Showhand(int otherwords, int otherhand)
{
	cout << words[otherwords] << "は、" << hand[otherhand] << "を出しました。" << endl;
}

void Showpoint(int otherwords, int otherpoint)
{
	cout << words[otherwords] << otherpoint << words[Points] << endl;
}

bool Compare()
{
	Enemyhand();
	Playerhand();
	Showhand(Player, player);
	Showhand(Enemy, enemy);

	if (player == enemy)
	{
		cout << "あいこ" << endl;
	}
	else if (player + 1 == enemy || player - 2 == enemy)
	{
		cout << words[Player] << "の勝ち!" << endl;
		playerPoint++;
	}
	else if (enemy + 1 == player || enemy - 2 == player)
	{
		cout << words[Player] << "の負け..." << endl;
		enemyPoint++;
	}

	Showpoint(Player, playerPoint);
	Showpoint(Enemy, enemyPoint);

	if (playerPoint == 3)
	{
		cout << endl
			<< "おめでとう！" << endl;
		return false;
	}
	else if (enemyPoint == 3)
	{
		cout << endl
			<< "残念、また挑戦してね" << endl;
		return false;
	}
}

void Gamejanken()
{
	InitRand();

	while (Compare())
	{

	}

	InitPoint();
}