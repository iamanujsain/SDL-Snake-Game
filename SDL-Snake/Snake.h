#pragma once
#include <vector>
#include <SDL/SDL.h>
#include "Point.h"

class Snake
{
public:
	Snake();
	~Snake();

	void render(SDL_Renderer *renderer);
	void update();
	//void handleEvents(SDL_Event *e);

	void setIsMoving(bool b);
	bool getIsMoving();
	int getDx();
	int getDy();
	void setDx(int input);
	void setDy(int input);


	std::vector<Point> snakePoints;

	void setElongate(bool b);
	void reset();

private:
	const int 
		STARTSIZE = 7, 
		BLOCKSIZE = 7, 
		STARTX = 200, 
		STARTY = 200;
	SDL_Rect rect;
	bool isMoving, elongate;
	int dx, dy;
	void moveTroughWalls();
	bool collision();
};

