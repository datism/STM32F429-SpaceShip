#include <gui/containers/Enemy.hpp>

Enemy::Enemy(int16_t h)
	:state(OOB), damaged(0), health(h), damagedTick(0) {}

void Enemy::handleDamage(uint16_t damage) {
	health -= damage;
	damaged = 1;

	if (health <= 0)
		setState(DEAD);

}

void Enemy::reset() {
	state = OOB;
	damaged = 0;
	damagedTick = 0;
}

void Enemy::setState(State state) {
    this->state = state;
    tickCounter = 0;
}

Enemy::State Enemy::getState() {
    return state;
}

void Enemy::setStartPos(int16_t x, int16_t y) {
    this->startX = x;
    this->startY = y;
}

void Enemy::setEndPos(int16_t x, int16_t y) {
    this->endX = x;
    this->endY = y;
}

int16_t Enemy::getStartX() {
    return startX;
}

int16_t Enemy::getStartY() {
    return startY;
}

int16_t Enemy::getEndX() {
    return endX;
}

int16_t Enemy::getEndY() {
    return endY;
}
