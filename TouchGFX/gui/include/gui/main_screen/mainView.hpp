#ifndef MAINVIEW_HPP
#define MAINVIEW_HPP

#include <gui_generated/main_screen/mainViewBase.hpp>
#include <gui/main_screen/mainPresenter.hpp>

/* Number of bullet */
#define NBR_BULLET 4

/* Number of enemy 0 */
#define NBR_ENEMY0 10

class mainView : public mainViewBase
{
public:
	mainView();
    virtual ~mainView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();
    void checkCollision();

    void bulletMoveAnimationEndedHandler(const touchgfx::MoveAnimator<touchgfx::Image>& comp);
protected:
    uint32_t tickCount;
    touchgfx::MoveAnimator< touchgfx::Image >* bullets[NBR_BULLET];
    Enemy0* enemies0[NBR_ENEMY0];

    Callback <mainView, const touchgfx::MoveAnimator<touchgfx::Image>& > bulletMoveAnimationEndedCallback;
};

#endif // MAINVIEW_HPP
