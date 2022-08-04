#ifndef ENEMY0_HPP
#define ENEMY0_HPP

#include <gui_generated/containers/Enemy0Base.hpp>
#include <gui/containers/Enemy.hpp>
#include <touchgfx/mixins/MoveAnimator.hpp>

class Enemy0 : public MoveAnimator<Enemy0Base>, public Enemy
{
public:
    Enemy0();
    virtual ~Enemy0() {}
    virtual void initialize();
    virtual void handleTickEvent();

    virtual const Rect& getHitBox();

protected:
    virtual void reset();
    virtual void startDamagedAnimation();
};

#endif // ENEMY0_HPP
