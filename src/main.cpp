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

	if (game.isVictory_ == true) {
		std::cout << "YOU WIN"<<std::endl;
	}else
	std::cout << "GAME OVER" << std::endl;

	system("pause");

    return 0;
}

