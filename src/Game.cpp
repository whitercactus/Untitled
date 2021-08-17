#include "include/Game.h"

Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	SDL_CreateWindowAndRenderer(800,600,0,&window,&renderer);
	SDL_SetWindowTitle(window, "Untitled Game");
	isRunning = true;
	count = 0;
	testObj.setDstRect(50,50,75,75);
	testObj.setSrcRect(0,0,75,75);
	testObj.setImg("assets/img/Slime.png", renderer);
	effect.load("assets/sfx/test.wav");
	effect.play();
	player.setImg("assets/img/player.png", renderer);
	player.setDstRect(100,100,47*3,45*3);
	idle = player.createCycle(1,47,43,2,20);
	shield = player.createCycle(2,47,43,4,20);
	player.setAnim(idle);
	loop();
}

Game::~Game() {
	TTF_Quit();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Game::loop() {
	while (isRunning) {
		input();

		lastFrame = SDL_GetTicks();
		static int lastTime;
		if (lastFrame > (lastTime + 1000)) {
			lastTime = lastFrame;
			frameCount = 0;
			count++;
		}
		render();
		update();
	}
}

void Game::render() {
	SDL_SetRenderDrawColor(renderer, 0,0,0,255);
	SDL_Rect rect;
	rect.x = rect.y = 0;

	draw(testObj);
	draw("Test",20,30,0,255,0,24);
	draw(player);

	int timerFPS = SDL_GetTicks()-lastFrame;

	if (timerFPS < (1000/60)) {
		SDL_Delay((1000/60)-timerFPS);
	}

	SDL_RenderPresent(renderer);
}

void Game::draw(GameObject obj) {
	SDL_Rect src = obj.getSrcRect();
	SDL_Rect dst = obj.getDstRect();
	SDL_RenderCopyEx(renderer, obj.getTex(), &src, &dst, 0, NULL, SDL_FLIP_NONE);
}

void Game::draw(const char* msg, int x, int y, int r, int g, int b, int scale) {
	SDL_Surface* surf;
	SDL_Texture* tex;
	TTF_Font* font = TTF_OpenFont("assets/Fonts/Minecraft.ttf",scale);
	SDL_Color color;

	color.r = r;
	color.b = b;
	color.g = g;
	color.a = 255;

	SDL_Rect rect;
	surf = TTF_RenderText_Solid(font, msg, color);
	tex = SDL_CreateTextureFromSurface(renderer, surf);

	rect.x = x;
	rect.y = y;
	rect.w = surf->w;
	rect.h = surf->h;

	SDL_FreeSurface(surf);
	SDL_RenderCopy(renderer, tex, NULL, &rect);
	SDL_DestroyTexture(tex);
	TTF_CloseFont(font);
}

void Game::input() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch(event.type) {
			default:
				break;
			case SDL_QUIT:
				isRunning = false;
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_ESCAPE) {
					isRunning = false;
				}
				if (event.key.keysym.sym == SDLK_w) {
					std::cout << "w down" << std::endl;
					player.setAnim(shield);
				}
			case SDL_KEYUP:
				if (event.key.keysym.sym == SDLK_w) {
					std::cout << "w up" << std::endl;
				}
		}
		SDL_GetMouseState(&mouseX, &mouseY);
	}
}

void Game::update() {
	player.updateAnim();
}
