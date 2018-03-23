#pragma once
#include "GameObject.h"

class Bullet:public GameObject
{
public:
	Bullet();
	Bullet(int x,int y, Direction direction);
	~Bullet();
	void update();
	void setCreatorType(ObjectType creatorType);
	ObjectType getCreatorType();
private:
	ObjectType creatorType_;
};

