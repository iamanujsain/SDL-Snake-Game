#include "Game.h"
#include "Snake.h"
#include "Food.h"

Snake *snake = new Snake();
Food *food = new Food();

Game::Game() {
	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
}


Game::~Game() {
}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	success = true;
	int flags = SDL_WINDOW_OPENGL;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf("SDL could not be initialized! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else {
		gWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (gWindow == NULL) {
			printf("Window could not be initialized! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else {
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL) {
				printf("Renderer could not be initialized! SDL_Error: %s\n", SDL_GetError());
				success = false;
			}
			else {
				SDL_SetRenderDrawColor(gRenderer, 59, 89, 152, 255);  // The color used for filling up the background.
				SDL_RenderClear(gRenderer);  //	Clears the current rendering target with the drawing colour.
			}
		}
	}
	return success;
}

void Game::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	snake->handleEvents(&event);  // Controls the snake.
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update() {
	snake->update();
	food->update(snake);
}

void Game::render() {
	SDL_SetRenderDrawColor(gRenderer, 59, 89, 152, 255);
	SDL_RenderClear(gRenderer);
	snake->render(gRenderer);
	food->render(gRenderer);
	SDL_RenderPresent(gRenderer);
}

void Game::clean(){
	SDL_Quit();
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gRenderer = NULL;
	gWindow = NULL;
}

bool Game::running() {
	return isRunning;
}
