#include "Snake.h"
#include <iostream>

Snake::Snake() {
	for (int i = 0; i < STARTSIZE; i++) {
		snakePoints.push_back(Point(STARTX - (BLOCKSIZE*i), STARTY));
	}
	rect.w = BLOCKSIZE;
	rect.h = BLOCKSIZE;
	isMoving = false;
	elongate = false;
	dx = 0;
	dy = 0;
}


Snake::~Snake() {
}

void Snake::render(SDL_Renderer *renderer) {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	for (int i = 0; i < snakePoints.size(); i++) {
		rect.x = snakePoints[i].getX();
		rect.y = snakePoints[i].getY();
		SDL_RenderFillRect(renderer, &rect);
	}
}

void Snake::update() {
	if (isMoving) {
		Point first = snakePoints[0];
		Point last = snakePoints[snakePoints.size() - 1];
		Point newFirst = Point(first.getX() + (dx*BLOCKSIZE), first.getY() + (dy*BLOCKSIZE));
		for (int i = snakePoints.size() - 1; i > 0; i--) {
			snakePoints[i].setX(snakePoints[i - 1].getX());
			snakePoints[i].setY(snakePoints[i - 1].getY());
		}
		snakePoints[0] = newFirst;
		if (elongate) {
			snakePoints.push_back(last);
			elongate = false;
		}

		moveTroughWalls();

		if (collision()) {
			isMoving = false;
		}
	}
}

bool Snake::getIsMoving() {
	return isMoving;
}

void Snake::setIsMoving(bool b) {
	isMoving = b;
}

void Snake::handleEvents(SDL_Event *e) {
	switch (e->type) {
	case SDL_KEYDOWN:
		switch (e->key.keysym.sym) {
		case SDLK_UP:
			if (isMoving && dy != 1) {
				dy = -1;
				dx = 0;
			}
			break;
		case SDLK_DOWN:
			if (isMoving && dy != -1) {
				dy = 1;
				dx = 0;
			}
			break;
		case SDLK_LEFT:
			if (isMoving && dx != 1) {
				dx = -1;
				dy = 0;
			}
			break;
		case SDLK_RIGHT:
			if (isMoving && dx != -1) {
				dx = 1;
				dy = 0;
			}
			break;
		case SDLK_SPACE:
			if (isMoving) {
				return;
			}
			else {
				isMoving = true;
				dx = 1;
			}
			break;
		}
		break;
	}
}

void Snake::moveTroughWalls() {
	if (snakePoints[0].getX() > 800-BLOCKSIZE && dx == 1) {
		snakePoints[0].setX(0);
	}
	if (snakePoints[0].getX() < 0 && dx == -1) {
		snakePoints[0].setX(800);
	}
	if (snakePoints[0].getY() > 600 - BLOCKSIZE && dy == 1) {
		snakePoints[0].setY(-BLOCKSIZE);
	}
	if (snakePoints[0].getY() < 0 && dy == -1) {
		snakePoints[0].setY(600);
	}
}

bool Snake::collision() {
	int headX = snakePoints[0].getX() + 3;
	int headY = snakePoints[0].getY() + 3;
	for (int i = 1; i < snakePoints.size(); i++) {
		if (headX >= snakePoints[i].getX() && headY >= snakePoints[i].getY() &&
			headX <= snakePoints[i].getX() + BLOCKSIZE && headY <= snakePoints[i].getY() + BLOCKSIZE) {
			return true;
		}
	}
	return false;
}