#pragma once

#include <SDL/SDL.h>
#include <stdio.h>

class Game
{
public:
	Game();
	~Game();

	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void clean();
	bool running();
	void setIsRunning(bool b) {
		isRunning = b;
	}

private:
	bool success;
	bool isRunning;
	SDL_Window *gWindow = NULL;
	SDL_Renderer *gRenderer = NULL;
};

