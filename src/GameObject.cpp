#include "stdafx.h"
#include "GameObject.h"


GameObject::GameObject() :
	x_(0),
	y_(0),
	symbol_(' '),
	direction_(UP),
	shift_(1),
	health_(0)
{
}


GameObject::~GameObject()
{
}

void GameObject::setX(double x) {
	this->x_ = x;
}

void GameObject::setY(double y) {
	this->y_ = y;
}

double GameObject::getX() {
	return x_;
}

double GameObject::getY() { 
	return y_; 
}

void GameObject::setSymbol(char symbol) {
	this->symbol_ = symbol;
}

char GameObject::getSymbol() {
	return symbol_;
}

void GameObject::setDirection(Direction direction) {
	this->direction_ = direction;
}

Direction GameObject::getDirection() {
	return direction_;
}

void GameObject::setShift(double shift) {
	this->shift_ = shift;
}

double GameObject::getShift() {
	return shift_;
}

void GameObject::setObjectType(ObjectType objectType) {
	this->objectType_ = objectType;
}

ObjectType GameObject::getObjectType() {
	return objectType_;
}

void GameObject::setHealth(int health) {
	health_ = health;
}

int GameObject::getHealth() {
	return health_;
}