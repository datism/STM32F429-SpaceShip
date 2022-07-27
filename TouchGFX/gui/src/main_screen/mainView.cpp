#include <gui/main_screen/mainView.hpp>
#include <utility>

/* Speed of a bullet (pixels/tick)*/
#define BULLET_SPEED 4
/* Ticks which a bullet take in move aniamtion */
#define BULLET_TIME 320 / BULLET_SPEED
/* Ticks which ship take to fire a bullet */
#define BULLET_INTERVAL (int)(BULLET_TIME / NBR_BULLET)


#define ENEMY_GAP (240 - enemy00.getWidth() * 4) / (4 + 1)
#define ENEMY_LINE3 35
#define ENEMY_LINE2 ENEMY_LINE3 + enemy00.getHeight() + 10
#define ENEMY_LINE1 ENEMY_LINE2 + enemy00.getHeight() + 10
#define STARTY - enemy00.getHeight()


mainView::mainView()
	: state(PHASE1), bulletMoveAnimationEndedCallback(this, &mainView::bulletMoveAnimationEndedHandler)
{

	bullets[0] = &bullet1;
	bullets[1] = &bullet2;
	bullets[2] = &bullet3;
	bullets[3] = &bullet4;
}

void mainView::setupScreen() {
    mainViewBase::setupScreen();
}

void mainView::tearDownScreen() {
    mainViewBase::tearDownScreen();
}

void mainView::handleTickEvent() {
	tickCount++;

	switch (state) {
	case PHASE1:
		//start phase pop up
		if (tickCount == 1)
			setUpPhase1();

		if (enemies.size() == 0 ) {
			setState(PHASE2);
		} else if (tickCount == 1000) {
			//retreat when time run out
			for(uint8_t i = 0; i < enemies.size(); ++i) {
					enemies[i]->setState(Enemy0::RETREAT);
			}
		}
		else if (tickCount == 1100)
			//start phase 2 after retreat
			setState(PHASE2);
		break;
	case PHASE2:
		//disable all bullet and start phase pop up
		if (tickCount == 1) {
			disableBullets();
		}
		//start phase 2
		else if (tickCount == 50)
			setUpPhase2();

		break;
	case PHASE3:
		break;
	}

	checkCollision();
}

void mainView::checkCollision() {
	uint8_t i = 0, j = 0;

	while (i < enemies.size()) {
		//ship not dead && ship intersect enemy
		if (ship.getState() != Ship::DEAD && ship.getRect().intersect(enemies[i]->getHitBox())) {
			ship.setState(Ship::DEAD);
			enemies[i]->setState(Enemy0::DEAD);
			enemies.removeAt(i);
			continue;
		}
		i++;
	}


	for (j = 0; j < NBR_BULLET; ++j) {
		if (bullets[j]->getRect().bottom() < 0 ||  !bullets[j]->isVisible())
			continue;

		for (i = 0; i < enemies.size();) {
			//bullet intersect enemy
			if (bullets[j]->getRect().intersect(enemies[i]->getHitBox())) {
				bullets[j]->setVisible(0);
				enemies[i]->setState(Enemy0::DEAD);
				enemies.removeAt(i);
				continue;
			}

			i++;
		}
	}
}

void mainView::setUpPhase1() {
	enemies.clear();

	enemies.add(&enemy00);
	enemies.add(&enemy01);
	enemies.add(&enemy02);
	enemies.add(&enemy03);

	//line 2, 4 enemy
	for (uint8_t i = 0; i < 4; i++) {
		if (i == 0) {
			enemies[i]->setStartPos(120 - enemy00.getWidth() / 2, -enemy00.getHeight());
			enemies[i]->setEndPos(ENEMY_GAP, ENEMY_LINE2);
		}
		else {
			enemies[i]->setStartPos(enemies[i - 1]->getStartX(), (i >= 2) ?  enemies[3 - i]->getStartY() : enemies[i - 1]->getStartY() - 50 );
			enemies[i]->setEndPos(enemies[i - 1]->getEndX() +  enemy00.getWidth() + ENEMY_GAP , ENEMY_LINE2);
		}

		enemies[i]->setState(Enemy0::ENTER);
	}

	enableBullets();
}

void mainView::setUpPhase2() {
	uint8_t i;
	uint16_t eHeight = enemy00.getHeight();
	uint16_t eWidth = enemy00.getWidth();

	enemies.clear();

	enemies.add(&enemy00);
	enemies.add(&enemy01);
	enemies.add(&enemy02);
	enemies.add(&enemy03);
	enemies.add(&enemy04);
	enemies.add(&enemy05);
	enemies.add(&enemy06);
	enemies.add(&enemy07);
	enemies.add(&enemy08);
	enemies.add(&enemy09);

	//line2, 4 enemy
	for (i = 3; i < 7; i++) {
		if (i == 3) {
			enemies[i]->setStartPos(120 - eWidth, -eHeight * (i + 1));
			enemies[i]->setEndPos(ENEMY_GAP, ENEMY_LINE2);
		}
		else {
			enemies[i]->setStartPos(enemies[i - 1]->getStartX(), -eHeight * i);
			enemies[i]->setEndPos(enemies[i - 1]->getEndX() +  eWidth + ENEMY_GAP, ENEMY_LINE2);
		}
	}

	//line1, 3 enemy
	for (i = 0; i < 3; ++i) {
		enemies[i]->setStartPos(240 - eWidth, -eHeight * (i + 1));
		enemies[i]->setEndPos(enemies[i + 3]->getEndX() + eWidth + 5, ENEMY_LINE1);
	}

	//line3, 3 enemy
	for (i = 7; i < 10; ++i) {
		enemies[i]->setStartPos(0, -eHeight * (i + 1));
		enemies[i]->setEndPos(enemies[i - 7]->getEndX(), ENEMY_LINE3);
	}

	for (i =  0; i < 10; ++i) {
		enemies[i]->setState(Enemy0::ENTER);
	}


	enableBullets();
}


void mainView::disableBullets() {
	for (uint8_t i = 0; i < 4; ++i) {
		bullets[i]->setY(320);
		bullets[i]->cancelMoveAnimation();
	}
}

void mainView::enableBullets() {
	for(uint8_t i = 0; i < NBR_BULLET; ++i) {
		bullets[i]->setVisible(0);
		bullets[i]->setMoveAnimationEndedAction(bulletMoveAnimationEndedCallback);
		bullets[i]->setMoveAnimationDelay(i * BULLET_INTERVAL);
		//The bullet will travel 320 pixel
		bullets[i]->startMoveAnimation(bullets[i]->getX(), -(320 - bullets[i]->getY()), BULLET_TIME);
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

void mainView::setState(State state) {
	this->state = state;
	tickCount = 0;
}
