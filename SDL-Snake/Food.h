#pragma once

#include "Snake.h"
#include <time.h>
#include <random>
#include <SDL/SDL.h>

class Food
{
public:
	Food();
	~Food();

	void render(SDL_Renderer *renderer);
	void update(Snake* snake);
	bool checkCollision(Snake* snake);
	int randomInt(int min, int max);

private:
	SDL_Rect rect;
	int FOODSIZE;
};

