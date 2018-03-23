#ifndef GAEMRENDER_H
#define GAEMRENDER_H

#include "GameObject.h" 
#include "level.h"

; class GameRender
{
public:
	GameRender();
	~GameRender();
	void setGameObject(GameObject* gameObject);
	void initMap();
	void update();
	void render();

private:
	GameObject* gameObject_;
	unsigned char levelData_[LEVELROWS][LEVELCOLS + 1];
};

#endif /*GAEMRENDERL_H */