#pragma once

#include <iostream>
#include "vector"
#include "SDL2/SDL.h"
#include "GameObject.h"

class Entity : public GameObject
{
public:
	Entity();
	~Entity();

	void setHealth(int health) { this->health = health; }
	void setMaxHealth(int health) { maxHealth = health; }
	int getHealth() const { return health; }
	int getMaxHealth() const { return maxHealth; }
	int createCycle(int r, int w, int h, int amount, int speed);
	void setAnim(int c) { begin = 0; currentAnim = c; }
	void updateAnim();
	
private:
	int health, maxHealth;
	struct Cycle {
		int row;
		int w, h;
		int amount;
		int speed;
		int tick;
	};
	std::vector<Cycle> anims;
	int currentAnim;
	int begin;
};
