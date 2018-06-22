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
	void handleEvents(SDL_Event *e);

	void setIsMoving(bool b);
	bool getIsMoving();

	std::vector<Point> snakePoints;

private:
	const int 
		STARTSIZE = 17, 
		BLOCKSIZE = 7, 
		STARTX = 200, 
		STARTY = 200;
	SDL_Rect rect;
	bool isMoving, elongate;
	int dx, dy;
	void moveTroughWalls();
	bool collision();
};

