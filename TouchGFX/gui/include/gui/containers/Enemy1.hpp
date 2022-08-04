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
    void setDirection(int8_t d);
protected:
    virtual void reset();
    virtual void startDamagedAnimation();

    int8_t direction;
};

#endif // ENEMY1_HPP
