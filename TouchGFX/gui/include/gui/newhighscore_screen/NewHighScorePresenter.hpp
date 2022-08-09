#ifndef NEWHIGHSCOREPRESENTER_HPP
#define NEWHIGHSCOREPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class NewHighScoreView;

class NewHighScorePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    NewHighScorePresenter(NewHighScoreView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~NewHighScorePresenter() {};

    void updateName(touchgfx::Unicode::UnicodeChar n[6]);
    void saveHighScore();
private:
    NewHighScorePresenter();

    NewHighScoreView& view;
};

#endif // NEWHIGHSCOREPRESENTER_HPP
