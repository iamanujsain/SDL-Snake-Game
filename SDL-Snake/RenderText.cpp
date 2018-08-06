#include "RenderText.h"

RenderText::RenderText(TTF_Font *font, SDL_Color *color, SDL_Renderer *renderer, std::string message,int x, int y, int width, int height) {
	SDL_Rect message_rect;
	message_rect.x = x;
	message_rect.y = y;
	message_rect.w = width;
	message_rect.h = height;

	SDL_Surface *surfaceMessage = TTF_RenderText_Solid(font, message.c_str(), *color);
	SDL_Texture *textureMessage = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	SDL_FreeSurface(surfaceMessage);

	SDL_RenderCopy(renderer, textureMessage, NULL, &message_rect);
}

RenderText::~RenderText() {
}
