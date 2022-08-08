#include <gui/main_screen/mainView.hpp>

mainView::mainView()
	: state(PHASE1)
{

	shipBullets[0] = &shipBullet0;
	shipBullets[1] = &shipBullet1;
	shipBullets[2] = &shipBullet2;
	shipBullets[3] = &shipBullet3;

	enemies[0] = &enemy00;
	enemies[1] = &enemy01;
	enemies[2] = &enemy02;
	enemies[3] = &enemy03;
	enemies[4] = &enemy04;
	enemies[5] = &enemy05;
	enemies[6] = &enemy06;
	enemies[7] = &enemy07;
	enemies[8] = &enemy08;
	enemies[9] = &enemy09;
	enemies[10] = &enemy10;
	enemies[11] = &enemy11;
	enemies[12] = &boss;

	enemyBullets[0] = &enemy10Bullet;
	enemyBullets[1] = &enemy11Bullet;
	enemyBullets[2] = &bossBullet00;
	enemyBullets[3] = &bossBullet01;
	enemyBullets[4] = &bossBullet10;
	enemyBullets[5] = &bossBullet11;
	enemyBullets[6] = &bossBullet12;
	enemyBullets[7] = &bossBullet13;
}

void mainView::setupScreen() {
    mainViewBase::setupScreen();
}

void mainView::tearDownScreen() {
    mainViewBase::tearDownScreen();
}

void mainView::handleTickEvent() {
	tickCount++;

	checkCollision();

	switch (state) {
	case PHASE1:
		//start phase pop up
		if (tickCount == 1) {
			setUpPhase1();
			ship.setState(Ship::IMMUNE);
		}
		else if (enemyCount == 0) {
			//start phase 2 if there arent any enemies left
			setState(PHASE2);
		}
		else if (tickCount == 100) {
			//enmy10 fly right to left
			enemy10.setStartPos(240, ENEMY_LINE4);
			enemy10.setDirection(-1);
			enemy10.setState(Enemy::ENTER);
		}
		else if (tickCount == 800) {
			//remains enemy go straight up
			for(uint8_t i = 0; i < NBR_ENEMY; ++i) {
				if(enemies[i]->getState() == Enemy::ENTER) {
					enemies[i]->setState(Enemy::RETREAT);
				}
			}
		}
		else if (tickCount == 800 + ENEMY0_MOVE_DURATION) {
			//start phase 2 after retreat
			setState(PHASE2);
		}

		break;
	case PHASE2:
		//start phase pop up
		if (tickCount == 1) {
			cancelShipBullet();
			setUpPhase2();
			ship.setState(Ship::IMMUNE);
		}
		else if (enemyCount == 0) {
			//start phase 3 if there arent any enemies left
			setState(PHASE3);
		}
		else if (tickCount % 500 == 0) {

			//enmy10 fly right to left
			enemy10.setStartPos(240, ENEMY_LINE4);
			enemy10.setDirection(-1);
			enemy10.setState(Enemy::ENTER);
		}
		else if (tickCount % 650 == 0) {
			//enmy11 fly left to right
			enemy11.setStartPos(0 - enemy11.getWidth(), ENEMY_LINE4);
			enemy11.setDirection(1);
			enemy11.setState(Enemy::ENTER);
		}
		else if (tickCount == 1200) {
			//remains enemy go straight down
			for(uint8_t i = 0; i < NBR_ENEMY; ++i) {
				if(enemies[i]->getState() == Enemy::ENTER)
					enemies[i]->setState(Enemy::ATTACK);
			}
		}
		else if (tickCount == 1200 + ENEMY0_MOVE_DURATION * 2) {
			//start phase 3 after attack
			setState(PHASE3);
		}

		break;
	case PHASE3:
		//start phase pop up
		if (tickCount == 1) {
			cancelShipBullet();
			setUpPhase3();
			ship.setState(Ship::IMMUNE);
		}
		else if (tickCount % 500 == 0) {
			//enem10 fly right to left every 900 tick
			enemy10.setStartPos(240, ENEMY_LINE4);
			enemy10.setDirection(-1);
			enemy10.setState(Enemy::ENTER);
		}
		break;
	}
}

