#include "Food.h"

Food::Food() {
	srand(time(NULL));
	FOODSIZE = 8;
	rect.w = FOODSIZE;
	rect.h = FOODSIZE;
	rect.x = randomInt(10, 790);
	rect.y = randomInt(10, 590);
}


Food::~Food()
{
}

void Food::render(SDL_Renderer *renderer) {
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	SDL_RenderFillRect(renderer, &rect);
}

void Food::update(Snake* snake) {
	if (checkCollision(snake)) {
		rect.x = randomInt(10, 790);
		rect.y = randomInt(10, 590);
		snake->setElongate(true);
	}
}

bool Food::checkCollision(Snake* snake) {
	int headX = snake->snakePoints[0].getX() + 3,
		headY = snake->snakePoints[0].getY() + 3,
		foodX = rect.x,
		foodY = rect.y;

	if (headX >= foodX && headY >= foodY &&
		headX <= foodX + FOODSIZE && headY <= foodY + FOODSIZE) {
		return true;
	}
	return false;
}

int Food::randomInt(int min, int max) {
	//srand(time(NULL));
	int num = (rand() % (max-min)) + min;
	return num;
}