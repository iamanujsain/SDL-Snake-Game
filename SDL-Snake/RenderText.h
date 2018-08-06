#pragma once

#include <SDL/SDL_ttf.h>
#include <SDL/SDL.h>
#include <string>

class RenderText
{
public:
	RenderText(
		TTF_Font *font,
		SDL_Color *color,
		SDL_Renderer *renderer,
		std::string message,
		int x,
		int y,
		int width,
		int height);
	~RenderText();

private:

};

