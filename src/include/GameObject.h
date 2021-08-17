#pragma once

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

class GameObject
{
public:
	GameObject();
	~GameObject();

	SDL_Rect getDstRect() const { return dst; }
	SDL_Rect getSrcRect() const { return src; }
	SDL_Texture* getTex() const { return tex; }
	void setDstRect(int x, int y, int w, int h);
	void setSrcRect(int x, int y, int w, int h);
	void setImg(const char* path, SDL_Renderer* renderer);
	
private:
	SDL_Rect src;
	SDL_Rect dst;
	SDL_Texture* tex;
};
