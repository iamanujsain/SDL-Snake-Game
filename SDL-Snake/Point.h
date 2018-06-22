#pragma once
class Point
{
public:
	Point(int x, int y);
	~Point();

	void setX(int a);
	void setY(int b);
	int getX();
	int getY();
private:
	int x, y;
};