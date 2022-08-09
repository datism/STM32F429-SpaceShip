#ifndef MAINVIEW_HPP
#define MAINVIEW_HPP

#include <gui_generated/main_screen/mainViewBase.hpp>
#include <gui/main_screen/mainPresenter.hpp>
#include <gui/containers/Enemy.hpp>
#include <gui/Constraint.hpp>

class mainView : public mainViewBase
{
public:

	enum State{
		PHASE1,
		PHASE2,
		PHASE3,
		ENDGAME,
	};

	mainView();
    virtual ~mainView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();

protected:
    uint32_t tickCount;
    //Count of alive, in screen enemies
    uint8_t enemyCount;
    //State of the game
    State state;
    //Array of enemies
    Enemy* enemies[NBR_ENEMY];
    //Array of ship's bullets
    touchgfx::MoveAnimator< touchgfx::Image >* shipBullets[NBR_SHIP_BULLET];
    //Array of enemy's bullets
    touchgfx::MoveAnimator< touchgfx::Image >* enemyBullets[NBR_ENEMY_BULLET];

    //Call by emitFireBulletTriggerCallback() by ship
    virtual void shipFireBullet();
    //Call by emitFireBullet0TriggerCallback() by boss
    virtual void bossFireBullet0();
    //Call bt emitFireBullet1TriggerCallback() by boss
    virtual void bossFireBullet1();
    //Call by emitFireBulletTriggerCallback() by enemy10
    virtual void enmy10FireBullet();
    //Call by emitFireBulletTriggerCallback() by enemy11
    virtual void enmy11FireBullet();

    //Check objects's collisions
    void checkCollision();
    //Remove ship's bullets from screens
    void cancelShipBullet();

    void handleShipDead();

    void setUpPhase1();
    void setUpPhase2();
    void setUpPhase3();
    void setState(State state);
};

#endif // MAINVIEW_HPP
