#include <gui/containers/Enemy0.hpp>
#include <BitmapDatabase.hpp>

#define EXPLO_PDURATION 40

Enemy0::Enemy0()
	:state(ALIVE) {
	Application::getInstance()->registerTimerWidget(this);
}

void Enemy0::initialize()
{
    Enemy0Base::initialize();
}

void Enemy0::handleTickEvent() {
	tickCounter++;
	MoveAnimator<Enemy0Base>::handleTickEvent();

	if (state == State::DEAD) {
		if (tickCounter == 1) {
			animatedImage.setBitmaps(BITMAP_EXPLOSION0_ID, BITMAP_EXPLOSION7_ID);
			animatedImage.setUpdateTicksInterval(5);
			animatedImage.startAnimation(false, true, false);
			cancelMoveAnimation();
		}
		else if (tickCounter > 30)
			reset();
	}
}

void Enemy0::reset() {
	state = ALIVE;
	moveTo(startPosX, startPosY);
	animatedImage.setBitmaps(BITMAP_ENEMY0_ID, BITMAP_ENEMY0_ID);
}


void Enemy0::setStartPos(int16_t x, int16_t y) {
	startPosX = x;
	startPosY = y;
}

void Enemy0::setEnterPos(int16_t x, int16_t y) {
	enterPosX = x;
	enterPosY = y;
}

int16_t Enemy0::getStartX() {
	return startPosX;
}

int16_t Enemy0::getStartY() {
	return startPosY;
}

int16_t Enemy0::getEnterX() {
	return enterPosX;
}

int16_t Enemy0::getEnterY() {
	return enterPosY;
}

void Enemy0::setState(State state) {
	tickCounter = 0;
	this->state = state;

}

Enemy0::State Enemy0::getState() {
	return state;
}