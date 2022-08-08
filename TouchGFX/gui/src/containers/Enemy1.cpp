#include <gui/containers/Enemy1.hpp>
#include <math.h>
#include <gui/Constraint.hpp>
#include <BitmapDatabase.hpp>

Enemy1::Enemy1()
	:Enemy(ENEMY1_HEALTH, ENEMY1_POINT) {
	Application::getInstance()->registerTimerWidget(this);
}

void Enemy1::initialize()
{
    Enemy1Base::initialize();
}

void Enemy1::handleTickEvent() {
	tickCounter++;

	if (damaged) {
		startDamagedAnimation();
	}


	switch(state) {
	case ENTER:
		if (tickCounter == 1) {
			reset();
			//move to outside screen
			endX = startX;
			moveTo(startX, startY);
		}
		else if (tickCounter == 270)
			reset();
		else {
			endY = startY + direction * 30 * sin(6.28/135 * tickCounter);
			endX = endX + direction * 2;
			moveTo(endX, endY);
		}

		if (tickCounter % ENEMY1_BULLET_INTERVAL == 0)
			//Fire bullet every ENEMY1_BULLET_INTERVAL ticks
			emitFireBulletTriggerCallback();
		break;
	case DEAD:
		if (tickCounter == 1) {
			damaged = 0;
			animatedImage.setAlpha(255);
			//Start explode animation
			cancelMoveAnimation();
			animatedImage.setBitmaps(BITMAP_EXPLOSION00_ID, BITMAP_EXPLOSION07_ID);
			animatedImage.setUpdateTicksInterval(5);
			animatedImage.startAnimation(false, true, false);
		}
		else if (tickCounter == EXPLODE_DURATION) {
			reset();
			setState(OOB);
			moveTo(startX, startY);
		}
		break;
	default: break;
	}
}

void  Enemy1::setDirection(int8_t d) {
	direction = d;
}

void  Enemy1::startDamagedAnimation() {
	if (damagedTick == 0) {
		damagedTick = tickCounter;
	}

	if (tickCounter > damagedTick + DAMAGED_DURATION) {
		damaged = 0;
		damagedTick = 0;
		animatedImage.setAlpha(255);
	}
	else if ((tickCounter - damagedTick) % DAMAGED_TICK_INTERVAL == 0){
		animatedImage.setAlpha((tickCounter - damagedTick) % (DAMAGED_TICK_INTERVAL * 2) == 0 ? 255 : 0);
	}
}

const Rect& Enemy1::getHitBox() {
	return getRect();
}

void Enemy1::reset() {
	Enemy::reset();
	health = ENEMY1_HEALTH;

	animatedImage.setAlpha(255);
	animatedImage.setBitmaps(BITMAP_ENEMY1_ID, BITMAP_ENEMY1_ID);
}
