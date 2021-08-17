#include "include/Entity.h"

Entity::Entity() {

}

Entity::~Entity() {

}

int Entity::createCycle(int r, int w, int h, int amount, int speed) {
	Cycle tmp;
	tmp.row = r-1;
	tmp.w = w;
	tmp.h = h;
	tmp.amount = amount;
	tmp.speed = speed;
	anims.push_back(tmp);
	return anims.size()-1;
}

void Entity::updateAnim() {
	setSrcRect(anims[currentAnim].w*anims[currentAnim].tick,anims[currentAnim].row*anims[currentAnim].h,
		anims[currentAnim].w,anims[currentAnim].h);
	if (anims[currentAnim].speed >= anims[currentAnim].tick) {
		anims[currentAnim].tick++;
		begin = 0;
	}
	begin++;
	if (anims[currentAnim].tick >= anims[currentAnim].amount) {
		anims[currentAnim].tick = 0;
	}
}
