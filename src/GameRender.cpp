#include "stdafx.h"
#include "GameRender.h"
#include<conio.h>
#include<iostream>
#include<Windows.h>


GameRender::GameRender()
{
}


GameRender::~GameRender()
{
}

void GameRender::setGameObject(GameObject* gameObject) {
	gameObject_ = gameObject;

}

void GameRender::initMap() {
	for (int r = 0; r < LEVELROWS; r++) {
		for (int c = 0; c < LEVELCOLS; c++) {
			unsigned char symbol = LEVEDATA0[r][c];
			levelData_[r][c] = symbol;
		}
	}
}

void GameRender::update() {
	levelData_[static_cast<int>(gameObject_->getY())][static_cast<int>(gameObject_->getX())] = ' ';
	gameObject_->update();
  	levelData_[static_cast<int>(gameObject_->getY())][static_cast<int>(gameObject_->getX())] = gameObject_->getSymbol();
}

void GameRender::render() {
	COORD coord;
	coord.X = 0;
	coord.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

	//std::cout << "\n\n\n\t";
	std::cout << "          Health-000"<<std::endl;
	for (int r = 0; r < LEVELROWS; r++) {
		for (int c = 0; c < LEVELCOLS; c++) {
			unsigned char symbol = levelData_[r][c];

			switch (symbol) {
			case '#': {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				break;
			}
			}

					  std::cout << symbol;
			}
			std::cout << "\n";
		}
}