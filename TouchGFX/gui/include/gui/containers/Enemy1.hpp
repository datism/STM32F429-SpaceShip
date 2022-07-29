#ifndef ENEMY1_HPP
#define ENEMY1_HPP

#include <gui_generated/containers/Enemy1Base.hpp>
#include <gui/containers/Enemy.hpp>
#include <touchgfx/mixins/MoveAnimator.hpp>

class Enemy1 : public MoveAnimator<Enemy1Base>,  public Enemy
{
public:
    Enemy1();
    virtual ~Enemy1() {}
    virtual void initialize();
    virtual void handleTickEvent();

    virtual const Rect& getHitBox();
    void setZigzagMovement(uint16_t period, int8_t nbrPeriod, int8_t direction);
protected:
    virtual void reset();

    int16_t movX;
    int16_t movY;
    uint16_t movDuration;
    uint8_t nbrMov;
};

#endif // ENEMY1_HPP
