#include "stdafx.h"
#include "Tank.h"


Tank::Tank()
{
}


Tank::~Tank()
{
}

void Tank::update() {
	switch (direction_)
	{
	case UP: {
		y_ -= shift_;
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