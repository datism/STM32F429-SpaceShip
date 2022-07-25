#include <gui/main_screen/mainView.hpp>
#include <utility>

/* Speed of a bullet (pixels/tick)*/
#define BULLET_SPEED 4
/* Ticks which a bullet take in move aniamtion */
#define BULLET_TIME 320 / BULLET_SPEED
/* Ticks which ship take to fire a bullet */
#define INTERVAL_BULLET (int)(BULLET_TIME / NBR_BULLET)


mainView::mainView()
	:bulletMoveAnimationEndedCallback(this, &mainView::bulletMoveAnimationEndedHandler)
{
    bullets[0] = &bullet1;
    bullets[1] = &bullet2;
    bullets[2] = &bullet3;
    bullets[3] = &bullet4;

    enemies0[0] = &enemy00;
    enemies0[1] = &enemy01;
    enemies0[2] = &enemy02;
    enemies0[3] = &enemy03;
    enemies0[4] = &enemy04;
    enemies0[5] = &enemy05;
    enemies0[6] = &enemy06;
    enemies0[7] = &enemy07;
    enemies0[8] = &enemy08;
    enemies0[9] = &enemy09;
}

void mainView::setupScreen() {
    mainViewBase::setupScreen();

    uint8_t i;
    uint16_t gap = (240 - enemy00.getWidth() * 4) / (4 + 1);
    uint16_t line3 = 35;
    uint16_t line2 = line3 + enemy00.getHeight() + 10;
    uint16_t line1 = line2 + enemy00.getHeight() + 10;
    int16_t startY = -enemy00.getHeight();


    for (i = 3; i < 7 ; i++) {
    	if (i == 3) {
			enemies0[i]->centerX();
			enemies0[i]->setStartPos(enemies0[i]->getX(), startY);
			enemies0[i]->setEnterPos(gap, line2);
    	}
    	else {
    		enemies0[i]->setStartPos(enemies0[i - 1]->getStartX(), startY);
    		enemies0[i]->setEnterPos(enemies0[i - 1]->getEnterX() +  enemy00.getWidth() + gap , line2);
    	}

    }

    for (i = 0; i < 3; i++) {
    	enemies0[i]->setStartPos(320 - enemy00.getWidth(), startY);
    	enemies0[i]->setEnterPos(enemies0[i + 3]->getEnterX() + enemy00.getWidth(), line1);
    }

    for (i = 7; i < 10 ;i++) {
		enemies0[i]->setStartPos(0, startY);
		enemies0[i]->setEnterPos(enemies0[i - 7]->getEnterX(), line3);
    }

    for (i = 0; i < NBR_ENEMY0; i++) {
    	 enemies0[i]->startMoveAnimation(enemies0[i]->getEnterX(), enemies0[i]->getEnterY(), 100, EasingEquations::cubicEaseOut, EasingEquations::expoEaseOut);
    	 enemies0[i]->setMoveAnimationDelay(i * 10);
    }

    for(i = 0; i < NBR_BULLET; ++i) {
    	bullets[i]->setVisible(0);
		bullets[i]->setMoveAnimationEndedAction(bulletMoveAnimationEndedCallback);
    }

}

void mainView::tearDownScreen() {
    mainViewBase::tearDownScreen();
}

void mainView::handleTickEvent() {
	tickCount++;

	if (tickCount == 1) {
		for (uint8_t i = 0; i < NBR_BULLET; ++i) {
			bullets[i]->setMoveAnimationDelay(i * INTERVAL_BULLET);
			//The bullet will travel 320 pixel
			bullets[i]->startMoveAnimation(bullets[i]->getX(), -(320 - bullets[i]->getY()), BULLET_TIME);

		}
	}

	checkCollision();
}

void mainView::checkCollision() {
	uint8_t i, j;

	for (i = 0; i < NBR_ENEMY0; ++i) {
		//enemy not in screen || enemy is dead
		if (enemies0[i]->getRect().bottom() < 0 || enemies0[i]->getState() == Enemy0::DEAD)
			continue;

		//ship not dead && ship intersect enemy
		if (ship.getState() != Ship::DEAD && ship.getRect().intersect(enemies0[i]->getRect())) {
			ship.setState(Ship::DEAD);
			enemies0[i]->setState(Enemy0::DEAD);
			continue;
		}

		for (j = 0; j < NBR_BULLET; ++j) {
			if (bullets[j]->getRect().bottom() > 0									//bullet in screen
					&& bullets[j]->isVisible()										//bullet is visible
					&& bullets[j]->getRect().intersect(enemies0[i]->getRect())) 	//bullet intersect enemy
			{
				enemies0[i]->setState(Enemy0::DEAD);
			}
		}
	}
}

void mainView::bulletMoveAnimationEndedHandler(const touchgfx::MoveAnimator<touchgfx::Image>& comp) {
	for (uint8_t i = 0; i < NBR_BULLET; ++i) {
		if (bullets[i] == &comp) {
			bullets[i]->setVisible(1);
		 	//Set the bullet middle of the ship
			bullets[i]->setXY(ship.getX() + ship.getWidth()/2 - bullets[i]->getWidth()/2, ship.getY());
			bullets[i]->setMoveAnimationDelay(0);
			bullets[i]->startMoveAnimation(bullets[i]->getX(), -(320 - bullets[i]->getY()), BULLET_TIME);
			return;
		}
	}
}
