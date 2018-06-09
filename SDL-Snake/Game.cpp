#include "Game.h"



Game::Game()
{
}


Game::~Game()
{
}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	success = true;
	int flags = 0;
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
				SDL_SetRenderDrawColor(gRenderer, 59, 89, 152, 255);
			}
		}
	}
	return success;
}

void Game::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update() {

}

void Game::render() {
	SDL_RenderClear(gRenderer);

	SDL_RenderPresent(gRenderer);
}

void Game::clean(){
	SDL_Quit();
	gRenderer = NULL;
	gWindow = NULL;
}

bool Game::running() {
	return isRunning;
}
