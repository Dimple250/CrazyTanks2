#pragma once
//#include "level.h"
#include "Tank.h"
#include "Bullet.h"
#include "Wall.h"
#include"BreakWall.h"
#include<Windows.h>
#include "GameObject.h"
#include "GameRender.h"

class Game
{
public:
	Game();
	~Game();

	void init();
	bool loop();

	bool isVictory_;

private:
	void update();
	void render();
	bool conflict(double r, double c);
	int getIndexGameObject(int r, int c);
	void bot();
	void createBullet(int r, int c,GameObject* gameObject);

	HANDLE console_;
	bool isGame_;
	
	GameObject* tank_;
	GameObject* objects_[1024];
	GameRender gameReder;
	int kolKilledTanks;
	//GameObject ff;
};

