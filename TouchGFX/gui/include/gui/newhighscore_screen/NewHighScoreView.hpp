#ifndef NEWHIGHSCOREVIEW_HPP
#define NEWHIGHSCOREVIEW_HPP

#include <gui_generated/newhighscore_screen/NewHighScoreViewBase.hpp>
#include <gui/newhighscore_screen/NewHighScorePresenter.hpp>
#include <gui/common/CustomKeyboard.hpp>

class NewHighScoreView : public NewHighScoreViewBase
{
public:
    NewHighScoreView();
    virtual ~NewHighScoreView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void enterPressedHandle();

protected:
    CustomKeyboard keyboard;
};

#endif // NEWHIGHSCOREVIEW_HPP
