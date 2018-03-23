#include "stdafx.h"
#include "Game.h"
#include<iostream>
#include<conio.h>
#include <ctime>

Game::Game():isGame_(true),kolKilledTanks(0)
{

}


Game::~Game()
{
	delete tank_;
	delete [] objects_;
}

void Game::init(){
	srand(time(0));

	gameReder.initMap();

	for (int i = 0; i < 1024; i++) {
		objects_[i] = 0;
	}

	for (int r = 0; r < LEVELROWS; r++) {
		for (int c = 0; c < LEVELCOLS; c++) {
			unsigned char symbol = LEVEDATA0[r][c];

			switch (symbol) {
			case SPLAYER: {
				tank_ = new Tank;
				tank_->setX(c);
				tank_->setY(r);
				tank_->setSymbol(symbol);
				tank_->setShift(1);
				tank_->setObjectType(PlayerType);
				tank_->setHealth(3);
				break;
			}
			case SWALL: {
				for (int i = 0; i < 1024; i++) {
					if (objects_[i] == 0) {
						objects_[i] = new Wall;
						objects_[i]->setX(c);
						objects_[i]->setY(r);
						objects_[i]->setSymbol(symbol);
						objects_[i]->setObjectType(WallType);
						break;
					}
				}
				break;
				}
			case SBREAKWALL: {
				for (int i = 0; i < 1024; i++) {
					if (objects_[i] == 0) {
						objects_[i] = new Wall;
						objects_[i]->setX(c);
						objects_[i]->setY(r);
						objects_[i]->setSymbol(symbol);
						objects_[i]->setObjectType(BreakEallType);
						break;
					}
				}
				break;
			}
			case SGOLD: {
				for (int i = 0; i < 1024; i++) {
					if (objects_[i] == 0) {
						objects_[i] = new Gold;
						objects_[i]->setX(c);
						objects_[i]->setY(r);
						objects_[i]->setSymbol(symbol);
						objects_[i]->setObjectType(GoldType);
						break;
					}
				}
				break;
			}
			case SENEMY: {
				for (int i = 0; i < 1024; i++) {
					if (objects_[i] == 0) {
						objects_[i] = new Tank;
						objects_[i]->setX(c);
						objects_[i]->setY(r);
						objects_[i]->setSymbol(symbol);
						objects_[i]->setShift(0.1);
						objects_[i]->setObjectType(EnemyType);
						objects_[i]->setHealth(3);
						break;
					}
				}
				break;
			}
			}
		}
	}
	
}

void Game::createBullet(int r, int c,GameObject* gameObject) {
	for (int i = 0; i < 1024; i++) {
		if (objects_[i] == 0) {
			if (conflict(r,c) != false) {
				objects_[i] = new Bullet(c, r,gameObject->getDirection());
				static_cast<Bullet*>(objects_[i])->setCreatorType(gameObject->getObjectType());
				objects_[i]->setShift(0.5);
				objects_[i]->setObjectType(BulletType);
			}else {
				if (objects_[getIndexGameObject(r, c)]->getObjectType() == BreakEallType) {
					int index = getIndexGameObject(r, c);
					objects_[index]->setSymbol(' ');
					gameReder.setGameObject(objects_[index]);
					gameReder.update();
					delete 	objects_[index];
					objects_[index] = 0;
				}
				else {

				}
			}
			break;
		}
	}
}

