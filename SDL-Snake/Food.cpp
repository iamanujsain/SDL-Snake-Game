#include "Food.h"

Food::Food() {
	srand(time(NULL));
	score = 0;
	FOODSIZE = 8;
	rect.w = FOODSIZE;
	rect.h = FOODSIZE;
	rect.x = randomInt(10, 790);
	rect.y = randomInt(10, 590);

	system("Color 1A");
	printScore();
}


Food::~Food()
{
}

void Food::render(SDL_Renderer *renderer) {
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	SDL_RenderFillRect(renderer, &rect);

	/*char c[] = "Hello";
	drawText(renderer, c, 500, 500, 100, 10);*/
}

void Food::update(Snake* snake) {
	if (checkCollision(snake)) {
		score++;
		printScore();
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

void Food::setScore(int s) {
	score = s;
}

int Food::getScore() {
	return score;
}




//void Food::drawText(SDL_Renderer *renderer, char *text, int x, int y, int width, int height) {
//	if (TTF_Init() == -1) {
//		printf("Couldn't initialize TTF!\n");
//	};
//	TTF_Font *font = TTF_OpenFont("Sans.ttf", 24);
//	SDL_Color white = { 0, 255, 0, 0};
//	SDL_Surface *surfaceMessage = TTF_RenderText_Solid(font, text, white);
//	SDL_Texture *message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
//	SDL_FreeSurface(surfaceMessage);
//	SDL_Rect message_rect;
//	message_rect.x = x;
//	message_rect.y = y;
//	message_rect.w = width;
//	message_rect.h = height;
//
//	SDL_RenderCopy(renderer, message, NULL, &message_rect);
//}




/**
	I'm not being able to make the SDL_ttf work. So, I'm printing the score on the console.
*/
void Food::printScore() {
	system("cls");
	printf("\n\tScore: %d\n\n", score);
}