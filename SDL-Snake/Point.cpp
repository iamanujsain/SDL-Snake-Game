#include "Point.h"



Point::Point(int x, int y) {
	this->x = x;
	this->y = y;
}


Point::~Point()
{
}

int Point::getX() {
	return this->x;
}

int Point::getY() {
	return this->y;
}

void Point::setX(int a) {
	this->x = a;
}

void Point::setY(int a) {
	this->y = a;
}