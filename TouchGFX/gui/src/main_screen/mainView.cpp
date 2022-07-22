#include <gui/main_screen/mainView.hpp>
#include <BitmapDatabase.hpp>
#include "cmsis_os.h"

extern osMessageQueueId_t Queue1Handle;

mainView::mainView()
	{}

void mainView::setupScreen() {
	localImgX = 240 / 2 - ship.getWidth() / 2;
	localImgY = 320 - ship.getHeight();

    mainViewBase::setupScreen();

    ship.setX(localImgX);
    ship.setY(localImgY);

    bulletList[0] = &bullet1;
    bulletList[1] = &bullet2;
    bulletList[2] = &bullet3;
    bulletList[3] = &bullet4;
}

void mainView::tearDownScreen() {
    mainViewBase::tearDownScreen();
}

void mainView::handleTickEvent() {
	tickCount++;

	if (tickCount % INTERVAL_BULLET == 0) {
		uint8_t i = tickCount / INTERVAL_BULLET - 1;

		if (!bulletList[i]->isMoveAnimationRunning()) {
			//Set the bullet middle of the ship
			bulletList[i]->setXY(localImgX + ship.getWidth()/2 - bulletList[i]->getWidth()/2, localImgY);
			//The bullet will travel 320 pixel
			bulletList[i]->startMoveAnimation(bulletList[i]->getX(), -(320 - bulletList[i]->getY()), BULLET_TIME);
		}
	}

	if (tickCount > BULLET_TIME)
		tickCount = 0;


	uint8_t res = 0;
	if (osMessageQueueGetCount(Queue1Handle) > 0 &&
			osMessageQueueGet(Queue1Handle, &res, NULL, osWaitForever) == osOK) {

		switch (res) {
		case 'U': localImgY += SHIP_SPEED; break;
		case 'D': localImgY -= SHIP_SPEED; break;
		case 'R': localImgX += SHIP_SPEED; break;
		case 'L': localImgX -= SHIP_SPEED; break;
		}

		if (localImgX < 0)
			localImgX = 0;
		else if (localImgX > 240 - ship.getWidth())
			localImgX = 240 - ship.getWidth();

		if (localImgY < 0)
			localImgY = 0;
		else if (localImgY > 320 - ship.getHeight())
			localImgY = 320 - ship.getHeight();

		ship.moveTo(localImgX, localImgY);

		ship.invalidate();
	}
}
