#include <gui/containers/Boss.hpp>
#include <gui/Constraint.hpp>
#include <BitmapDatabase.hpp>

Boss::Boss()
	:Enemy(BOSS_HEALTH) {
	Application::getInstance()->registerTimerWidget(this);
}

void Boss::initialize()
{
    BossBase::initialize();
}

void Boss::handleTickEvent() {
	tickCounter++;
	MoveAnimator<BossBase>::handleTickEvent();

	if (damaged) {
		startDamagedAnimation();
	}

	switch(state) {
	case ENTER:
		if (tickCounter == 1) {
			//move to outside screen
			moveTo(startX, startY);
			//move to standing position
			startMoveAnimation(endX, endY, BOSS_MOVE_DURATION / 2);
		}
		else if (tickCounter == BOSS_MOVE_DURATION / 2) {
			startMoveAnimation(0, getY(), BOSS_MOVE_DURATION / 2);
		}
		else if (tickCounter % BOSS_MOVE_DURATION == 0) {
			startMoveAnimation((tickCounter % (BOSS_MOVE_DURATION * 2) == BOSS_MOVE_DURATION) ? 125 : 0, getY(), BOSS_MOVE_DURATION);
		}


		if (tickCounter > BOSS_MOVE_DURATION && tickCounter % BOSS_BULLET1_INTERVAL == 0)
			//Fire bullet1 every BOSS_BULLET1_INTERVAL ticks
			emitFireBullet1TriggerCallback();

		if (tickCounter > BOSS_MOVE_DURATION && tickCounter % BOSS_BULLET0_INTERVAL == 0) {
			//Fire bullet1 every BOSS_BULLET0_INTERVAL ticks
			emitFireBullet0TriggerCallback();
		}

		break;
	case DEAD:
		if (tickCounter == 1) {
			damaged = 0;
			animatedImage.setAlpha(255);
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

const Rect& Boss::getHitBox() {
	return getRect();
}

void Boss::reset() {
	Enemy::reset();
	health = BOSS_HEALTH;

	animatedImage.setAlpha(255);
	animatedImage.setBitmaps(BITMAP_ENEMY0_ID, BITMAP_ENEMY0_ID);
	moveTo(startX, startY);
}

void Boss::startDamagedAnimation() {
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

