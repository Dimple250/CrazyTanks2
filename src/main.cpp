// CrazyTanks2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Game.h"
#include<iostream>

int main()
{
	Game game;

	game.init();

	while (game.loop());

	std::cout << "GAME OVER";

	system("pause");

    return 0;
}

