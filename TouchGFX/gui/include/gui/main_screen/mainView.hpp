#ifndef MAINVIEW_HPP
#define MAINVIEW_HPP

#include <gui_generated/main_screen/mainViewBase.hpp>
#include <gui/main_screen/mainPresenter.hpp>
#include <touchgfx/mixins/MoveAnimator.hpp>
#include <touchgfx/hal/Types.hpp>

class mainView : public mainViewBase
{
public:
	mainView();
    virtual ~mainView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();
    void bulletMoveAnimationEndedHandler(const touchgfx::MoveAnimator<touchgfx::Image>& bullet);
protected:
    int16_t localImgX;
    int16_t localImgY;
    uint32_t tickCount;
    touchgfx::MoveAnimator< touchgfx::Image >* bulletList[3];
    Callback <mainView, const touchgfx::MoveAnimator<touchgfx::Image>&> bulletMoveAnimationEndedCallback;
};

#endif // MAINVIEW_HPP
