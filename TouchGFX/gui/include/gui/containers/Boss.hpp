#ifndef BOSS_HPP
#define BOSS_HPP

#include <gui_generated/containers/BossBase.hpp>
#include <gui/containers/Enemy.hpp>
#include <touchgfx/mixins/MoveAnimator.hpp>

class Boss : public MoveAnimator<BossBase>, public Enemy
{
public:
    Boss();
    virtual ~Boss() {}
    virtual void initialize();

    virtual void handleTickEvent();
    virtual const Rect& getHitBox();

protected:
    virtual void reset();
    virtual void startDamagedAnimation();
};

#endif // BOSS_HPP
