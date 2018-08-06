#pragma once

#include <SDL/SDL_ttf.h>
#include "Snake.h"
#include <time.h>
#include <random>
#include <SDL/SDL.h>
#include <stdlib.h>

class Food
{
public:
	Food();
	~Food();

	void render(SDL_Renderer *renderer);
	void update(Snake* snake);
	bool checkCollision(Snake* snake);
	int randomInt(int min, int max);

	void setScore(int s);
	int getScore();

	//void drawText(SDL_Renderer * renderer, char *text, int x, int y, int width, int height);
	
	void printScore();

private:
	SDL_Rect rect;
	int FOODSIZE,
		score;
};