void mainView::checkCollision() {
	uint8_t i = 0, j = 0;

	//Check if enemy bullet hit ship
	if (ship.getState() == Ship::ALIVE) {
		for (i = 0; i < NBR_ENEMY_BULLET; ++i) {
			if (enemyBullets[i]->getX() < 240 && enemyBullets[i]->isVisible()
					&& enemyBullets[i]->getRect().intersect(ship.getRect())) {
				ship.setState(Ship::DEAD);
				enemyBullets[i]->setVisible(0);
				break;
			}
		}
	}

	//Check enemy and ship collision
	if (ship.getState() == Ship::ALIVE) {
		for (i = 0; i < NBR_ENEMY; ++i) {
			if (enemies[i]->getState() == Enemy::OOB || enemies[i]->getState() == Enemy::DEAD)
				continue;
			//ship intersect enemy
			if (ship.getRect().intersect(enemies[i]->getHitBox())) {
				ship.setState(Ship::DEAD);
				enemies[i]->setState(Enemy0::DEAD);
				break;
			}
		}
	}

	//Check if ship bullet hit enemy, count alive, in screen enemy
	enemyCount = NBR_ENEMY;
	for (i = 0; i < NBR_ENEMY; ++i) {
		if (enemies[i]->getState() == Enemy::OOB || enemies[i]->getState() == Enemy::DEAD) {
			--enemyCount;
			continue;
		}

		for (j = 0; j < NBR_SHIP_BULLET; ++j) {
			if (shipBullets[j]->getRect().bottom() < 0 ||  !shipBullets[j]->isVisible())
				continue;
			//bullet intersect enemy
			if (shipBullets[j]->getRect().intersect(enemies[i]->getHitBox())) {
				shipBullets[j]->setVisible(0);
				enemies[i]->handleDamage(1);
//				enemies[i]->setState(Enemy0::DEAD);
//				--enemyCount;
				break;
			}
		}
	}
}

void mainView::setUpPhase1() {
	//line 1, 4 enemy
	for (uint8_t i = 0; i < 4; i++) {
		if (i == 0) {
			enemies[i]->setStartPos(120 - enemy00.getWidth() / 2, -enemy00.getHeight());
			enemies[i]->setEndPos(ENEMY_GAP, ENEMY_LINE1);
		}
		else {
			enemies[i]->setStartPos(enemies[i - 1]->getStartX(), (i >= 2) ?  enemies[3 - i]->getStartY() : enemies[i - 1]->getStartY() - 50 );
			enemies[i]->setEndPos(enemies[i - 1]->getEndX() +  enemy00.getWidth() + ENEMY_GAP , ENEMY_LINE1);
		}

		enemies[i]->setState(Enemy::ENTER);
	}
}

void mainView::setUpPhase2() {
	uint8_t i;
	uint16_t eHeight = enemy00.getHeight();
	uint16_t eWidth = enemy00.getWidth();

	//line1, 4 enemy
	for (i = 3; i < 7; i++) {
		if (i == 3) {
			enemies[i]->setStartPos(120 - eWidth, -eHeight * (i + 1));
			enemies[i]->setEndPos(ENEMY_GAP, ENEMY_LINE1);
		}
		else {
			enemies[i]->setStartPos(enemies[i - 1]->getStartX(), -eHeight * i);
			enemies[i]->setEndPos(enemies[i - 1]->getEndX() +  eWidth + ENEMY_GAP, ENEMY_LINE1);
		}
	}

	//line2, 3 enemy
	for (i = 0; i < 3; ++i) {
		enemies[i]->setStartPos(240 - eWidth, -eHeight * (i + 1));
		enemies[i]->setEndPos(enemies[i + 3]->getEndX() + eWidth + 5, ENEMY_LINE2);
	}

	//line0, 3 enemy
	for (i = 7; i < 10; ++i) {
		enemies[i]->setStartPos(0, -eHeight * (i + 1));
		enemies[i]->setEndPos(enemies[i - 7]->getEndX(), ENEMY_LINE0);
	}

	for (i =  0; i < 10; ++i) {
		enemies[i]->setState(Enemy::ENTER);
	}
}

