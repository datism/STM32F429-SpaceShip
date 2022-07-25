#ifndef ENEMY0_HPP
#define ENEMY0_HPP

#include <gui_generated/containers/Enemy0Base.hpp>
#include <touchgfx/mixins/MoveAnimator.hpp>

class Enemy0 : public MoveAnimator<Enemy0Base>
{
public:
	enum State {
		ALIVE,
		DEAD
	};

    Enemy0();
    virtual ~Enemy0() {}
    virtual void initialize();
    virtual void handleTickEvent();

    void setState(State state);
    State getState();
    void setStartPos(int16_t x, int16_t y);
    void setEnterPos(int16_t x, int16_t y);
    int16_t getStartX();
    int16_t getStartY();
    int16_t getEnterX();
    int16_t getEnterY();
protected:
    State state;
    int16_t startPosX;
    int16_t startPosY;
    int16_t enterPosX;
    int16_t enterPosY;
    uint32_t tickCounter;

    void reset();
};

#endif // ENEMY0_HPP
