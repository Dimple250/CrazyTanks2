#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Direction.h";
#include "ObjectType.h"

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();
	virtual void update()=0;

	void setX(double x);
	double getX();
	void setY(double y);
	double getY();
	void setHealth(int y);
	int getHealth();
	void setShift(double y);
	double getShift();
	void setSymbol(char symbol);
	char getSymbol();
	 void setDirection(Direction direction);
	 Direction getDirection();
	 void setObjectType(ObjectType objectType);
	 ObjectType getObjectType();

protected:
	double x_;
	double y_;
	double shift_;
	char symbol_;
	int health_;
	Direction direction_;
	ObjectType objectType_;
};

#endif /*GAMEOBJECT_H */

