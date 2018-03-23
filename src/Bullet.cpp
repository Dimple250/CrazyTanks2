#include "stdafx.h"
#include "Bullet.h"
#include<iostream>


Bullet::Bullet()
{
}

Bullet::Bullet(int x, int y, Direction direction)
{
	this->x_ = x;
	this->y_ = y;
	this->direction_ = direction;
	this->symbol_ = '*';
}

Bullet::~Bullet()
{
}

void Bullet::update() {
	switch (direction_)
	{
	case UP: {
		y_ -=shift_;
		break;
	}
	case DOWN: {
		y_ += shift_;
		break;
	}
	case LEFT: {
		x_ -= shift_;
		break;
	}
	case RIGHT: {
		x_ += shift_;
		break;
	}
	default:
		break;
	}
}

void Bullet::setCreatorType(ObjectType creatorType) {
	creatorType_ = creatorType;
}

ObjectType Bullet::getCreatorType(){
	return  creatorType_;
}
