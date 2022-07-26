#include <gui/containers/Enemy0.hpp>
#include <BitmapDatabase.hpp>



Enemy0::Enemy0()
	:state(OOB) {
	Application::getInstance()->registerTimerWidget(this);
}

void Enemy0::initialize()
{
    Enemy0Base::initialize();
}

void Enemy0::handleTickEvent() {
	tickCounter++;
	MoveAnimator<Enemy0Base>::handleTickEvent();

	switch(state) {
	case ENTER:
		if (tickCounter == 1) {
			//move to outside screen
			moveTo(startPosX, startPosY);
			//move to standing position
			startMoveAnimation(enterPosX, enterPosY, 100, EasingEquations::cubicEaseOut, EasingEquations::expoEaseOut);
		}
		break;
	case RETREAT:
		if (tickCounter == 1)
			//go straight up
			startMoveAnimation(getX(), -getHeight(), 100);
		break;
	case DEAD:
		if (tickCounter == 1) {
			animatedImage.setBitmaps(BITMAP_EXPLOSION0_ID, BITMAP_EXPLOSION7_ID);
			animatedImage.setUpdateTicksInterval(5);
			animatedImage.startAnimation(false, true, false);
			cancelMoveAnimation();
		}
		else if (tickCounter > 40)
			reset();
		break;
	default: break;
	}
}

void Enemy0::reset() {
	state = OOB;
	animatedImage.setBitmaps(BITMAP_ENEMY0_ID, BITMAP_ENEMY0_ID);
	moveTo(startPosX, startPosY);
}

void Enemy0::setStartPos(int16_t x, int16_t y) {
	startPosX = x;
	startPosY = y;

	if (startPosY == 0) {
		startPosY = 1;
	}
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
