#include <gui/containers/Ship.hpp>
#include <gui/Constraint.hpp>
#include <BitmapDatabase.hpp>
#include "cmsis_os.h"

extern osMessageQueueId_t Queue1Handle;

Ship::Ship() {
	Application::getInstance()->registerTimerWidget(this);

	setXY(240 / 2 - getWidth() / 2, 320 - getHeight());
}

void Ship::initialize()
{
    ShipBase::initialize();
}

void Ship::handleTickEvent() {
	tickCounter++;

	switch (state) {
	case ALIVE:
		//Fire bullet every SHIP_BULLET_INTERVAL ticks
		if (tickCounter % SHIP_BULLET_INTERVAL == 0)
			 emitFireBulletTriggerCallback();
		break;
	case IMMUNE:
		if ((tickCounter - 1) % 5 == 0) {
			animatedImage.setAlpha((tickCounter - 1) % 10 == 0 ? 0 : 255);
		}

		if (tickCounter > 100) {
			animatedImage.setAlpha(255);
			setState(ALIVE);
		}
		break;
	case DEAD:
		if (tickCounter == 1) {
			//Start explode animation
			animatedImage.setBitmaps(BITMAP_EXPLOSION00_ID, BITMAP_EXPLOSION07_ID);
			animatedImage.setUpdateTicksInterval(5);
			animatedImage.startAnimation(false, true, false);
		}
		else if (tickCounter == EXPLODE_DURATION)
			//Restart after explode animation end
			reset();
		return;
	default: break;
	}

	uint8_t res = 0;
	if (osMessageQueueGetCount(Queue1Handle) > 0 &&
			osMessageQueueGet(Queue1Handle, &res, NULL, osWaitForever) == osOK) {

		int16_t x = getX(), y = getY();

		switch (res) {
		case 'U': y += SHIP_SPEED; break;		//Move up
		case 'D': y -= SHIP_SPEED; break;		//Move down
		case 'R': x += SHIP_SPEED; break;		//Move right
		case 'L': x -= SHIP_SPEED; break;		//Move left
		default: return;
		}

		//The ship stay in screen
		if (x < 0)
			x = 0;
		else if (x > 240 - getWidth())
			x = 240 - getWidth();

		if (y < 0)
			y = 0;
		else if (y > 320 - getHeight())
			y = 320 - getHeight();

		moveTo(x, y);
		animatedImage.invalidate();
	}
}

void Ship::reset() {
	state = IMMUNE;
	setXY(240 / 2 - getWidth() / 2, 320 - getHeight());
	animatedImage.setBitmaps(BITMAP_SHIP_ID, BITMAP_SHIP_ID);
}

void Ship::setState(State state) {
	this->state = state;
	tickCounter = 0;
}

Ship::State Ship::getState() {
	return state;
}
