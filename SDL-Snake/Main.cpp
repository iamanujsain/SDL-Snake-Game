#include <stdio.h>
#include <iostream>
#include "Game.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

Game *game = NULL;

int main(int argc, char** argv) {
	game = new Game();
	if (!game->init("Snake Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, false)) {
		printf("Failed to initialize!\n");
		game->setIsRunning(false);
	}
	else {
		game->setIsRunning(true);
		while (game->running()) {
			game->handleEvents();
			game->render();
			game->update();
		}
		game->clean();
	}
	system("pause");
	return 0;
}