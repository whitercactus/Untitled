#pragma once

#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "GameObject.h"
#include "Audio.h"
#include "Perlin.h"
#include "Entity.h"

class Game {
public:
	Game();
	~Game();

	void loop();
	void update();
	void input();
	void render();
	void draw(GameObject obj);
	void draw(const char* msg, int x, int y, int r, int g, int b, int scale);

private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	bool isRunning;
	int count;
	int frameCount, frameFPS, lastFrame;
	int mouseX, mouseY;
	int idle, shield;

	GameObject testObj;
	Entity player;
	Audio effect;
};
