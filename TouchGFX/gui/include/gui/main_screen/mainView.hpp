#ifndef MAINVIEW_HPP
#define MAINVIEW_HPP

#include <gui_generated/main_screen/mainViewBase.hpp>
#include <gui/main_screen/mainPresenter.hpp>
#include <touchgfx/mixins/MoveAnimator.hpp>

/* Speed of the ship (pixels/tick)*/
#define SHIP_SPEED 1
/* Speed of a bullet (pixels/tick)*/
#define BULLET_SPEED 4
/* Ticks which a bullet take in move aniamtion */
#define BULLET_TIME 320 / BULLET_SPEED
/* Number of bullet */
#define NBR_BULLET 4
/* Ticks which ship take to fire a bullet */
#define INTERVAL_BULLET (int)(BULLET_TIME / NBR_BULLET)

class mainView : public mainViewBase
{
public:
	mainView();
    virtual ~mainView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();
protected:
    int16_t localImgX;
    int16_t localImgY;
    uint32_t tickCount;
    touchgfx::MoveAnimator< touchgfx::Image >* bulletList[NBR_BULLET];
};

#endif // MAINVIEW_HPP
