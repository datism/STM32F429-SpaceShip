#ifndef NEWHIGHSCOREVIEWVIEW_HPP
#define NEWHIGHSCOREVIEWVIEW_HPP

#include <gui_generated/newhighscoreview_screen/NewHighScoreViewViewBase.hpp>
#include <gui/newhighscoreview_screen/NewHighScoreViewPresenter.hpp>
#include <gui/common/CustomKeyboard.hpp>

class NewHighScoreViewView : public NewHighScoreViewViewBase
{
public:
    NewHighScoreViewView();
    virtual ~NewHighScoreViewView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
    CustomKeyboard keyboard;
};

#endif // NEWHIGHSCOREVIEWVIEW_HPP
