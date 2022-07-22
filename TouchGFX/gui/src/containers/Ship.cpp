#include <gui/containers/Ship.hpp>
#include "cmsis_os.h"

/* Speed of the ship (pixels/tick)*/
#define SHIP_SPEED 1

extern osMessageQueueId_t Queue1Handle;

Ship::Ship() {
	Application::getInstance()->registerTimerWidget(this);

	setX(240 / 2 - getWidth() / 2);
	setY(320 - getHeight());

	localX = getX();
	localY = getY();
}

void Ship::initialize()
{
    ShipBase::initialize();
}

void Ship::handleTickEvent() {
	uint8_t res = 0;
	if (osMessageQueueGetCount(Queue1Handle) > 0 &&
			osMessageQueueGet(Queue1Handle, &res, NULL, osWaitForever) == osOK) {

		switch (res) {
		case 'U': localY += SHIP_SPEED; break;
		case 'D': localY -= SHIP_SPEED; break;
		case 'R': localX += SHIP_SPEED; break;
		case 'L': localX -= SHIP_SPEED; break;
		}

		if (localX < 0)
			localX = 0;
		else if (localX > 240 - getWidth())
			localX = 240 - getWidth();

		if (localY < 0)
			localY = 0;
		else if (localY > 320 - getHeight())
			localY = 320 - getHeight();

		moveTo(localX, localY);

		animatedImage.invalidate();
	}
}

Rect Ship::getBodyArea() {
	return animatedImage.getRect();
}
