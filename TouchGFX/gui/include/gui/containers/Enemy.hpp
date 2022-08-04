#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <stdint.h>
#include <touchgfx/hal/Types.hpp>

class Enemy {
public:
	enum State {
		OOB,
		ENTER,
		RETREAT,
		ATTACK,
		DEAD
	};

    ~Enemy() {}

    void setState(State);
    State getState();

    void handleDamage(uint16_t damage);

    void setStartPos(int16_t, int16_t);
    void setEndPos(int16_t, int16_t);
    int16_t getStartX();
    int16_t getStartY();
    int16_t getEndX();
    int16_t getEndY();

    virtual const touchgfx::Rect& getHitBox() = 0;

protected:
    State state;
    int8_t damaged;
    int16_t health;

    uint32_t damagedTick;
    uint32_t tickCounter;

    int16_t startX;
    int16_t startY;
    int16_t endX;
    int16_t endY;

    virtual void startDamagedAnimation() = 0;
    virtual void reset();

    Enemy(int16_t h);
};

#endif // ENEMY_HPP
