#ifndef LEADERSCOREPRESENTER_HPP
#define LEADERSCOREPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class LeaderscoreView;

class LeaderscorePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    LeaderscorePresenter(LeaderscoreView& v);

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

    void getHighScore(touchgfx::Unicode::UnicodeChar names[5][6], uint32_t points[5]);
    virtual ~LeaderscorePresenter() {};

private:
    LeaderscorePresenter();

    LeaderscoreView& view;
};

#endif // LEADERSCOREPRESENTER_HPP
