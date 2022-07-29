#include <gui/containers/Enemy0.hpp>
#include <gui/Constraint.hpp>
#include <BitmapDatabase.hpp>


Enemy0::Enemy0()
	:Enemy(OOB) {
	Application::getInstance()->registerTimerWidget(this);
}

void Enemy0::initialize()
{
    Enemy0Base::initialize();
}

void Enemy0::handleTickEvent() {
	tickCounter++;
	MoveAnimator<Enemy0Base>::handleTickEvent();

	switch(state) {
	case ENTER:
		if (tickCounter == 1) {
			//move to outside screen
			moveTo(startX, startY);
			//move to standing position
			startMoveAnimation(endX, endY, ENEMY0_MOVE_DURATION, EasingEquations::cubicEaseOut, EasingEquations::expoEaseOut);
		}
		break;
	case RETREAT:
		if (tickCounter == 1)
			//go straight up
			startMoveAnimation(getX(), -getHeight(), ENEMY0_MOVE_DURATION);
		if (tickCounter == ENEMY0_MOVE_DURATION)
			reset();
		break;
	case ATTACK:
		if (tickCounter == 1) {
			//Go straight down
			startMoveAnimation(getX(), getY() + 320, ENEMY0_MOVE_DURATION);
		}
		else if (tickCounter == ENEMY0_MOVE_DURATION)
			reset();
		break;
	case DEAD:
		if (tickCounter == 1) {
			//Start explode animation
			animatedImage.setBitmaps(BITMAP_EXPLOSION0_ID, BITMAP_EXPLOSION7_ID);
			animatedImage.setUpdateTicksInterval(5);
			animatedImage.startAnimation(false, true, false);
			cancelMoveAnimation();
		}
		else if (tickCounter == EXPLODE_DURATION)
			reset();
		break;
	default: break;
	}
}

const Rect& Enemy0::getHitBox() {
	return getRect();
}

void Enemy0::reset() {
	state = OOB;
	animatedImage.setBitmaps(BITMAP_ENEMY0_ID, BITMAP_ENEMY0_ID);
	moveTo(startX, startY);
}