void mainView::setUpPhase3() {
	//set boss
	boss.setStartPos(120 - boss.getWidth() / 2, -boss.getHeight());
	boss.setEndPos(boss.getStartX(), 10);
	boss.setState(Enemy::ENTER);
}

//determine which bullet is fired
static uint8_t bulletIndex = 0;
void  mainView::shipFireBullet() {
	shipBullets[bulletIndex]->setVisible(1);
	//move bullets to top center of the ship
	shipBullets[bulletIndex]->setXY(ship.getX() + ship.getWidth()/2 - shipBullet0.getWidth()/2, ship.getY());
	//bullet go straight 320 pixel
	shipBullets[bulletIndex]->startMoveAnimation(shipBullets[bulletIndex]->getX(),
			-(320 - shipBullets[bulletIndex]->getY()), SHIP_BULLET_DURATION);

	if (++bulletIndex == NBR_SHIP_BULLET)
		bulletIndex = 0;
}

void mainView::cancelShipBullet() {
	for (uint8_t i = 0; i < NBR_SHIP_BULLET; ++i) {
		shipBullets[i]->setY(320);
		shipBullets[i]->cancelMoveAnimation();
	}

	invalidate();
 }

void mainView::bossFireBullet0() {
	bossBullet00.setVisible(1);
	bossBullet01.setVisible(1);

	//move bullet to the right hand of boss
	bossBullet00.moveTo(boss.getX() + 15, boss.getY() + 93);
	//bullet go straight down 320 pixel
	bossBullet00.startMoveAnimation(bossBullet00.getX(), bossBullet00.getY() + 320, BOSS_BULLET0_DURATION);

	//move bullet to the left hand of boss
	bossBullet01.moveTo(boss.getX() + 82, boss.getY() + 93);
	//bullet go straight down 320 pixel
	bossBullet01.startMoveAnimation(bossBullet01.getX(), bossBullet01.getY() + 320, BOSS_BULLET0_DURATION);
}

void mainView::bossFireBullet1() {
	uint16_t bossCenterY = boss.getY() + boss.getHeight() / 2;
	uint16_t bossCenterX = boss.getX() + boss.getWidth() / 2;

	bossBullet10.setVisible(1);
	bossBullet11.setVisible(1);
	bossBullet12.setVisible(1);
	bossBullet13.setVisible(1);

	bossBullet10.moveTo(bossCenterX, bossCenterY);
	bossBullet11.moveTo(bossCenterX, bossCenterY);
	bossBullet12.moveTo(bossCenterX, bossCenterY);
	bossBullet13.moveTo(bossCenterX, bossCenterY);

	//bullets go in different direction
	bossBullet10.startMoveAnimation(-168, 420, BOSS_BULLET1_DURATION);
	bossBullet11.startMoveAnimation(21, 420, BOSS_BULLET1_DURATION);
	bossBullet12.startMoveAnimation(196, 420, BOSS_BULLET1_DURATION);
	bossBullet13.startMoveAnimation(398, 420, BOSS_BULLET1_DURATION);
}

void mainView::enmy10FireBullet() {
	//move bullet to bottom center of enemy10
	enemy10Bullet.moveTo(enemy10.getX() + enemy10.getWidth() / 2, enemy10.getY() + enemy10.getHeight());
	//bullet go straight down 200 pixel
	enemy10Bullet.startMoveAnimation(enemy10Bullet.getX(), enemy10Bullet.getY() + 200, ENEMY1_BULLET_DURATION);
}

void mainView::enmy11FireBullet() {
	//move bullet to bottom center of enemy11
	enemy11Bullet.moveTo(enemy11.getX() + enemy11.getWidth() / 2, enemy11.getY() + enemy11.getHeight());
	//bullet go straight down 200 pixel
	enemy11Bullet.startMoveAnimation(enemy11Bullet.getX(), enemy11Bullet.getY() + 200, ENEMY1_BULLET_DURATION);
}

void mainView::setState(State state) {
	this->state = state;
	tickCount = 0;
}
