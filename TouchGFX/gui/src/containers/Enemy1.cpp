#include <gui/containers/Enemy1.hpp>
#include <gui/Constraint.hpp>
#include <BitmapDatabase.hpp>

Enemy1::Enemy1()
	:Enemy(OOB) {
	Application::getInstance()->registerTimerWidget(this);
}

void Enemy1::initialize()
{
    Enemy1Base::initialize();
}

void Enemy1::handleTickEvent() {
	tickCounter++;
	MoveAnimator<Enemy1Base>::handleTickEvent();

	switch(state) {
	case ENTER:
		if (tickCounter == 1) {
			//move to outside screen
			moveTo(startX, startY);

			endX = startX + movX;
			endY = startY + movY;
			startMoveAnimation(endX, endY, movDuration);
		}
		else if (tickCounter % movDuration == 0) {
			//sin movement
			endX = endX + movX;
			endY = endY + movY * ((tickCounter % (movDuration * 2) == 0) ? 1 : -1);
			startMoveAnimation(endX, endY, movDuration);
		} else if (tickCounter == movDuration  * nbrMov)
			reset();

		if (tickCounter % ENEMY1_BULLET_INTERVAL == 0)
			//Fire bullet every ENEMY1_BULLET_INTERVAL ticks
			emitFireBulletTriggerCallback();
		break;
	case DEAD:
		if (tickCounter == 1) {
			//Start explode animation
			cancelMoveAnimation();
			animatedImage.setBitmaps(BITMAP_EXPLOSION0_ID, BITMAP_EXPLOSION7_ID);
			animatedImage.setUpdateTicksInterval(5);
			animatedImage.startAnimation(false, true, false);
		}
		else if (tickCounter == EXPLODE_DURATION)
			reset();
		break;
	default: break;
	}
}

void Enemy1::setZigzagMovement(uint16_t period, int8_t nbrPeriod, int8_t direction) {
	nbrMov = nbrPeriod * 2;

	movDuration = period / 2;

	movX = direction * (240 + 30) / nbrMov;
	movY = movX / direction;
}

const Rect& Enemy1::getHitBox() {
	return getRect();
}

void Enemy1::reset() {
	state = OOB;
	animatedImage.setBitmaps(BITMAP_ENEMY1_ID, BITMAP_ENEMY1_ID);
	moveTo(startX, startY);
}
