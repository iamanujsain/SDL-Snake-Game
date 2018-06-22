#include <stdio.h>
#include <iostream>
#include "Game.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

Game *game = NULL;

int main(int argc, char** argv) {

	const int FPS = 33;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	game = new Game();
	if (!game->init("Snake Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, false)) {
		printf("Failed to initialize!\n");
		game->setIsRunning(false);
	}
	else {
		game->setIsRunning(true);
		while (game->running()) {

			frameStart = SDL_GetTicks();

			game->handleEvents();
			game->render();
			game->update();

			frameTime = SDL_GetTicks() - frameStart;

			if (frameDelay > frameTime) {
				SDL_Delay(frameDelay - frameTime);
			}
		}
		game->clean();
	}
	system("pause");
	return 0;
}