void Game::update() {
	unsigned char direction = '1';
	if (_kbhit())
	{
		direction = _getch();
	}

	switch (direction) {
		//up
	case 72: {
		tank_->setDirection(UP);
		if (conflict(tank_->getY() - 1, tank_->getX()) != false) {
			gameReder.setGameObject(tank_);
			gameReder.update();
		}
		break;
	}
			 //down
	case 80: {
		tank_->setDirection(DOWN);
		if (conflict(tank_->getY() + 1, tank_->getX()) != false) {
			gameReder.setGameObject(tank_);
			gameReder.update();
		}
		break;
	}
			 //left
	case 75: {
		tank_->setDirection(LEFT);
		if (conflict(tank_->getY(), tank_->getX() - 1) != false) {
			gameReder.setGameObject(tank_);
			gameReder.update();
		}
		break;
	}
			 //right
	case 77: {
		tank_->setDirection(RIGHT);
		if (conflict(tank_->getY(), tank_->getX() + 1) != false) {
			gameReder.setGameObject(tank_);
			gameReder.update();
		}
		break;
	}
	case 32: {
		int r = 0;
		int c = 0;
		switch(tank_->getDirection()) {
			case UP: {
				c = tank_->getX();
				r = tank_->getY() - 1;
				createBullet(r, c,tank_);
				break;
			}
			case DOWN: {
				c = tank_->getX();
				r = tank_->getY() + 1;
				createBullet(r, c, tank_);
				break;
			}
			case LEFT: {
				c = tank_->getX() - 1;
				r = tank_->getY();
				createBullet(r, c, tank_);
				break;
			}
			case RIGHT: {
				c = tank_->getX() + 1;
				r = tank_->getY();
				createBullet(r, c, tank_);
				break;
			}
		}
		
		break;
		}
	}
	double r = 0;
	double c = 0;
	for (int i = 0; i < 1024; i++) {
		if (objects_[i] != 0 && objects_[i]->getSymbol()!=SWALL) {
			switch (objects_[i]->getDirection())
			{
			case UP:{
				c = objects_[i]->getX();
				r = objects_[i]->getY() - 1;
				break;
				}
			case DOWN: {
				c = objects_[i]->getX();
				r = objects_[i]->getY() + 1;
				break;
			}
			case LEFT: {
				c = objects_[i]->getX()-1;
				r = objects_[i]->getY();
				break;
			}
			case RIGHT: {
				c = objects_[i]->getX()+1;
				r = objects_[i]->getY();
				break;
			}
			default:
				break;
			}

			if (conflict(r, c) != false) {
				if (tank_->getX() == c && tank_->getY() == r) {
					if (static_cast<Bullet*>(objects_[i])->getCreatorType() == EnemyType) {
						tank_->setHealth(tank_->getHealth() - 1);
						if (tank_->getHealth() == 0) {
							isGame_ = 0;
							isVictory_ = false;
						}
						objects_[i]->setSymbol(' ');
						gameReder.setGameObject(objects_[i]);
						gameReder.update();
						delete objects_[i];
						objects_[i] = 0;
					}
				}
					else {
						gameReder.setGameObject(objects_[i]);
						gameReder.update();
					}

			}
			else {
				if (objects_[i]->getObjectType() == BulletType) {
					if (objects_[getIndexGameObject(r, c)]->getObjectType() == BreakEallType) {
						
						int index = getIndexGameObject(r, c);
						objects_[index]->setSymbol(' ');
						gameReder.setGameObject(objects_[index]);
						gameReder.update();
						delete objects_[index];
						objects_[index] = 0;
					}else
					if (objects_[getIndexGameObject(r, c)]->getObjectType() == EnemyType) {
						int index = getIndexGameObject(r, c);
						if (static_cast<Bullet*>(objects_[i])->getCreatorType() == EnemyType) {

						}else
						if (static_cast<Bullet*>(objects_[i])->getCreatorType() == PlayerType) {

							objects_[index]->setHealth(objects_[index]->getHealth() - 1);

							if (objects_[index]->getHealth() == 0) {
							objects_[index]->setSymbol(' ');
							gameReder.setGameObject(objects_[index]);
							gameReder.update();
							delete objects_[index];
							objects_[index] = 0;
							kolKilledTanks++;
							if (kolKilledTanks == 4) {
								isVictory_ = true;
								isGame_ = false;
							}
						}
						}
					}
					else
						if (objects_[getIndexGameObject(r, c)]->getObjectType() == GoldType) {
							int index = getIndexGameObject(r, c);
							if (static_cast<Bullet*>(objects_[i])->getCreatorType() == EnemyType) {
								objects_[index]->setSymbol(' ');
								gameReder.setGameObject(objects_[index]);
								gameReder.update();
								delete objects_[index];
								objects_[index] = 0;
								isVictory_ = false;
								isGame_ = false;
							}
						}

					objects_[i]->setSymbol(' ');
					gameReder.setGameObject(objects_[i]);
					gameReder.update();
					delete objects_[i];
					objects_[i] = 0;
				}
			}
		}

	}
	bot();
}

bool Game::conflict(double r, double c) {
		if(getIndexGameObject(r,c)!=1025){
				return false;
			}else
			return true;
}

int Game::getIndexGameObject(int r,int c) {
	for (int i = 0; i < 1024; i++) {
		if (objects_[i] != 0) {
			if (static_cast<int>(objects_[i]->getX()) == c && static_cast<int>(objects_[i]->getY()) == r) {
				return i;
			}
		}
	}
	return 1025;
}

void Game::bot() {

	for (int i = 0; i < 1024; i++) {
		if (objects_[i] != 0 && objects_[i]->getObjectType() == EnemyType) {
			int direction = rand() % 50+1;
			int shot = 0;
			switch (direction)
			{
			case 1: {
				objects_[i]->setDirection(UP);
				if (conflict(objects_[i]->getY() - 1, objects_[i]->getX()) != false) {
					if (tank_->getX() == objects_[i]->getX() && tank_->getY() == objects_[i]->getY() - 1) {
					
					}
					else {
						gameReder.setGameObject(objects_[i]);
						gameReder.update();
					}
				}
				shot = rand() % 4 + 1;
				if (shot == 1){
				createBullet(objects_[i]->getY() - 1, objects_[i]->getX(), objects_[i]);
				}
				break;
			}
			case 2: {
				objects_[i]->setDirection(DOWN);
				if (conflict(objects_[i]->getY() + 1, objects_[i]->getX()) != false) {
					gameReder.setGameObject(objects_[i]);
					gameReder.update();
				}
				shot = rand() % 4 + 1;
				if (shot == 1) {
					createBullet(objects_[i]->getY() + 1,objects_[i]->getX(), objects_[i]);
				}
				break;
			}
			case 3: {
				objects_[i]->setDirection(LEFT);
				int shot = rand() % 4 + 1;
				if (shot == 1) {
					gameReder.setGameObject(objects_[i]);
					gameReder.update();
				}
				shot = rand() % 4 + 1;
				if (shot == 1) {
				createBullet(objects_[i]->getY(), objects_[i]->getX()-1, objects_[i]);
				}
				break;
			}
			case 4: {
				objects_[i]->setDirection(RIGHT);
				if (conflict(objects_[i]->getY() , objects_[i]->getX()+1) != false) {
					gameReder.setGameObject(objects_[i]);
					gameReder.update();
				}
				shot = rand() % 4 + 1;
				if (shot == 1) {
					createBullet(objects_[i]->getY() , objects_[i]->getX()+1,objects_[i]);
				}
				break;
			}
			default:
				break;
			}
		}
	}
}

void Game::render() {
	gameReder.render();
}

bool Game::loop() {

	render();
	update();

	return isGame_;
}
