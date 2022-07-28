#ifndef MAINVIEW_HPP
#define MAINVIEW_HPP

#include <gui_generated/main_screen/mainViewBase.hpp>
#include <gui/main_screen/mainPresenter.hpp>
#include <gui/containers/Enemy.hpp>

/* Number of bullet */
#define NBR_BULLET 4

#define NBR_ENEMY_BULLET 8

/* Number of enemy 0 */
#define NBR_ENEMY 13

class mainView : public mainViewBase
{
public:

	enum State{
		PHASE1,
		PHASE2,
		PHASE3,
	};

	mainView();
    virtual ~mainView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();

protected:
    uint32_t tickCount;
    uint8_t enemyCount;
    State state;
    Enemy* enemies[NBR_ENEMY];
    touchgfx::MoveAnimator< touchgfx::Image >* shipBullets[NBR_BULLET];
    touchgfx::MoveAnimator< touchgfx::Image >* enemyBullets[NBR_ENEMY_BULLET];

    virtual void shipFireBullet();
    virtual void bossFireBullet0();
    virtual void bossFireBullet1();
    virtual void enmy10FireBullet();
    virtual void enmy11FireBullet();

    void setUpPhase1();
    void setUpPhase2();
    void setUpPhase3();
    void checkCollision();
    void cancelShipBullet();
    void setState(State state);
};

#endif // MAINVIEW_HPP
