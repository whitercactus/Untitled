#include "include/GameObject.h"

GameObject::GameObject() {

}

GameObject::~GameObject() {

}

void GameObject::setDstRect(int x, int y, int w, int h) {
	dst.x = x;
	dst.y = y;
	dst.w = w;
	dst.h = h;
}

void GameObject::setSrcRect(int x, int y, int w, int h) {
	src.x = x;
	src.y = y;
	src.w = w;
	src.h = h;
}

void GameObject::setImg(const char* path, SDL_Renderer* renderer) {
	SDL_Surface* surf = IMG_Load(path);
	tex = SDL_CreateTextureFromSurface(renderer, surf);
}
