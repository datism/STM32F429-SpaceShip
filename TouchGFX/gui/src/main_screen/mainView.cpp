#include <gui/main_screen/mainView.hpp>
#include <BitmapDatabase.hpp>
#include "cmsis_os.h"

extern osMessageQueueId_t Queue1Handle;

mainView::mainView()
	: bulletMoveAnimationEndedCallback(this, &mainView::bulletMoveAnimationEndedHandler)
	{}

void mainView::setupScreen()
{
	localImgX = 240 / 2 - ship.getWidth() / 2;
	localImgY = 320 - ship.getHeight();

    mainViewBase::setupScreen();

    ship.setX(localImgX);
    ship.setY(localImgY);

    bullet1.setMoveAnimationEndedAction(bulletMoveAnimationEndedCallback);
    bullet2.setMoveAnimationEndedAction(bulletMoveAnimationEndedCallback);
    bullet3.setMoveAnimationEndedAction(bulletMoveAnimationEndedCallback);
}

void mainView::tearDownScreen()
{
    mainViewBase::tearDownScreen();
}

void mainView::handleTickEvent() {
	tickCount++;

	if (tickCount == 5) {
		bullet1.setXY(ship.getX() + ship.getWidth() / 2 - bullet1.getWidth() / 2,
				 ship.getY() - bullet1.getHeight());
		bullet1.startMoveAnimation(bullet1.getX(), 0 - bullet1.getY(), 200);
		bullet1.invalidate();
	}


	uint8_t res = 0;
	if (osMessageQueueGetCount(Queue1Handle) > 0 &&
			osMessageQueueGet(Queue1Handle, &res, NULL, osWaitForever) == osOK) {

		switch (res) {
		case 'U': localImgY += 2; break;
		case 'D': localImgY -= 2; break;
		case 'R': localImgX += 2; break;
		case 'L': localImgX -= 2; break;
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

void mainView::bulletMoveAnimationEndedHandler(const touchgfx::MoveAnimator<touchgfx::Image>& bullet) {
	touchgfx::MoveAnimator<touchgfx::Image> *b;

	if (&bullet == &bullet1) {
		b = &bullet1;
	}

	b->setXY(ship.getX() + ship.getWidth() / 2 - b->getWidth() / 2,
					 ship.getY() - b->getHeight());
	b->startMoveAnimation(b->getX(), 0 - b->getY(), 200);
	b->invalidate();
}
