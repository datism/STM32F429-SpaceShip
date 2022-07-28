#include <gui/containers/Enemy1.hpp>
#include <BitmapDatabase.hpp>

#define MOVE_DURATION  40

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
			//move to standing position
			startMoveAnimation(endX, endY, MOVE_DURATION);
		}
		else if (tickCounter % MOVE_DURATION == 0) {
			endX = endX + 60 * direction ;
			endY = endY + 30 * ((tickCounter % (MOVE_DURATION * 2) == 0) ? 1 : -1);
			startMoveAnimation(endX, endY, MOVE_DURATION);
		} else if (tickCounter > MOVE_DURATION * 4)
			reset();

		if (tickCounter % 50 == 0)
			emitFireBulletTriggerCallback();
		break;
	case DEAD:
		if (tickCounter == 1) {
			cancelMoveAnimation();
			animatedImage.setBitmaps(BITMAP_EXPLOSION0_ID, BITMAP_EXPLOSION7_ID);
			animatedImage.setUpdateTicksInterval(5);
			animatedImage.startAnimation(false, true, false);
		}
		else if (tickCounter > 40)
			reset();
		break;
	default: break;
	}
}

void Enemy1::setDirection(int8_t direction) {
	this->direction = direction;
}

const Rect& Enemy1::getHitBox() {
	return getRect();
}

void Enemy1::reset() {
	state = OOB;
	animatedImage.setBitmaps(BITMAP_ENEMY1_ID, BITMAP_ENEMY1_ID);
	moveTo(startX, startY);
}
