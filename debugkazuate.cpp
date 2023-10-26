#include "kazuate.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define D_DEBUG_ON

void Init()
{
	answer = 0;
	number = 0;
}

void InitRand()
{
	srand((unsigned int)time(NULL));
}

void Answer()
{
	cin >> answer;
}

void Number()
{
	number = rand() % MAX_VALUE + 1;
#ifdef D_DEBUG_ON
	cout << "選ばれた数字は" << number << "です。" << endl;
#endif

}

bool Guess()
{
	cout << "あなたの答えは > " << flush;
	Answer();

	if (number == answer)
	{
		cout << "正解！" << endl;
		return false;
	}
	else if (abs(number - answer) <= 10)
	{
		cout << "近いよ！" << endl;
	}
	else
	{
		cout << "まだ遠いよ" << endl;
	}

}

void Gamekazuate()
{
	InitRand();
	Number();

	cout << "1～100の中から選ばれた数字を当てなさい" << endl;
	while (Guess())
	{

	}

	Init();
}

