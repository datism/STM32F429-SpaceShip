#ifndef MAINVIEW_HPP
#define MAINVIEW_HPP

#include <gui_generated/main_screen/mainViewBase.hpp>
#include <gui/main_screen/mainPresenter.hpp>
#include <touchgfx/hal/Types.hpp>

/* Number of bullet */
#define NBR_BULLET 4

/* Number of enemy 0 */
#define NBR_ENEMY0 10

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

    void bulletMoveAnimationEndedHandler(const touchgfx::MoveAnimator<touchgfx::Image>& comp);
protected:
    uint32_t tickCount;
    State state;
    touchgfx::Vector<Enemy0*, NBR_ENEMY0> enemies;
    touchgfx::MoveAnimator< touchgfx::Image >* bullets[NBR_BULLET];

    void checkCollision();
    void setUpPhase1();
    void setUpPhase2();
    void resetBullets();
    void setState(State state);
    Callback <mainView, const touchgfx::MoveAnimator<touchgfx::Image>& > bulletMoveAnimationEndedCallback;
};

#endif // MAINVIEW_HPP
