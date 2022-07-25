#include <gui/containers/Ship.hpp>
#include <BitmapDatabase.hpp>
#include "cmsis_os.h"

/* Speed of the ship (pixels/tick)*/
#define SHIP_SPEED 1
#define STARTPOS 240 / 2 - getWidth() / 2, 320 - getHeight()

extern osMessageQueueId_t Queue1Handle;

Ship::Ship() {
	Application::getInstance()->registerTimerWidget(this);

	setXY(STARTPOS);
}

void Ship::initialize()
{
    ShipBase::initialize();
}

void Ship::handleTickEvent() {
	tickCounter++;

	if (state == State::DEAD) {
		if (tickCounter == 1) {
			animatedImage.setBitmaps(BITMAP_EXPLOSION0_ID, BITMAP_EXPLOSION7_ID);
			animatedImage.setUpdateTicksInterval(5);
			animatedImage.startAnimation(false, true, false);
		}
		else if (tickCounter > 30)
			reset();
		return;
	}

	uint8_t res = 0;
	if (osMessageQueueGetCount(Queue1Handle) > 0 &&
			osMessageQueueGet(Queue1Handle, &res, NULL, osWaitForever) == osOK) {

		int16_t x = getX(), y = getY();

		switch (res) {
		case 'U': y += SHIP_SPEED; break;
		case 'D': y -= SHIP_SPEED; break;
		case 'R': x += SHIP_SPEED; break;
		case 'L': x -= SHIP_SPEED; break;
		default: return;
		}

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
	state = ALIVE;
	setXY(STARTPOS);
	animatedImage.setBitmaps(BITMAP_SHIP0_ID, BITMAP_SHIP2_ID);
}

void Ship::setState(State state) {
	this->state = state;
	tickCounter = 0;
}

Ship::State Ship::getState() {
	return state;
}

//Rect Ship::getBodyArea() {
//	return animatedImage.getRect();
//}
