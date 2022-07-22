#include <gui/main_screen/mainView.hpp>

mainView::mainView()
	{}

void mainView::setupScreen() {
    mainViewBase::setupScreen();

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
			bulletList[i]->setXY(ship.getX() + ship.getWidth()/2 - bulletList[i]->getWidth()/2, ship.getY());
			//The bullet will travel 320 pixel
			bulletList[i]->startMoveAnimation(bulletList[i]->getX(), -(320 - bulletList[i]->getY()), BULLET_TIME);
		}
	}

	if (tickCount > BULLET_TIME)
		tickCount = 0;
}
